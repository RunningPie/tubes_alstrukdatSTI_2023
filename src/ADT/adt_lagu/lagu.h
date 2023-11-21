#ifndef _LAGU_H_
#define _LAGU_H_

#include "../boolean.h"
#include <stdio.h>
#include "../adt_mesinkata/mesinkata.h"
#include "../struct.h"

typedef Word ElType;
typedef int IdxType;


void CreateSong(Song *d, Word penyanyi, Word album, Word lagu);
/* I.S. : d sembarang. 
          penyanyi, album, dan lagu yang terdefinisi, mungkin kosong. 
   F.S. : d menjadi deskripsi dengan isi penyanyi, album, dan lagu. */

boolean IsEmptySong(Song d);
/* mengecek jika isi d kosong. */

void PasteSong(Song source, Song *dest);
/* I.S. : source terdefinisi, dest sembarang. 
   F.S. : mengisi dest dengan isi source. */

void DisplaySong(Song d);
/* I.S. : d terdefinisi.
   F.S. : menampilkan penyanyi, album, lagu */

#endif
