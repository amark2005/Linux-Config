#!/bin/bash
# fix-touchpad.sh
# Disables 3-finger tap (middle-click) on touchpad by overriding libinput tap button map.

set -e

QUIRKS_DIR="/etc/libinput"
QUIRKS_FILE="$QUIRKS_DIR/local-overrides.quirks"

if [[ $EUID -ne 0 ]]; then
    echo "Run as root: sudo $0"
    exit 1
fi

mkdir -p "$QUIRKS_DIR"

cat > "$QUIRKS_FILE" << 'EOF'
[Touchpad Override]
MatchUdevType=touchpad
AttrTapButtonMap=lm
EOF

echo "Done. Log out and back in to apply."