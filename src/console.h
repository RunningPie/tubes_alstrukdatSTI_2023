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

void PLAYLISTCREATE(ArrayDin daftarPlaylist);
/*
Command PLAYLISTCREATE digunakan untuk membuat playlist baru dan ditambahkan pada 
daftar playlist pengguna. Keadaan awal playlist adalah kosong. Nama playlist dapat 
sama dengan playlist yang sudah ada
*/
// I.S. Playlist belum ada
// F.S. Playlist berhasil dibuat jika input pengguna valid

void PLAYLISTADDSONG(List daftarPenyanyi,ArrayDin daftarPlaylist, Map *penyanyiAlbum, Map *albumLagu);
/*
Command PLAYLISTADDSONG digunakan untuk menambahkan lagu pada suatu playlist yang telah 
ada sebelumnya pada daftar playlist pengguna.Pada defaultnya,command ini hanya dapat
menambahkan satu spesifik lagu kepada suatu playlist. Apabila lagu yang ingin ditambahkan sudah ada didalam 
suatu playlist pengguna, maka lagu-lagu yang ditambahkan adalah yang belum ada di playlist pengguna.
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Lagu baru berhasil ditambahkan ke playlist jika input user valid

void PLAYLISTADDALBUM(List daftarPenyanyi, Map *penyanyiAlbum, ArrayDin daftarPlaylist, Map *albumLagu);
/*
Command PLAYLISTADDALBUM digunakan untuk menambahkan album pada suatu playlist yang telah 
ada sebelumnya pada daftar playlist pengguna.Pada defaultnya,command ini hanya dapat
menambahkan semua lagu yang ada pada album kepada suatu playlist. 
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Album baru berhasil ditambahkan ke playlist jika input user valid

void PLAYLISTSWAP(List daftarPenyanyi, Map *penyanyiAlbum, ArrayDin daftarPlaylist, Map *albumLagu);
/*
Command PLAYLISTSWAP digunakan untuk menukar lagu pada urutan ke x dan juga urutan ke y 
di playlist dengan urutan ke id
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Lagu dengan urutan x dan urutan y berhasil ditukar jika input user valid

void PLAYLISTREMOVE(List daftarPenyanyi, Map *penyanyiAlbum, ArrayDin daftarPlaylist, Map *albumLagu);
/*
Command PLAYLISTREMOVE digunakan untuk menghapus lagu dengan urutan n pada playlist
dengan index id.
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Lagu pada urutan n berhasil dihapus jika input user valid

void PLAYLISTDELETE(List daftarPenyanyi, Map *penyanyiAlbum, ArrayDin daftarPlaylist, Map *albumLagu);
/*
Command PLAYLISTDELETE digunakan untuk melakukan penghapusan suatu existing playlist 
dalam daftar playlist pengguna.Tampilkan pesan error apabila masukkan pengguna
tidak valid pada setiap permintaan masukkan.
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Playlist berhasil dihapus jika input user valid

void STATUS();
/*
STATUS merupakan command yang digunakan untuk menampilkan lagu yang sedang dimainkan 
beserta Queue song yang ada dan dari playlist mana lagu itu diputar
*/
// I.S.
// F.S.

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