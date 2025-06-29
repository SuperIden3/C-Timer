# C-Timer

C programs that simulates a timer and a stopwatch.

Both codes would check if output (just `stdout`) is a TTY or not, enabling cleaner viewing of the printed time between terminal and plain-text output.

## Usage

### Timer

`timer` accepts three arguments: hours, minutes, and seconds. If no arguments are provided, then the default time is 10 seconds.

If minutes and seconds exceed 60, then they will be formatted and calculated to cleaner hours, minutes, and seconds. For instance, `./timer 0 0 60` would be formatted to `00:01:00`.

```sh
$ ./timer # For ten second countdown

$ ./timer seconds
$ ./timer minutes seconds
$ ./timer hours minutes seconds
```

### Stopwatch

Unlike the timer, the stopwatch is a program that counts time forever, meaning that it takes in no arguments. For the program to end, it would have to rely on the user pressing Ctrl+C.

```sh
$ ./stopwatch
```
