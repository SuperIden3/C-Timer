# C-Timer

This project provides two simple C programs: `timer` and `stopwatch`.

Both programs intelligently detect if their output (`stdout`) is a terminal (TTY). This allows them to provide a dynamic, single-line display when run in a terminal, or a newline-separated output when redirected to a file, ensuring clean and appropriate formatting for different use cases.

## Usage

### Timer

The `timer` program simulates a countdown timer. It's highly flexible in how you specify the duration.

**Duration Input:**

You can provide the countdown duration in several ways:

*   `./timer`: Starts a default 10-second countdown.
*   `./timer <seconds>`: Counts down for the specified number of seconds.
*   `./timer <minutes> <seconds>`: Counts down for the specified minutes and seconds.
*   `./timer <hours> <minutes> <seconds>`: Counts down for the specified hours, minutes, and seconds.

The program uses `unsigned long long int` for time values, allowing for very long countdown durations.

**Time Normalization:**

A convenient feature is automatic time normalization. If you input minutes or seconds values greater than or equal to 60, the `timer` will correctly convert them into a standard time format. For example:

*   `./timer 0 0 70` will be interpreted as `00:01:10` (1 minute and 10 seconds).
*   `./timer 0 75 0` will be interpreted as `01:15:00` (1 hour and 15 minutes).

**Output Behavior (TTY vs. File):**

The `timer` intelligently adapts its output based on where it's being displayed:

*   **In a Terminal (TTY):** When run in a standard terminal, the timer will update the time dynamically in-place using a carriage return (`\r`). This provides a clean, single-line display that continuously refreshes. Upon completion, it will print a final "00:00:00" and emit an audible bell sound (`\007`) to notify you that the time is up.
*   **Redirected to a File/Pipe:** If you redirect the output (e.g., `./timer 5 > output.txt`), each one-second interval will be printed on a new line. This is useful for logging or processing the timer's progress. The bell sound is not emitted in this mode.

**Examples:**

```sh
# Default 10-second countdown
$ ./timer

# Countdown for 5 seconds
$ ./timer 5

# Countdown for 1 minute and 30 seconds
$ ./timer 1 30

# Countdown for 1 hour, 15 minutes, and 45 seconds
$ ./timer 1 15 45

# Countdown for 90 seconds (normalized to 00:01:30)
$ ./timer 0 0 90
```

### Stopwatch

The `stopwatch` program counts time upwards from zero, like a traditional stopwatch. It takes no arguments and will run indefinitely until manually stopped by the user (typically by pressing `Ctrl+C`).

**Output Behavior (TTY vs. File):**

Similar to the `timer`, the `stopwatch` adapts its output:

*   **In a Terminal (TTY):** The stopwatch displays the elapsed time, dynamically updating it in-place on a single line using a carriage return (`\r`). This provides a continuously refreshing view of the ongoing time.
*   **Redirected to a File/Pipe:** If you redirect the output (e.g., `./stopwatch > timing_log.txt`), each one-second interval of elapsed time will be printed on a new line.

The program uses `unsigned long long int` to store the elapsed time, allowing it to run and track time for exceptionally long periods.

**Example Usage and Output:**

To start the stopwatch, simply run the command:

```sh
$ ./stopwatch
```

If run in a terminal, the output will look something like this, updating every second:

```
00:00:00
```

(After 1 second)
```
00:00:01
```

(After 5 seconds)
```
00:00:05
```

(After 1 minute and 30 seconds)
```
00:01:30
```
And so on. Press `Ctrl+C` to stop it.

## Building the Project

To use the `timer` and `stopwatch` programs, you'll first need to compile them from their source code. This project uses Makefiles for easy compilation.

You will need `make` and a C compiler (like GCC or Clang) installed on your system.

*   **To build the timer:**
    ```sh
    make -f timer.Makefile
    ```
    This will create an executable file named `timer` in the current directory.

*   **To build the stopwatch:**
    ```sh
    make -f stopwatch.Makefile
    ```
    This will create an executable file named `stopwatch` in the current directory.

*   **To build both:**
    You can run the above commands sequentially.

*   **Cleaning up build files:**
    The Makefiles (`timer.Makefile`, `stopwatch.Makefile`) may also include `clean` targets to remove compiled object files and executables (e.g., `make -f timer.Makefile clean`).

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
