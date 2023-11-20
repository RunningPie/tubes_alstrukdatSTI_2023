#include <stdio.h>
#include "song.h"

void songNext (Queue *queueSong, Stack *previousSong){
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
// Pertanyaan: Status apakah sudah ada bentukan type-nya?
    Song onPlaySong;
    
    if ((Qlength(*queueSong)) >= 1){ // Isi queueSong 1 atau lebih lagu yang telah di-Queue
        // QUESTION,
        dequeue(queueSong, &onPlaySong);
        PushStack(&previousSong, onPlaySong);
        
        printf("\nMemutar lagu selanjutnya\n");
        printf("\"");
        DisplayKata(onPlaySong.titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong.singer);
        printf("\"");
    }
    else {
        onPlaySong = InfoTop(*previousSong);
        printf("\nQueue Kosong, memutar kembali lagu\n");
        printf("\"");
        DisplayKata(onPlaySong.titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong.singer);
        printf("\"");
    }
}
void songPrev (Queue *queueSong, Stack *previousSong){
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
    Song onPlaySong;

    // If stack is empty, then return nothing (terminate early)
    // Else:

    // At this point, stack udah pasti ada isinya (minimal element nya ada satu)
    // Ambil elemen teratas dari stack (tanpa nge-pop
    Stack onQueuePrevious;
    if ((LengthStack(*previousSong)) >= 1){
        PopStack(previousSong, &onPlaySong);
        // enqueue dengan posisi Head
        // // kasus apabila queueSong kosong, maka
        // if (QisEmpty(*queueSong)){
        //     IDX_HEAD(*queueSong) = 0;
        //     IDX_TAIL(*queueSong) = 0;
        // } 
        // else {
        // if (IDX_TAIL(*queueSong)==CAPACITY-1) {
        //     int i;
        //     for (i=IDX_HEAD(*queueSong); i<=CAPACITY-1; i++){
        //         (*queueSong).buffer[i+1-IDX_HEAD(*queueSong)] = (*queueSong).buffer[i];
        //     }
        //     IDX_TAIL(*queueSong) -= (IDX_HEAD(*queueSong)-1);
        //     IDX_HEAD(*queueSong)=0;
        //     }
        //     IDX_TAIL(*queueSong)++;
        // }
        // // Masukan onPlaySong bukan ke TAIL tetapi ke HEAD
        // HEAD(*queueSong) = onPlaySong;
        
        printf("\nMemutar lagu sebelumnya\n");
        printf("\"");
        DisplayKata(onPlaySong.titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong.singer);
        printf("\"");
    }
    else {
        onPlaySong = InfoTop(*previousSong);
        printf("\nRiwayat lagu kosong, memutar kembali lagu\n");
        printf("\"");
        DisplayKata(onPlaySong.titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong.singer);
        printf("\"");
    }
}