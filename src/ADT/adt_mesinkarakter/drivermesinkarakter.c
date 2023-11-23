#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    START();

    while(!isEOP()) {
        printf("%c", currentChar);
        ADV();
    }
}