/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../boolean.h"
#include "../adt_mesinkata/mesinkata.h"
#include "../adt_song/song.h"
#include "../adt_stack/stack.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef Word ElType;

// ADT QUEUE
typedef Song QueueEltype;
typedef struct {
	QueueEltype buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean QisEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean QisFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu ketika IDX_HEAD=0 dan IDX_TAIL=CAPACITY-1 */

int Qlength(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, ElType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

void enqueueFirst(Queue *q, Song val);

// Songs
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

// Queue Playlist
// void queuePlaylist(Queue *queueSong, Playlist playlist);

void queueSwap(Queue *queueSong, int x, int y);

void queueRemove(Queue *queueSong, int id);

void queueClear(Queue *queue);

#endif