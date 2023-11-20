#include "song.h"

Song createSong(Word titleSong, Word album, Word singer) {
    Song newSong;
    newSong.titleSong = titleSong;
    newSong.album = album;
    newSong.singer = singer;

    return newSong;
}

void displaySongInfo(Song song) {
    DisplayKata(song.titleSong);
    DisplayKata(song.album);
    DisplayKata(song.singer);
}