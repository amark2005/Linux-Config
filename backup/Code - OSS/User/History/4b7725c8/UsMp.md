# batcheck-rust 

A lightweight battery monitoring CLI written in Rust.

Built for Linux systems using `/sys/class/power_supply`.

Fast. Minimal. No Electron. No nonsense.

---

## Features

- Show battery percentage
- Show battery health
- Tiny native binary
- Low memory usage
- Linux sysfs based
- Zero background daemon

---

## Installation

### Clone

```bash
git clone https://github.com/amark2005/batcheck-rust-.git
cd batcheck-rust-
````

---

## Build

### Debug Build

```bash
cargo build
```

Binary:

```bash
target/debug/batcheck
```

---

### Release Build

```bash
cargo build --release
```

Binary:

```bash
target/release/batcheck
```

---


Output:

```bash
target/x86_64-unknown-linux-musl/release/batcheck
```

---

## Usage

### Show Battery Percentage

```bash
batcheck --show
```

Example:

```text
Battery: 82%
```

---

### Show Battery Health

```bash
batcheck --health
```

Example:

```text
Battery Health: Good
```

---

## How It Works

`batcheck` reads Linux battery information directly from:

```text
/sys/class/power_supply/BAT0/
```

No external services.
No telemetry.
No GUI overhead.

---

## Requirements

* Linux
* Rust toolchain
* Battery exposed through sysfs

---

## Dependencies

* clap

---

## Future Plans

* battery cycle count
* charging status
* battery temperature
* notification support
* JSON output mode
* multi-battery support

---

## Why Rust?

Rust provides:

* memory safety
* native performance
* static binaries
* predictable behavior

Perfect for system utilities.

---

## License

MIT

````

---

# Minimal Documentation (`docs.md`)

```md
# batcheck Documentation

## Overview

`batcheck` is a command-line battery monitoring utility written in Rust for Linux systems.

It reads battery information from Linux sysfs.

---

# Commands

## `--show`

Displays current battery percentage.

Example:

```bash
batcheck --show
````

Output:

```text
Battery: 74%
```

---

## `--health`

Displays battery health information.

Example:

```bash
batcheck --health
```

Output:

```text
Battery Health: Good
```

---

# Internal Data Source

Battery information is read from:

```text
/sys/class/power_supply/BAT0/
```

Examples:

```text
capacity
health
status
cycle_count
```

---

# Build Instructions

## Standard Build

```bash
cargo build --release
```

---

## Static Build

```bash
cargo build --release --target x86_64-unknown-linux-musl
```

---

# Debugging

Run with GDB:

```bash
gdb target/debug/batcheck
```

Run with Miri:

```bash
cargo miri run
```

---

# Philosophy

`batcheck` focuses on:

* low overhead
* simplicity
* native performance
* direct system interaction

No unnecessary abstractions.

```

