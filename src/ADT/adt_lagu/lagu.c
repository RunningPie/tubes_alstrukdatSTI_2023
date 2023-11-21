#include "lagu.h"

void CreateSong(Song *d, Word penyanyi, Word album, Word lagu) {
    SalinKata(penyanyi, &(*d).Penyanyi);
    SalinKata(album, &(*d).Album);
    SalinKata(lagu, &(*d).Lagu);
}

boolean IsEmptySong(Song d) {
    return d.Penyanyi.Length == 0 && d.Album.Length == 0 && d.Lagu.Length == 0;
}

void PasteSong(Song source, Song *dest) {
    SalinKata(source.Penyanyi, &(*dest).Penyanyi);
    SalinKata(source.Album, &(*dest).Album);
    SalinKata(source.Lagu, &(*dest).Lagu);
}

void DisplaySong(Song d) {
    if (IsEmptySong(d)) {
        printf("Kosong\n");
    }
    else {
        DisplayKata(d.Penyanyi);
        printf(" - ");
        DisplayKata(d.Album);
        printf(" - ");
        DisplayKata(d.Lagu);
        printf("\n");
    }
}