/* Header untuk file console */
/* File ini berisi prototipe dari semua command yang akan diimplementasikan */
/* Prototipe dan implementasi dari semua command dipisah dari main agar lebih rapi
   dan terstruktur. Sehingga main lebih efektif dan mudah dibaca */

#include "../src/ADT/adt_map/map.h"                        // ADT Map dan Set
#include "../src/ADT/adt_list/arraydin.h"                  // ADT list dinamis
#include "../src/ADT/adt_mesinkarakter/mesinkarakter.h"    // ADT mesinkarakter
#include "../src/ADT/adt_mesinkata/mesinkata.h"            // ADT mesinkata v1
#include "../src/ADT/adt_queue/circular_queue.h"           // ADT queue circular (queue v3)
#include "../src/ADT/adt_queue/queue.h"                    // ADT queue v2
#include "../src/ADT/adt_stack/stack.h"                    // ADT stack dengan array
#include "../src/ADT/adt_list/list.h"                      // ADT list statis

#include "../src/ADT/struct.h"
#include "../src/ADT/boolean.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void STARTWAYANGWAVE(List *daftarPenyanyi, Map *PenyanyiAlbum, Map *AlbumLagu);
/*
START merupakan salah satu command yang dimasukkan pertama kali dalam WayangWave.
Setelah menekan Enter, dibaca file konfigurasi default yang berisi daftar penyanyi
serta album yang dimiliki.
*/
// I.S. Sembarang
// F.S. Program memasuki sesi
//      Daftar penyanyi default terinisialisasi beserta album yang dimiliki

void LOAD(String filename);
/*
LOAD merupakan salah satu command yang dimasukkan pertama kali dalam WayangWave.
Command ini memiliki satu argumen yaitu filename yang merepresentasikan suatu
save file yang ingin dibuka. Setelah menekan Enter, akan dibaca save file <filename>
yang berisi list penyanyi, album, dan lagu yang bisa diputar. Lebih detailnya
bisa dilihat pada Konfigurasi Aplikasi.
*/
// I.S. Sembarang
// F.S. Jika save file bernama <filename> ditemukan
//         Program memasuki sesi
//         Daftar penyanyi, album, dan lagu dari save file terinisialisasi
//         Queue yang tersimpan dalam save file akan dimuat ke queue dalam main
//         Riwayat lagu yang tersimpan akan dimuat ke stack di main
//         Playlist dalam save file akan dimuat menjadi playlist-playlist dalam main
//      Jika save file bernama <filename> tidak ditemukan
//         Tuliskan pesan kegagalan pada layar. Program tidak memasuki sesi.

void SAVE(String filename);
/*
SAVE merupakan command yang digunakan untuk menyimpan state aplikasi terbaru ke dalam suatu file.
Command SAVE memiliki satu argumen yang merepresentasikan nama file yang akan disimpan.
Penyimpanan dilakukan pada folder tertentu, misal folder save.
*/
// I.S. Sembarang dalam sesi
// F.S. Terbentuk suatu file bernama <filename> di folder save.

// BAGIAN SONG: (1) songNext, (2) songPrev
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

// BAGIAN QUEUE: (1) Queue Song, (2) Queue Playlist, (3) Queue Swap, (4) Queue Remove, (5) Queue Clear

void enqueueSong (Queue *queueSong, Song val);
/*






*/
// void enqueuePlaylist(Queue *queueSong, Playlist playlist);

void queueSwap(Queue *queueSong, int x, int y);
/*






*/
void queueRemove(Queue *queueSong, int id);
/*






*/
void queueClear(Queue *queue);
/*






*/


void QUIT();
// QUIT merupakan command yang digunakan untuk keluar dari sesi aplikasi WayangWave.
// I.S. Sembarang dalam sesi
// F.S. Keluar dari sesi. Jika data sesi disimpan maka terbentuk suatu file bernama <filename> di folder save.rty