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
#include "../src/ADT/adt_linkedlist/linkedlist_v2.h"       // ADT linked list
#include "../src/ADT/adt_lagu/lagu.h"                      // ADT lagu
#include "../src/ADT/adt_help/help.h"                      // ADT help

#include "../src/ADT/struct.h"
#include "../src/ADT/boolean.h"

#include <stdio.h>
#include <stdlib.h>
// #include <Word.h>
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

void PLAYSONG(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu, Queue *QueueL, Stack *historyL, Song *currentSong);
/*
PLAYSONG merupakan command yang digunakan untuk memainkan lagu berdasarkan masukan nama penyanyi, nama album, dan id lagu.
*/
// I.S. Daftar penyanyi, daftar album, daftar lagu dalam album sudah terdefinisi
// F.S. queue dan riwayat lagu akan menjadi kosong.

void PLAYPLAYLIST(ArrayDin daftarPlaylist, Map *playlistSongs, Queue *QueueL, Stack *historyL, Song *onPlaySong);
/*
PLAYPLAYLIST merupakan command yang digunakan untuk memainkan lagu berdasarkan id playlist

// I.S. Daftar penyanyi, daftar album, daftar lagu dalam album sudah terdefinisi
// F.S. current song akan menjadi lagu pada urutan pertama playlist dan queue akan berisi semua lagu yang ada dalam playlist 
yang akan dimainkan dan isi riwayat lagu sama dengan queue, tetapi dengan urutan yang di-reverse.
*/

void PLAYLISTCREATE(ArrayDin *daftarPlaylist);
/*
Command PLAYLISTCREATE digunakan untuk membuat playlist baru dan ditambahkan pada 
daftar playlist pengguna. Keadaan awal playlist adalah kosong. Nama playlist dapat 
sama dengan playlist yang sudah ada
*/
// I.S. Playlist belum ada
// F.S. Playlist berhasil dibuat jika input pengguna valid

void PLAYLISTADDSONG(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu);
/*
Command PLAYLISTADDSONG digunakan untuk menambahkan lagu pada suatu playlist yang telah 
ada sebelumnya pada daftar playlist pengguna.Pada defaultnya,command ini hanya dapat
menambahkan satu spesifik lagu kepada suatu playlist. Apabila lagu yang ingin ditambahkan sudah ada didalam 
suatu playlist pengguna, maka lagu-lagu yang ditambahkan adalah yang belum ada di playlist pengguna.
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Lagu baru berhasil ditambahkan ke playlist jika input user valid

void PLAYLISTADDALBUM(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu);
/*
Command PLAYLISTADDALBUM digunakan untuk menambahkan album pada suatu playlist yang telah 
ada sebelumnya pada daftar playlist pengguna.Pada defaultnya,command ini hanya dapat
menambahkan semua lagu yang ada pada album kepada suatu playlist. 
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Album baru berhasil ditambahkan ke playlist jika input user valid

void PLAYLISTSWAP(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu, int id, int x, int y);
/*
Command PLAYLISTSWAP digunakan untuk menukar lagu pada urutan ke x dan juga urutan ke y 
di playlist dengan urutan ke id
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Lagu dengan urutan x dan urutan y berhasil ditukar jika input user valid

void PLAYLISTREMOVE(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu, int id, int n);
/*
Command PLAYLISTREMOVE digunakan untuk menghapus lagu dengan urutan n pada playlist
dengan index id.
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Lagu pada urutan n berhasil dihapus jika input user valid

void PLAYLISTDELETE(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu);
/*
Command PLAYLISTDELETE digunakan untuk melakukan penghapusan suatu existing playlist 
dalam daftar playlist pengguna.Tampilkan pesan error apabila masukkan pengguna
tidak valid pada setiap permintaan masukkan.
*/
// I.S. Lagu di playlist terdefinisi
// F.S. Playlist berhasil dihapus jika input user valid

void STATUS(Song currentL, Queue QueueL);
/*
STATUS merupakan command yang digunakan untuk menampilkan lagu yang sedang dimainkan 
beserta Queue song yang ada dan dari playlist mana lagu itu diputar
*/
// I.S.
// F.S.

