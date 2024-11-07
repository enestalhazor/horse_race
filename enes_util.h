#ifndef ENES_UTIL
#define ENES_UTIL

unsigned char get_random_number(unsigned char min, unsigned char max);

int perform_race(int racer_count);

void print_spaces(int count);

struct horse
{
    int distance;
};

#endif