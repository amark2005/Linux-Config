Installation
1. Install Fastfetch
sudo dnf install fastfetch
2. Clone this repository
git clone https://github.com/amark2005/fastfetch-fedora-.git
cd fastfetch-fedora-
3. Install the configuration

Manual install:

mkdir -p ~/.config/fastfetch
cp -r configs/* ~/.config/fastfetch/

Using a helper script (if available):

chmod +x scripts/install-config.sh
./scripts/install-config.sh
4. Test
fastfetch

Test a specific config:

fastfetch --config ~/.config/fastfetch/fedora.conf
Usage Examples

Default run:

fastfetch

Run with a specific config:

fastfetch --config ~/.config/fastfetch/fedora.conf

List available modules:

fastfetch --list-modules
Customization

You can customize Fastfetch by editing files in:

~/.config/fastfetch/

Common tweaks:

Change colors and layout

Enable or disable modules

Swap Fedora ASCII logos

Add custom system info modules

Replace or add assets under:

~/.config/fastfetch/assets/
