#include <stdio.h>
#include <string.h>
#include "enes_util.h"
#include <unistd.h>

unsigned char get_random_number(unsigned char min, unsigned char max)
{
    FILE *f = fopen("/dev/urandom", "r");

    unsigned char a = fgetc(f);

    fclose(f);

    return a % (max - min + 1) + min;
}

int perform_race(int racer_count)
{
    int winner = -1;
    int finished = 0;
    int track_length = 60;
    struct horse racers[100];

    for (int i = 0; i < racer_count; i++)
    {
        racers[i].distance = 0;
    }

    while (1)
    {
        usleep(1000 * 50);
        for (int j = 0; j < racer_count; j++)
        {
            unsigned char advanced = get_random_number(0, 1);
            if (advanced == 1)
            {
                racers[j].distance++;
                if (racers[j].distance == track_length)
                {
                    finished = 1;
                    winner = j;
                }
            }

            if (!finished)
            {
                print_spaces(racers[j].distance);
                fflush(stdout);

                printf("%d🐢", j + 1);
                fflush(stdout);

                print_spaces(track_length - 1 - racers[j].distance);
                fflush(stdout);

                printf("|\n");
                fflush(stdout);
            }
            else
            {
                printf("\x1b[1B");
                fflush(stdout);
            }
            fflush(stdout);
        }

        if (finished)
        {
            break;
        }
        printf("\x1b[%dF", racer_count);
    }

    return winner + 1;
}

void print_spaces(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf(" ");
    }
}
