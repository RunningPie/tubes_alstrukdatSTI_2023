#include "linkedlist_v2.h"
#include "../adt_lagu/lagu.h"
#include <stdio.h>

int main() {
    LinkedList list;
    CreateLinkedList(&list);

    // Menambahkan elemen ke dalam list
    Desc desc1, desc2, desc3;
    desc1.Penyanyi = ToKata("Adele");
    desc1.Album = ToKata("25");
    desc1.Lagu = ToKata("Hello");

    desc2.Penyanyi = ToKata("Ed Sheeran");
    desc2.Album = ToKata("Divide");
    desc2.Lagu = ToKata("Shape of You");

    // CreateDesc(&desc2, ToKata("Ed Sheeran"), ToKata("Divide"), ToKata("Shape of You"));

    desc3.Penyanyi = ToKata("Justin Bieber");
    desc3.Album = ToKata("My World");
    desc3.Lagu = ToKata("One Time");

    // printf("panjang album: %d\n", desc2.Album.Length);
    // printf("test album: "); DisplayKata(desc2.Album);

    LinkedListInsertFirst(&list, desc1);
    LinkedListInsertLast(&list, desc2);
    LinkedListInsertAt(&list, desc3, 1);

    // Menampilkan elemen-elemen list
    printf("Elemen-elemen list:\n");
    for (int i = 0; i < LinkedListLength(list); i++) {
        // printf("Loop jalan29\n");
        Desc currentDesc = getElmt(list, i);
        // printf("Loop jalan31\n");
        printf("Penyanyi: %s, Album: %s, Lagu: %s\n", currentDesc.Penyanyi.TabWord, currentDesc.Album.TabWord, currentDesc.Lagu.TabWord);
        // printf("Loop jalan32\n");
    }

    // Menghapus elemen terakhir
    Desc deletedDesc;
    LinkedListDeleteLast(&list, &deletedDesc);
    printf("\nElemen terakhir dihapus:\n");
    printf("Penyanyi: %s, Album: %s, Lagu: %s\n", deletedDesc.Penyanyi.TabWord, deletedDesc.Album.TabWord, deletedDesc.Lagu.TabWord);

}

// gcc -o main src/adt/adt_linkedlist/linkedlist_v2.c src/adt/adt_linkedlist/driver_linkedlist.c src/adt/adt_mesinkata/mesinkata.c src/adt/adt_mesinkarakter/mesinkarakter.c src/adt/adt_lagu/lagu.c