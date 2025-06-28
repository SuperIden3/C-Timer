# C-Timer

A C program that simulates a timer, supporting three arguments:

- Hours
- Minutes
- Seconds

This code would also check if output (just `stdout`) is a TTY or not, enabling cleaner viewing of the printed time between terminal and plain-text output.

## Usage

```sh
$ ./timer # For ten second countdown

$ ./timer seconds
$ ./timer minutes seconds
$ ./timer hours minutes seconds
```
