#ifndef SONG_CMD
#define SONG_CMD

#include "../adt_mesinkata/mesinkata.h"
#include "../boolean.h"

/* Definisi elemen dan address */
typedef Word ElType;

// typedef int IDSong;

// STRUCT SONG (1)
typedef struct{
    Word titleSong;
    Word album;
    Word singer;
} Song;

Song createSong(Word titleSong, Word album, Word singer);

void displaySongInfo(Song song);

#endif