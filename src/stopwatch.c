#define _POSIX_C_SOURCE 200809L

#include "_common.c"
#include <stdio.h> // printf
#include <unistd.h> // sleep

int main(void) { // Stopwatch program will take in no arguments, as it will count time forever.
  const int ISATTY = isatty(STDOUT_FILENO);
  timer_t seconds       = 0;
  timer_t minutes       = 0;
  timer_t hours         = 0;
  timer_t total_seconds = 0;

  while (1) {
    printf("%02llu:%02llu:%02llu", hours, minutes, seconds);
    if (ISATTY) {
      printf("\r");
      fflush(stdout);
    } else printf("\n");

    total_seconds++;
    hours   = total_seconds / 3600; // Divides by 3600 to get hours from total seconds.
    minutes = (total_seconds % 3600) / 60; // Wraps total seconds into hours and then divides by 60 to get minutes from total seconds.
    seconds = (total_seconds % 3600) % 60; // Wraps total seconds into hours and then wraps total seconds into minutes and then wraps total seconds into seconds.

    sleep(1); // Sleep for a second.
  }

  return 0;
}
