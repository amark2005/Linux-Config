#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>

namespace fs = std::filesystem;

// Terminal manipulation for the TUI
void setRawMode(termios& orig_termios) {
    tcgetattr(STDIN_FILENO, &orig_termios);
    termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void restoreMode(const termios& orig_termios) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

int renderMenu(const std::string& title, const std::vector<std::string>& options) {
    int selected = 0;
    termios orig_termios;
    setRawMode(orig_termios);

    // Hide cursor
    std::cout << "\033[?25l";

    while (true) {
        std::cout << "\033[2J\033[H"; // Clear screen and move to top
        std::cout << "\033[1;36m=== " << title << " ===\033[0m\n\n";

        for (int i = 0; i < options.size(); ++i) {
            if (i == selected) {
                std::cout << "\033[1;32m > " << options[i] << " \033[0m\n";
            } else {
                std::cout << "   " << options[i] << "\n";
            }
        }
        std::cout << "\n\033[90m(Use Arrow Keys to navigate, Enter to select, 'q' to quit)\033[0m\n";

        char c;
        read(STDIN_FILENO, &c, 1);

        if (c == 'q') {
            selected = -1;
            break;
        } else if (c == '\n') {
            break;
        } else if (c == '\033') {
            char seq[3];
            if (read(STDIN_FILENO, &seq[0], 1) == 0) continue;
            if (read(STDIN_FILENO, &seq[1], 1) == 0) continue;

            if (seq[0] == '[') {
                if (seq[1] == 'A' && selected > 0) selected--;          // Up
                else if (seq[1] == 'B' && selected < options.size() - 1) selected++; // Down
            }
        }
    }

    // Show cursor and restore terminal
    std::cout << "\033[?25h\033[2J\033[H";
    restoreMode(orig_termios);
    return selected;
}

int main() {
    std::vector<std::string> profiles = {
        "1. DaVinci Resolve DNxHR HQX (Intel VAAPI Decode)",
        "2. Quick Rewrap (MP4 -> MOV, No re-encode)",
        "3. H.265 / HEVC Web Render (Intel VAAPI Encode)",
        "4. Extract Audio to uncompressed WAV"
    };

    int choice = renderMenu("Shutter CLI - Arch Linux Edition", profiles);
    if (choice == -1) {
        std::cout << "Aborted.\n";
        return 0;
    }

    std::string out_dir = "converted_media";
    if (!fs::exists(out_dir)) fs::create_directory(out_dir);

    bool files_found = false;
    for (const auto& entry : fs::directory_iterator(".")) {
        if (!entry.is_regular_file()) continue;
        
        std::string path = entry.path().string();
        std::string ext = entry.path().extension().string();
        std::string filename = entry.path().stem().string();

        if (ext == ".mp4" || ext == ".mkv" || ext == ".webm") {
            files_found = true;
            std::string cmd;
            std::string out_file = out_dir + "/" + filename;

            switch (choice) {
                case 0: // DNxHR
                    cmd = "ffmpeg -hwaccel vaapi -i \"" + path + "\" -c:v dnxhd -profile:v dnxhr_hqx -pix_fmt yuv422p10le -c:a pcm_s16le \"" + out_file + ".mov\"";
                    break;
                case 1: // Rewrap
                    cmd = "ffmpeg -i \"" + path + "\" -c copy \"" + out_file + ".mov\"";
                    break;
                case 2: // HEVC VAAPI Encode
                    cmd = "ffmpeg -vaapi_device /dev/dri/renderD128 -i \"" + path + "\" -vf 'format=nv12,hwupload' -c:v hevc_vaapi -c:a aac -b:a 192k \"" + out_file + "_h265.mp4\"";
                    break;
                case 3: // WAV Audio
                    cmd = "ffmpeg -i \"" + path + "\" -vn -c:a pcm_s16le \"" + out_file + ".wav\"";
                    break;
            }

            std::cout << "\033[1;34mProcessing: \033[0m" << filename << ext << "\n";
            std::cout << "\033[90mCommand: " << cmd << "\033[0m\n\n";
            
            int result = system(cmd.c_str());
            if (result != 0) {
                std::cerr << "\033[1;31mError processing " << filename << ext << "\033[0m\n";
            }
        }
    }

    if (!files_found) {
        std::cout << "\033[1;33mNo supported video files (.mp4, .mkv, .webm) found in current directory.\033[0m\n";
    } else {
        std::cout << "\n\033[1;32mBatch processing complete. Files saved to ./" << out_dir << "/\033[0m\n";
    }

    return 0;
}