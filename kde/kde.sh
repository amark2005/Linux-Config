#!/bin/bash

BACKUP_DIR="$HOME/.kde-snapshots/latest"

export_kde() {
    echo "⚡ Exporting KDE configuration..."

    rm -rf "$BACKUP_DIR"
    mkdir -p "$BACKUP_DIR/config"

    cp ~/.config/kdeglobals "$BACKUP_DIR/config/" 2>/dev/null
    cp ~/.config/kwinrc "$BACKUP_DIR/config/" 2>/dev/null
    cp ~/.config/plasma-org.kde.plasma.desktop-appletsrc "$BACKUP_DIR/config/" 2>/dev/null
    cp ~/.config/kglobalshortcutsrc "$BACKUP_DIR/config/" 2>/dev/null
    cp ~/.config/ksmserverrc "$BACKUP_DIR/config/" 2>/dev/null

    mkdir -p "$BACKUP_DIR/share"

    cp -r ~/.local/share/plasma "$BACKUP_DIR/share/" 2>/dev/null
    cp -r ~/.local/share/icons "$BACKUP_DIR/share/" 2>/dev/null
    cp -r ~/.local/share/color-schemes "$BACKUP_DIR/share/" 2>/dev/null

    pacman -Qqe > "$BACKUP_DIR/pkglist.txt"
    pacman -Qqm > "$BACKUP_DIR/aurlist.txt"

    echo "✅ KDE snapshot saved to $BACKUP_DIR"
}

import_kde() {
    echo "⚡ Importing KDE configuration..."

    if [ ! -d "$BACKUP_DIR" ]; then
        echo "❌ No snapshot found"
        exit 1
    fi

    cp "$BACKUP_DIR/config/"* ~/.config/ 2>/dev/null
    cp -r "$BACKUP_DIR/share/"* ~/.local/share/ 2>/dev/null

    echo "🔄 Restarting Plasma..."

    kquitapp6 plasmashell
    plasmashell &

    echo "✅ KDE configuration restored"
}

case "$1" in
    export)
        export_kde
        ;;
    import)
        import_kde
        ;;
    *)
        echo "Usage: kde {export|import}"
        ;;
esac