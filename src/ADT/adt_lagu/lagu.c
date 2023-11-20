#include "lagu.h"

void CreateDesc(Desc *d, Word penyanyi, Word album, Word lagu) {
    SalinKata(penyanyi, &(*d).Penyanyi);
    SalinKata(album, &(*d).Album);
    SalinKata(lagu, &(*d).Lagu);
}

boolean IsEmptyDesc(Desc d) {
    return d.Penyanyi.Length == 0 && d.Album.Length == 0 && d.Lagu.Length == 0;
}

void PasteDesc(Desc source, Desc *dest) {
    SalinKata(source.Penyanyi, &(*dest).Penyanyi);
    SalinKata(source.Album, &(*dest).Album);
    SalinKata(source.Lagu, &(*dest).Lagu);
}

void DisplayDesc(Desc d) {
    if (IsEmptyD(d)) {
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