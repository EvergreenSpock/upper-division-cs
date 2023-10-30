#include <stdio.h>
//determines how many arguments are inputed into the script on the commandline
int main(int arg_count, char *arg_list[]) {
    int i;
    printf("There were %d arguments provided:\n", arg_count);
    for(i=0; i < arg_count; i++)
        printf("argument #%d\t-\t%s\n", i, arg_list[i]); 
}