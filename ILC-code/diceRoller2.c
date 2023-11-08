#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void usage(char *prog_name) {
    printf("Usage: %s <number_of_dice> <number_of_sides>\n", prog_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    int i;
    int arg_position = 1; // Position of the first argument that is not the program name

    if(argc < 3) { // Need at least two arguments: number of dice and sides
        usage(argv[0]); // Show usage message and exit if not enough arguments
    }

    // Convert the string arguments to integers using atoi
    int dice_number = atoi(argv[arg_position++]); // Increment arg_position after use
    int max_side = atoi(argv[arg_position]);
    int verbose_mode = 0;

    // Checking for verbose flag
    if(strcmp(argv[1], "-v") == 0) {
        printf("Verbose mode: active\n");
        verbose_mode = 1;
        // If verbose flag is present, adjust the dice_number and max_side accordingly
        if(argc < 4) { // Need at least two more arguments for dice and sides
            usage(argv[0]);
        }
        dice_number = atoi(argv[arg_position++]); // Increment arg_position after use
        max_side = atoi(argv[arg_position]);
    }

    unsigned int seed = (unsigned int)time(0);

    printf("Rolling %d dice with %d sides each.\n", dice_number, max_side);
    srand(seed); // Seed the random number generator
    if(verbose_mode == 1){
        printf("seed: %d\n", seed);
        printf("dice number: %d\n", dice_number);
        printf("max sides: %d\n", max_side);
    }
    for(i = 0; i < dice_number; i++) {
        printf("Dice %d: %d\n", i + 1, (rand() % max_side) + 1);
    }

    return 0;
}
