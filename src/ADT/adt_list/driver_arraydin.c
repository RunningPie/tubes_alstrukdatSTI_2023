#include "arraydin.h"
#include <stdio.h>

int main() {
    ArrayDin myArray = MakeArrayDin();

    ArrDinEl el1 = CreateArrDinEl(ToKata("Playlist1"));
    ArrDinEl el2 = CreateArrDinEl(ToKata("Playlist2"));
    ArrDinEl el3 = CreateArrDinEl(ToKata("Playlist3"));

    InsertLastArrDin(&myArray, el1);
    InsertLastArrDin(&myArray, el2);
    InsertLastArrDin(&myArray, el3);

    printf("Initial ArrayDin:\n");
    PrintArrayDin(myArray);

    printf("\nLength of ArrayDin: %d\n", LengthArrDin(myArray));
    printf("Capacity of ArrayDin: %d\n", GetCapacityArrDin(myArray));

    ReverseArrayDin(&myArray);
    printf("\nArrayDin after reversing:\n");
    PrintArrayDin(myArray);

    ArrDinEl searchEl = CreateArrDinEl(ToKata("Playlist2"));
    IdxType result = SearchArrayDin(myArray, searchEl);
    if (result != -1) {
        printf("\nElement %s found at index %d\n", WordToString(searchEl.namaPlaylist).content, result);
    } else {
        printf("\nElement not found\n");
    }

    ArrayDin copyArray = CopyArrayDin(myArray);
    printf("\nCopied ArrayDin:\n");
    PrintArrayDin(copyArray);

    return 0;
}


// gcc -o main src/adt/adt_list/arraydin.c src/adt/adt_list/driver_arraydin.c src/adt/adt_mesinkata/mesinkata.c src/adt/adt_mesinkarakter/mesinkarakter.c src/adt/adt_linkedlist/linkedlist_v2.c
