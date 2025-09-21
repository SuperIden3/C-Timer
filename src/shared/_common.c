typedef unsigned long long int timer_t;

/**
 * @brief Quickly convert hours, minutes, and seconds into just seconds.
 * 
 * @param hours 
 * @param minutes 
 * @param seconds 
 * @return timer_t
 */
timer_t as_seconds(timer_t hours, timer_t minutes, timer_t seconds) { return seconds + (minutes * 60) + (hours * 3600); }

