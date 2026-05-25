#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_PATH_LEN 4096

void execute_rsync(const char *source_dir, const char *target_dir) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        char *args[] = {
            "rsync", 
            "-avh", 
            "--progress", 
            (char *)source_dir, 
            (char *)target_dir, 
            NULL
        };

        execvp(args[0], args);
        perror("Execvp failed");
        exit(EXIT_FAILURE);
    } 
    else {
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Warning: Rsync exited with error code %d for %s\n", WEXITSTATUS(status), source_dir);
        }
    }
}

int main() {
    const char *base_source_dir = "/home/amar/.config";
    const char *target_dir = "/home/amar/Linux-Config/backup"; 
    
    FILE *file = fopen("backup.txt", "r");
    if (!file) {
        perror("Error opening backup.txt");
        return EXIT_FAILURE;
    }

    char line[MAX_PATH_LEN];
    char full_source_path[MAX_PATH_LEN];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }

        // Construct absolute path: /home/amar/.config/folder_name
        snprintf(full_source_path, sizeof(full_source_path), "%s/%s", base_source_dir, line);

        printf("\n[BACKUP] Starting sync for: %s\n", full_source_path);
        execute_rsync(full_source_path, target_dir);
    }

    fclose(file);
    printf("\n[SUCCESS] All backup tasks completed.\n");
    return EXIT_SUCCESS;
}
