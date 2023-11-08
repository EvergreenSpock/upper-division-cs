#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *prog_name) {
    printf("%s: <decimal> dice rolled <decimal> times\n", prog_name);
    exit(0);
}

//int argv[], char *arg_list[]
//determines how many arguments are inputed into the script on the command line
int main(int argc, char *argv[]) {
    int i;
    int arg_position = 1;
    int dice_number = atoi(argv[arg_position]); // Increment arg_position after use
    int max_side = atoi(argv[arg_position++]);
    printf("There were %d arguments provided:\n", argc);
    for(i=0; i < argc; i++)
        printf("argument #%d\t-\t%s\n", i, argv[i]); 
    if(argc < 3) //If no args
        usage(argv[0]);
    if(strcmp(argv[1], "-v") == 0) {
        printf("hello world\n");
        arg_position++;
    }
    printf("random values from 1 to %d\n", max_side);
    srand(time(0));
    for(i =0; i < dice_number; i++){
        printf("Dice %d: %d\n", i + 1, (rand()%max_side) + 1);
    }
}