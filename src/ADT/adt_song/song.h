#ifndef SONG_CMD
#define SONG_CMD

#include "../ADT/adt_mesinkata/mesinkata.h"
#include "../ADT/boolean.h"

/* Definisi elemen dan address */
typedef Word ElType;
typedef int IDSong;

// STRUCT SONG (1)
typedef struct{
     Word titleSong;
     Word album;
     Word singer;
     int IDSong;
} Song;

#endif