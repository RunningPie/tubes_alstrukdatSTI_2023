/* MODUL CIRCULAR CQUEUE */
/* Definisi ADT CQueue dengan representasi array secara eksplisit dan alokasi statik */
/* Implementasi CQueue menggunakan circular buffer (Alternatif III) */

#ifndef __circular_Cqueue_h__
#define __circular_Cqueue_h__

#include "../boolean.h"
#include "../adt_mesinkata/mesinkata.h"
#include "../struct.h"
#include "../adt_lagu/lagu.h"

#define IDX_UNDEF -1
#define IDX_MAX 99

/* Definisi tipe elemen dan indeks pada CQueue */
typedef Word ElType;
typedef int IdxType;

typedef struct {
        ElType Tab[IDX_MAX+1];  /* tabel penyimpan elemen */
        IdxType idxHead;  /* indeks elemen paling awal (terdepan) */
        IdxType idxTail;  /* indeks tempat menambah elemen baru */
} CQueue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah CQueue, maka akses elemen : */
#define CQIDX_HEAD(q) (q).idxHead
#define CQIDX_TAIL(q) (q).idxTail
#define     CQHEAD(q) (q).Tab[(q).idxHead]
#define     CQTAIL(q) (q).Tab[(q).idxTail]

/* ********* Prototype ********* */
boolean CQIsEmpty (CQueue Q);
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean CQIsFull (CQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int CQLength (CQueue Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateCCQueue (CQueue * Q);
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void CQenCqueue (CQueue * Q, ElType X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
ElType CQdeCqueue (CQueue * Q);
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Display CQueue *** */
void displayCCQueue(CQueue q);
/* Proses : Menuliskan isi CQueue dengan traversal; CQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika CQueue kosong : menulis [] */
/* Note: Output mengandung newline */

#endif