void LOAD(Word filename);
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


// BAGIAN SONG: (1) songNext, (2) songPrev
void songNext (Queue *queueSong, Stack *previousSong, Song *onPlaySong);
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

void songPrev (Queue *queueSong, Stack *previousSong, Song *onPlaySong);
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

void enqueueSong (List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu, Queue *queueSong);
/*
Proses: Procedure yang digunakan untuk menambahkan lagu ke dalam queue. Procedure ini akan menerima tiga input, pertama Nama dari Penyanyi, kedua Nama dari Album yang dipilih, dan ketiga ID Lagu yang dipilih. ID Lagu tersebut sebagai key dari lagu yang akan di queue.  
I.S.: Queue kosong atau queue berisi lagu yang sebelumnya telah di queue
F.S.: Queue berisi satu lagu atau queue telah ditambahkan dengan masukan lagu yang baru (Isi queue minimal satu lagu) pada posisi TAIL queue
*/

void queuePlaylist(Queue *queueSong, ArrayDin daftarPlaylist);
/*
Proses: Procedure yang digunakan untuk menambahkan seluruh lagu yang ada dalam playlist yang dimasukkan ke dalam queue. Procedure ini akan menetima satu input, yaitu ID dari playlist. 
I.S.: Queue kosong atau queue berisi lagu yang sebelumnya telah di queue
F.S.: Queue berisi satu atau lebih lagu yang di queue dari suatu playlist yang dimasukkan. Proses memasukkan lagu dimulai dari lagu pertama dari PLAYLIST dan dimasukkan pada posisi TAIL queue
*/

void queueSwap(Queue *queueSong, int x, int y);
/*
Proses: Procedure yang digunakan untuk menukar lagu pada urutan ke-x dan urutan ke-y. Input pada Command ini adalah dua id lagu (x, y). 
I.S.: Posisi lagu dengan id x dan posisi lagu dengan id y tetap berdasarkan urutan queue sebelumnya atau salah satu dari x atau y tidak terdefinisi 
F.S.: Posisi lagu dengan id x berada di posisi lagu dengan id y, serta posisi lagu dengan id y berada di posisi lagu dengan id x (Swapping telah dilakukan) apabila x dan y terdefinisi 
*/
void queueRemove(Queue *queueSong, int id);
/*
Proses: Procedure yang digunakan untuk menghapus lagu dari queue berdasarkan id yang dimasukkan. Input pada Command ini adalah id lagu (id) yang ingin dihapus dari queue
I.S.: Terdapat lagu (berdasarkan id yang dimasukkan) pada queue atau id yang dimasukkan tidak terdefinisi 
F.S.: Lagu (id) dihapus dari queue apabila id terdefinisi   
*/
void queueClear(Queue *queue);
/*
Proses: Procedure yang digunakan untuk mengosongkan queue.
I.S.: Queue berisi lagu yang telah di-queue sebelumnya
F.S.: Queue kosong atau tidak berisi lagu 
*/

void SAVE(Word filename, List daftarPenyanyi, Map penyanyiAlbum,
Map albumLagu, Song currentSong, Queue currentQ, Stack currentHist);
/*
SAVE merupakan command yang digunakan untuk menyimpan state aplikasi terbaru ke dalam suatu file.
Command SAVE memiliki satu argumen yang merepresentasikan nama file yang akan disimpan.
Penyimpanan dilakukan pada folder tertentu, misal folder save.
*/
// I.S. Sembarang dalam sesi
// F.S. Terbentuk suatu file bernama <filename> di folder save.

void QUIT(List daftarPenyanyi, Map penyanyiAlbum, Map albumLagu,
Song currentSong, Queue currentQ, Stack currentHist);
// QUIT merupakan command yang digunakan untuk keluar dari sesi aplikasi WayangWave.
// I.S. Sembarang dalam sesi
// F.S. Keluar dari sesi. Jika data sesi disimpan maka terbentuk suatu file bernama <filename> di folder save.

void InvalidSession();
// menuliskan ketika command benar tapi di sesi yang salah