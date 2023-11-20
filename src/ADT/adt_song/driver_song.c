#include <stdio.h>
#include "song.h"

int main() {
    // Tes constructor song
    char* titleChar = "Hello";
    Word titleSong = ToKata(titleChar);

    char* albumChar = "25";
    Word albumSong = ToKata(albumChar);

    char* singerChar = "singer";
    Word singerSong = ToKata(singerChar);

    Song newSong = createSong(titleSong, albumSong, singerSong);
    displaySongInfo(newSong);
}