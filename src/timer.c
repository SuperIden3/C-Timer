#define _POSIX_C_SOURCE 200809L

#include "_common.c"
#include <stdio.h> // printf
#include <unistd.h> // sleep
#include <stdlib.h> // strtoull
#include <stdbool.h> // Manage SIGTSTP using a `bool`
#include <unistd.h> // sleep; tcgetpgrp, getpgrp for checking if a process is in the foreground

static bool in_background = false;
static bool can_check = true;

int main(int argc, char **argv) {
  const bool ISATTY = isatty(STDOUT_FILENO) == 1; // Check if stdout is a tty for those who want to play with this source coude in a plain-text output.

  timer_t seconds       = 0;
  timer_t minutes       = 0;
  timer_t hours         = 0;
  timer_t total_seconds = 0; // Total time as seconds, used for the while loop for checking and ending the program when time's up.

  switch (argc) {
    case 4: // ./timer h m s
      hours   = strtoull(argv[1], NULL, 10);
      minutes = strtoull(argv[2], NULL, 10);
      seconds = strtoull(argv[3], NULL, 10);
      break;

    case 3: // ./timer h s
      minutes = strtoull(argv[1], NULL, 10);
      seconds = strtoull(argv[2], NULL, 10);
      break;

    case 2: // ./timer s
      seconds = strtoull(argv[1], NULL, 10);
      break;

    case 1: // ./timer
      seconds = 10llu;
      break;
  }

  // Hours, minutes, and seconds would be changed if minutes and seconds exceed 60.
  while (seconds >= 60 || minutes >= 60) {
    hours += minutes / 60;   // Add to hours if minutes exceed 60.
    minutes %= 60;           // Set minutes to 0 if minutes exceed 60.
    minutes += seconds / 60; // Add to minutes if seconds exceed 60.
    seconds %= 60;           // Set seconds to 0 if seconds exceed 60.
  }

  total_seconds = as_seconds(hours, minutes, seconds);
  while (total_seconds > 0) {
    const pid_t fg = tcgetpgrp(STDIN_FILENO); // Check if a process is in the foreground
    const pid_t pg = getpgrp(); // Check if a process is in the background
    if (fg == -1) { // Handle error
      can_check = false; // Stop checking if a process is in the foreground
    }
    if (can_check) { // If checkable...
      in_background = pg != fg; // Set background to true if a process is in the background
    }

    // Format & print time and decrement total seconds.
    if (!in_background) { // Only print time if not in the background
      printf("%02llu:%02llu:%02llu", hours, minutes, seconds);
      if (ISATTY) {
        printf("\r");
        fflush(stdout);
      } else {
        printf("\n");
      }
    }
    sleep(1);
    total_seconds--;

    // Decrement time if needed.
    if (seconds == 0) {
      if (minutes == 0) { // If there are 0 minutes on timer, reset to 59 minutes and borrow from hours.
        hours--;
        minutes = 59;
        seconds = 59;
      } else { // If there are 0 seconds on timer, reset to 59 seconds and borrow from minutes.
        minutes--;
        seconds = 59;
      }
    } else {
      seconds--;
    }
  }

  if (!in_background) printf("00:00:00");
  if (ISATTY) printf("\007");
  printf("\n");
  return 0;
}
