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
/*Function createSong digunakan untuk membuat instance dari ADT Song*/

void displaySongInfo(Song song);
/* Proses: Mencetak title, album, dan singer pada layar sesuai dengan struct Song */
/* I.S.: Song terdefinisi */
/* F.S.: Atribut song tercetak di layar */

#endif