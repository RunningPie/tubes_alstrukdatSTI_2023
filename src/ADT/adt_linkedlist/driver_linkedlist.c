#include "linkedlist_v2.h"
#include "../adt_lagu/lagu.h"
#include <stdio.h>

int main() {
    LinkedList list;
    CreateLinkedList(&list);

    // Menambahkan elemen ke dalam list
    Song Song1, Song2, Song3;
    Song1.Penyanyi = ToKata("Adele");
    Song1.Album = ToKata("25");
    Song1.Lagu = ToKata("Hello");

    Song2.Penyanyi = ToKata("Ed Sheeran");
    Song2.Album = ToKata("Divide");
    Song2.Lagu = ToKata("Shape of You");

    // CreateSong(&Song2, ToKata("Ed Sheeran"), ToKata("Divide"), ToKata("Shape of You"));

    Song3.Penyanyi = ToKata("Justin Bieber");
    Song3.Album = ToKata("My World");
    Song3.Lagu = ToKata("One Time");

    // printf("panjang album: %d\n", Song2.Album.Length);
    // printf("test album: "); DisplayKata(Song2.Album);

    LinkedListInsertFirst(&list, Song1);
    LinkedListInsertLast(&list, Song2);
    LinkedListInsertAt(&list, Song3, 1);

    // Menampilkan elemen-elemen list
    printf("Elemen-elemen list:\n");
    for (int i = 0; i < LinkedListLength(list); i++) {
        // printf("Loop jalan29\n");
        Song currentSong = getElmt(list, i);
        // printf("Loop jalan31\n");
        printf("Penyanyi: %s, Album: %s, Lagu: %s\n", currentSong.Penyanyi.TabWord, currentSong.Album.TabWord, currentSong.Lagu.TabWord);
        // printf("Loop jalan32\n");
    }

    // Menghapus elemen terakhir
    Song deletedSong;
    LinkedListDeleteLast(&list, &deletedSong);
    printf("\nElemen terakhir dihapus:\n");
    printf("Penyanyi: %s, Album: %s, Lagu: %s\n", deletedSong.Penyanyi.TabWord, deletedSong.Album.TabWord, deletedSong.Lagu.TabWord);

}

// gcc -o main src/adt/adt_linkedlist/linkedlist_v2.c src/adt/adt_linkedlist/driver_linkedlist.c src/adt/adt_mesinkata/mesinkata.c src/adt/adt_mesinkarakter/mesinkarakter.c src/adt/adt_lagu/lagu.c