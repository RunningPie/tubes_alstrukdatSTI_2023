#include <stdio.h>
#include "song.h"

Song createSong(Word titleSong, Word album, Word singer) {
    Song newSong;

    newSong.titleSong = titleSong;
    newSong.album = album;
    newSong.singer = singer;

    return newSong;
}

void displaySongInfo(Song song) {
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