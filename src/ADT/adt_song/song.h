#ifndef SONG_CMD
#define SONG_CMD

#include "../ADT/adt_queue/queue.h"
#include "../ADT/adt_stack/stack.h"
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

void songNext (Queue *queueSong, Stack *previousSong);
/*
Saat procedure songNext dijalankan, program WayangWave akan melakukan:
1. Terdapat kumpulan song yang sudah diantrikan pada queueSong yang bertipe Queue
2. Setiap Song yang di-Queue, diantrikan dari belakang (Tail)
3. Setiap Next Song, akan menjalankan Song dengan antrian terdepan (Head)
Contoh: Kondisi Queue Tidak Kosong

Memutar lagu selanjutnya 
“Hype Boy” oleh “New Jeans”

Contoh: Kondisi Queue Kosong

'Queue kosong, memutar kembali lagu
“Mirror” oleh “Yasuda Rei”'

I.S.: queueSong berisi Song yang telah di-Queue
F.S.: Head dari queueSong dimainkan, Heed berganti ke lagu yang diantrikan selanjutnya pada queueSong
*/

void songPrev (Queue *queueSong, Stack *previousSong);
/*
Saat procedure songPrev dijalankan, program WayangWave akan melakukan:
1. Terdapat kumpulan song yang telah dimainkan dan dimasukkan ke previousSong yang bertipe Stack
2. Setiap Song yang selesai dimainkan, akan disimpan dalam Stack previousSong dan akan menjadi Top dari Stack tersebut
3. Setiap Song Prev, akan menjalankan Song dengan posisi Top dari Stack previousSong

Contoh: Kondisi Riwayat Tidak Kosong

Memutar lagu sebelumnya 
“Hype Boy” oleh “New Jeans”

Contoh: Kondisi Riwaya Kosong
Queue kosong, memutar kembali lagu
“Mirror” oleh “Yasuda Rei”
*/


#endif