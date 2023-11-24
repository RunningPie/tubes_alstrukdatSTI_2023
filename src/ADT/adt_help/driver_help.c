#include "help.h"

int main(){
    help1();

    printf("\n == help 1 ok == \n");

    help2();

    printf("\n == help 2 ok == \n");    

    return 0;
}

// gcc -o help.exe driver_help.c help.c