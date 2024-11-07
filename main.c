#include <stdio.h>
#include "enes_util.h"
#include <unistd.h>

int main()
{
    int horse_count;
    int current;
    int horse_num;
    int bet;
    int race_num = 1;

    printf("Welcome to horses racing game!\n");
    printf("enter the money you have currently: ");
    scanf("%d", &current);

    while (current > 0)
    {
        printf("%d. horse racing starts!\n", race_num);
        horse_count = get_random_number(3, 9);
        printf("%d horses are racing\n", horse_count);

        do
        {
            printf("which horse do you want to bet (1-%d): ", horse_count);
            scanf("%d", &horse_num);
        } while (!(horse_num > 0 && horse_num <= horse_count));

        do
        {
            printf("how much do you want to bet (1-10000): ");
            scanf("%d", &bet);
        } while (bet > 10000 || bet > current);

        current = current - bet;
        int conclusion = perform_race(horse_count);
        if (horse_num == conclusion)
        {
            int commission = horse_count * bet / 2;

            if (commission > 15000)
            {
                commission = 15000;
            }

            current = current + commission + bet;
            printf("you won, your current balance is %d\n", current);
        }
        else
        {
            printf("horse %d won, your current balance is %d\n", conclusion, current);
        }

        race_num++;
    }
    printf("game over\n");

    return 0;
}