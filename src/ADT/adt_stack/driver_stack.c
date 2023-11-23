#include <stdio.h>
#include "stack.h"

int main() {
    Stack test_S;


    printf("Test Konstruktor:\n");
    CreateEmptyStack(&test_S);
    printf("KONSTRUKTOR OK\n");

    printf("========================\n");

    printf("Test Predikat:\n");
    printf("IsEmptyStack: %u\n", IsEmptyStack(test_S));
    printf("IsFullStack: %u\n", IsFullStack(test_S));
    printf("PREDIKAT OK\n");

    printf("========================\n");

    printf("Test Push:\n");
    infotypeS s1;
    CreateSong(&s1, ToKata("Penyanyi1"), ToKata("Album1"), ToKata("Lagu1"));
    PushStack(&test_S, s1);
    printf("Top Stack: %s {Harusnya bernilai Penyanyi1}\n", InfoTop(test_S).Penyanyi.TabWord);
    printf("PUSH OK\n");

    printf("========================\n");

    printf("Test Pop:\n");
    infotypeS s2, s3;
    CreateSong(&s2, ToKata("Penyanyi2"), ToKata("Album2"), ToKata("Lagu2"));
    PushStack(&test_S, s2);
    printf("Top Stack: %s {Harusnya bernilai Penyanyi2}\n", InfoTop(test_S).Penyanyi.TabWord);
    PopStack(&test_S, &s3);
    printf("s3.Penyanyi: %s {Harusnya bernilai Penyanyi2}\n", s3.Penyanyi.TabWord);
    printf("POP OK\n");

    return 0;
}

// to test, type:
// gcc -o test_stack.exe driver_stack.c stack.c ../adt_mesinkata/mesinkata.c ../adt_mesinkarakter/mesinkarakter.c ../adt_lagu/lagu.c