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
#include "../src/ADT/adt_linkedlist/linkedlist_v2.h"
#include "../src/ADT/adt_lagu/lagu.h"                      // ADT lagu

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

void LISTDEFAULT(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu);
/*
LISTDEFAUTL  digunakan untuk 
melihat list penyanyi yang ada. S
elanjutnya dapat memilih untuk melihat album dari penyanyi yang dipilih. Kemudian melihat lagu yang ada dari album yang dipilih. 
Terdapat konfirmasi apakah ingin melihat album/lagu.
*/
// I.S. Daftar penyanyi, daftar album, daftar lagu dalam album sudah terdefinisi
// F.S. Menampilkan daftar penyanyi, daftar album, daftar lagu dalam album ke layar

void LISTPLAYLIST(ArrayDin daftarPlaylist);
/*
LISTPLAYLIST merupakan command yang digunakan untuk menampilkan daftar playlist yang tersedia
*/
// I.S. Daftar playlist terdefinisi
// F.S. Menampilkan daftar playlist ke layar

void PLAYSONG(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu, Queue *QueueL, Stack *historyL);
/*
PLAYSONG merupakan command yang digunakan untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu.
*/
// I.S. Daftar penyanyi, daftar album, daftar lagu dalam album sudah terdefinisi
// F.S. queue dan riwayat lagu akan menjadi kosong.

void PLAYPLAYLIST(ArrayDin daftarPlaylist, Queue *QueueL, Stack *historyL);
/*
PLAYPLAYLIST merupakan command yang digunakan untuk memainkan lagu berdasarkan id playlist

// I.S. Daftar penyanyi, daftar album, daftar lagu dalam album sudah terdefinisi
// F.S. current song akan menjadi lagu pada urutan pertama playlist dan queue akan berisi semua lagu yang ada dalam playlist 
yang akan dimainkan dan isi riwayat lagu sama dengan queue, tetapi dengan urutan yang di-reverse.
*/

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

void QUIT();
// QUIT merupakan command yang digunakan untuk keluar dari sesi aplikasi WayangWave.
// I.S. Sembarang dalam sesi
// F.S. Keluar dari sesi. Jika data sesi disimpan maka terbentuk suatu file bernama <filename> di folder save.