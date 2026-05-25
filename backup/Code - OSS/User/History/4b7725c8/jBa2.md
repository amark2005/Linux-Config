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

