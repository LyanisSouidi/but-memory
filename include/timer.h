#ifndef TIMER_H
#define TIMER_H
#define DELTA 1000000L

void update_timer(unsigned long int start);

unsigned long int start_timer(unsigned long int start);

unsigned long int stop_timer(unsigned long int start);

void wait(int sec);

#endif