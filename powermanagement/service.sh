#!/bin/bash

echo "Disabling unnecessary GNOME background services..."

# Evolution services
systemctl --user mask evolution-addressbook-factory.service
systemctl --user mask evolution-calendar-factory.service
systemctl --user mask evolution-source-registry.service
systemctl --user mask evolution-alarm-notify.service

# GNOME Online Accounts
systemctl --user mask org.gnome.OnlineAccounts.service

# GNOME file sharing
systemctl --user mask org.gnome.SettingsDaemon.Sharing.service

# Bluetooth file transfer
systemctl --user mask obex.service

# GNOME file indexer
systemctl --user mask localsearch-3.service

# Smartcard support
systemctl --user mask org.gnome.SettingsDaemon.Smartcard.service

# Accessibility services
systemctl --user mask at-spi-dbus-bus.service

echo "Optimization complete."
echo "Log out and log back in to apply changes."