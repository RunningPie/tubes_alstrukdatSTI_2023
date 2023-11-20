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

Contoh: Kondisi Riwayat Kosong
Riwayat kosong, memutar kembali lagu
“Mirror” oleh “Yasuda Rei”
*/
    Song onPlaySong;
    Song tempSong;
    if (IsEmptyStack(*previousSong)){
        printf("\nRiwayat lagu kosong, memutar kembali lagu\n");
        printf("\"");
        DisplayKata(onPlaySong.titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong.singer);
        printf("\"");
    }
    else{
        if(QisFull(*queueSong)){
            printf("\nDaftar lagu pada Queue sudah penuh!\n");
        }
        else{
            PopStack(previousSong, &tempSong); // Menyimpan Song Previous di posisi temporary
            enqueueFirst(&queueSong, onPlaySong); // Menyimpan Song yang sedang dimainkan menjadi HEAD DARI QUEUE SONG
            // Mengubah tempSong sebagai onPlaySong
            onPlaySong = tempSong;

            printf("\nMemutar lagu sebelumnya\n");
            printf("\"");
            DisplayKata(onPlaySong.titleSong);
            printf("\" oleh \"");
            DisplayKata(onPlaySong.singer);
            printf("\"");

        }
    }

    // 1. Check if stack is empty -> do nothing (return)
    // 2. Check if queue is full -> print "Queue is full" (return)
    // 3. Set Queue head as current song that is playing
    // 4. Set onPlaySong as previous song from stack pop
    // Done :)

}