#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen(char **argv)
{
    int gen_len;
    if (argv[2] == NULL) {
        gen_len = 12;
    } else {
        gen_len = atoi(argv[2]);
    }

    char gen[gen_len];
    srand((unsigned int)(time(NULL)));

    char *upper = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char *lower = "abcdefghijklmnoqprstuvwyzx";
    char *numbers = "0123456789";
    char *special = "!@#$^&*?%_";

    int randomizer = 0;
    int randomizer_modval = 4;

    if (strcmp(argv[1], "pw") == 0) {
        if (argv[3] != NULL) {
            randomizer_modval = 4;
        } else {
            randomizer_modval = 3;
        }
    } else if (strcmp(argv[1], "pp") == 0) {
        if (argv[3] != NULL) {
            randomizer_modval = 3;
        } else {
            randomizer_modval = 2;
        }
    } else {
        return 1;
    }

    for (int i = 0; i < gen_len; ++i) {
        randomizer = rand() % randomizer_modval;
        if (randomizer == 0) {
            gen[i] = upper[rand() % 26];
            printf("%c", gen[i]);
        }
        else if (randomizer == 1) {
            gen[i] = lower[rand() % 26];
            printf("%c", gen[i]);
        }
        else if (randomizer == 2) {
            gen[i] = numbers[rand() % 10];
            printf("%c", gen[i]);
        }
        else {
            gen[i] = special[rand() % 10];
            printf("%c", gen[i]);
        }
    }
    printf("\n");
    return 0;
}

// pgwen [gen_type *required] [gen_length] [include_special|include_numbers]
int main(int argc, char **argv)
{
    if (argc == 1) {
        return 1;
    } else {
        gen(argv);
    }
}