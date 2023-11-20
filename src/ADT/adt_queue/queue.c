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
        printf("[");
        for (i = IDX_HEAD(q); i < (IDX_HEAD(q)+Qlength(q))-1; i++){
            printf("%d,", q.buffer[i]);
        }
        printf("%d]\n", q.buffer[i]);
    }
}


void enqueueFirst(Queue *q, Song val){
    int i;
    for (i = IDX_TAIL(*q); i > IDX_HEAD(*q); i--) {
        (*q).buffer[i] = (*q).buffer[i-1];
    }
    HEAD(*q) = val;
}

void songNext (Queue *queueSong, Stack *previousSong, Song *onPlaySong){
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
    if ((Qlength(*queueSong)) >= 1){ // Isi queueSong 1 atau lebih lagu yang telah di-Queue
        dequeue(queueSong, onPlaySong);
        PushStac(&previousSong, *onPlaySong);
        
        printf("\nMemutar lagu selanjutnya\n");
        printf("\"");
        DisplayKata(onPlaySong->titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong->singer);
        printf("\"");
    }
    else {
        *onPlaySong = InfoTop(*previousSong);
        printf("\nQueue Kosong, memutar kembali lagu\n");
        printf("\"");
        DisplayKata(onPlaySong->titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong->singer);
        printf("\"");
    }
}

void songPrev (Queue *queueSong, Stack *previousSong, Song *onPlaySong){
/*
Saat procedure songPrev dijalankan, program WayangWave akan melakukan:
1. Terdapat kumpulan song yang telah dimainkan dan dimasukkan ke previousSong yang bertipe Stack
2. Setiap Song yang selesai dimainkan, akan disimpan dalam Stack previousSong dan akan menjadi Top dari Stack tersebut
3. Setiap Song Prev, akan menjalankan Song dengan posisi Top dari Stack previousSong

Contoh: Kondisi Riwayat Tidak Kosong

Memutar lagu sebelumnya 
“Hype Boy” oleh “New Jeans”

Contoh: Kondisi Riwayat Kosong
Riwayat kosong, memutar kembali lagu
“Mirror” oleh “Yasuda Rei”
*/
    Song tempSong;
    if (IsEmptyStack(*previousSong)){
        printf("\nRiwayat lagu kosong, memutar kembali lagu\n");
        printf("\"");
        DisplayKata(onPlaySong->titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong->singer);
        printf("\"");
    }
    else{
        if(QisFull(*queueSong)){
            printf("\nDaftar lagu pada Queue sudah penuh!\n");
        }
        else{
            PopStack(previousSong, &tempSong); // Menyimpan Song Previous di posisi temporary
            enqueueFirst(&queueSong, *onPlaySong); // Menyimpan Song yang sedang dimainkan menjadi HEAD DARI QUEUE SONG
            // Mengubah tempSong sebagai onPlaySong
            *onPlaySong = tempSong;

            printf("\nMemutar lagu sebelumnya\n");
            printf("\"");
            DisplayKata(onPlaySong->titleSong);
            printf("\" oleh \"");
            DisplayKata(onPlaySong->singer);
            printf("\"");

        }
    }
}

// int main(){

//     Queue q1, q2;
//     ElType val1;
//     CreateQueue(&q1);
//     displayQueue(q1);
//     printf("Is Q1 empty? %u\n", isEmpty(q1));
//     enqueue(&q1, 1);
//     enqueue(&q1, 2);
//     displayQueue(q1);
//     printf("Is Q1 full? %u\n", isFull(q1));
//     dequeue(&q1, &val1);
//     displayQueue(q1);
//     dequeue(&q1, &val1);
//     printf("Length of Q1: %d", length(q1));
//     displayQueue(q1);
//     printf("%d\n", val1);

//     return 0;
// }