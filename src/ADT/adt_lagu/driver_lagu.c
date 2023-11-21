#include <stdio.h>
#include "lagu.h"

int main() {
    Desc lagu1, lagu2, lagu3;

    Word penyanyi1 = ToKata("Adele");
    Word album1 = ToKata("25");
    Word judul1 = ToKata("Hello");
    CreateDesc(&lagu1, penyanyi1, album1, judul1);

    Word penyanyi2 = ToKata("Ed Sheeran");
    Word album2 = ToKata("Divide");
    Word judul2 = ToKata("Shape of You");
    CreateDesc(&lagu2, penyanyi2, album2, judul2);

    printf("Lagu 1:\n");
    DisplayDesc(lagu1);
    printf("\n");

    printf("Lagu 2:\n");
    DisplayDesc(lagu2);
    printf("\n");

    PasteDesc(lagu2, &lagu3);

    printf("Menyalin Lagu 2:\n");
    DisplayDesc(lagu3);

    return 0;
}

// gcc -o main src/adt/adt_mesinkarakter/mesinkarakter.c src/adt/adt_mesinkata/mesinkata.c src/adt/adt_lagu/lagu.c src/adt/adt_lagu/driver_lagu.c