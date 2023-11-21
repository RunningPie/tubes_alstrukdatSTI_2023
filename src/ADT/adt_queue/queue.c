/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean QisEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return (IDX_HEAD(q)==IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean QisFull(Queue q)
{
    return (IDX_HEAD(q) == 0 & IDX_TAIL(q) == CAPACITY-1);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu ketika IDX_HEAD=0 dan IDX_TAIL=CAPACITY-1 */

int Qlength(Queue q){
    if (QisEmpty(q)){
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q)+1);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Song val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    if (QisEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL(*q)==CAPACITY-1) {
            int i;
            for (i=IDX_HEAD(*q); i<=CAPACITY-1; i++){
                (*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
            }
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q)=0;
        }
        IDX_TAIL(*q)++;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, Song *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
{
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q)+1) % CAPACITY;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    int i = IDX_HEAD(q);

    if (QisEmpty(q)){
        printf("[]\n");
    } else {
        for (i = IDX_HEAD(q); i < (IDX_HEAD(q)+Qlength(q))-1; i++) {
            displaySongInfo(q.buffer[i]);
            printf("\n");
        }
    }
}


/* *** Tambahan Procedure *** */
/* Proses: Menambahkan lagu pada queue dengan urutan pertama*/
/*I.S.: Queue kosong atau berisi lagu yang telah di-queue sebelumnya 
/*F.S.: Queue telah ditambahkan dengan lagu yang ingin dimasukkan pada posisi HEAD */
void enqueueFirst(Queue *q, Song val){
    int i;
    for (i = IDX_TAIL(*q); i > IDX_HEAD(*q); i--) {
        (*q).buffer[i] = (*q).buffer[i-1];
    }
    HEAD(*q) = val;
}