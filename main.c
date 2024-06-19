#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen(int gen_len)
{
    char gen[gen_len];
    int randomizer = 0;
    srand((unsigned int)(time(NULL)));

    char *numbers = "0123456789";
    char *lower = "abcdefghijklmnoqprstuvwyzx";
    char *upper = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char *special = "!@#$^&*?%_";

    for (int i = 0; i < gen_len; ++i) {
        randomizer = rand() % 4;
        if (randomizer == 1) {
            gen[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            printf("%c", gen[i]);
        }
        else if (randomizer == 2) {
            gen[i] = special[rand() % 8];
            randomizer = rand() % 4;
            printf("%c", gen[i]);
        }
        else if (randomizer == 3) {
            gen[i] = upper[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", gen[i]);
        }
        else {
            gen[i] = lower[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", gen[i]);
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        return 1;
    }
    if (strcmp(argv[1], "pw") == 0 && argv[2] != NULL) {
        gen(atoi(argv[2]));
    }
    return 0;
}