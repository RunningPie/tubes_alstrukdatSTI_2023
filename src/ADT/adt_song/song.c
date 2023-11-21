#include <stdio.h>
#include "song.h"

Song createSong(Word titleSong, Word album, Word singer) {
/*Function createSong digunakan untuk membuat instance dari ADT Song*/ 
    Song newSong;

    newSong.titleSong = titleSong;
    newSong.album = album;
    newSong.singer = singer;

    return newSong;
}

void displaySongInfo(Song song) {
/* Proses: Mencetak title, album, dan singer pada layar sesuai dengan struct Song */
/* I.S.: Song terdefinisi */
/* F.S.: Atribut song tercetak di layar */
    DisplayKata(ToKata("Title: "));
    DisplayKata(song.titleSong);
    printf("\n");
    DisplayKata(ToKata("Album: "));
    DisplayKata(song.album);
    printf("\n");
    DisplayKata(ToKata("Singer: "));
    DisplayKata(song.singer);
    printf("\n");
}