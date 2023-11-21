#include "console.h"


void STARTWAYANGWAVE(List *daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu) {

    int Npenyanyi, Nalbum, Nlagu;
    Word penyanyi, album, lagu;
    Set Salbum, Slagu;
    CreateEmptySet(&Salbum);
    CreateEmptySet(&Slagu);

    STARTWORDFILE("data/config.txt");

    Npenyanyi = WordToInt(currentWord);

    for (int i = 0; i < Npenyanyi; i++) {
        ADVWORD();
        Nalbum = WordToInt(currentWord);

        ADVSENTENCE();
        penyanyi = currentWord;
        ListInsertLast(daftarPenyanyi, penyanyi);

        for (int j = 0; j < Nalbum; j++) {
            ADVWORD();
            Nlagu = WordToInt(currentWord);

            ADVSENTENCE();
            album = currentWord;
            SetInsert(&Salbum, album);

            for (int k = 0; k < Nlagu; k++) {
                ADVSENTENCE();
                lagu = currentWord;
                SetInsert(&Slagu, lagu);
            }
            MapInsert(albumLagu, album, Slagu);
            CreateEmptySet(&Slagu);
        }
        MapInsert(penyanyiAlbum, penyanyi, Salbum);
        CreateEmptySet(&Salbum);
    }
}


void LOAD(String filename)
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
//         Jika save file bernama <filename> tidak ditemukan
//         Tuliskan pesan kegagalan pada layar. Program tidak memasuki sesi.
{

}

void SAVE(String filename)
/*
SAVE merupakan command yang digunakan untuk menyimpan state aplikasi terbaru ke dalam suatu file.
Command SAVE memiliki satu argumen yang merepresentasikan nama file yang akan disimpan.
Penyimpanan dilakukan pada folder tertentu, misal folder save.
*/
// I.S. Sembarang dalam sesi
// F.S. Terbentuk suatu file bernama <filename> di folder save.
{

}

// BAGIAN SONG: (1) songNext, (2) songPrev

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
        PushStack(&previousSong, *onPlaySong);
        
        printf("\nMemutar lagu selanjutnya\n");
        printf("\"");
        DisplayKata(onPlaySong->titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong->singer);
        printf("\"\n");
    }
    else {
        *onPlaySong = InfoTop(*previousSong);
        printf("\nQueue kosong, memutar kembali lagu\n");
        printf("\"");
        DisplayKata(onPlaySong->titleSong);
        printf("\" oleh \"");
        DisplayKata(onPlaySong->singer);
        printf("\"\n");
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
        printf("\"\n");
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
            printf("\"\n");

        }
    }
}

// BAGIAN QUEUE: (1) Queue Song, (2) Queue Playlist, (3) Queue Swap, (4) Queue Remove, (5) Queue Clear

void enqueueSong(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu, Queue *queueSong) {
/*
Proses: Procedure yang digunakan untuk menambahkan lagu ke dalam queue. Procedure ini akan menerima tiga input, pertama Nama dari Penyanyi, kedua Nama dari Album yang dipilih, dan ketiga ID Lagu yang dipilih. ID Lagu tersebut sebagai key dari lagu yang akan di queue.  
I.S.: Queue kosong atau queue berisi lagu yang sebelumnya telah di queue
F.S.: Queue berisi satu lagu atau queue telah ditambahkan dengan masukan lagu yang baru (Isi queue minimal satu lagu) pada posisi TAIL queue
*/
    printf("Daftar Penyanyi :\n");
    DisplayList(daftarPenyanyi);
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTWORD();
    printf("\n");
    Word penyanyi = currentWord;

    if (ListSearch(daftarPenyanyi,penyanyi))
    {
        printf("Daftar Album oleh ");DisplayKata(penyanyi);printf(" :\n");
        DisplayVMap(*penyanyiAlbum,penyanyi);printf("\n");

        printf("Masukkan Nama Album yang dipilih : ");
        STARTWORD();
        printf("\n");
        Word album = currentWord;
        if(IsSetMember(MapValue(*penyanyiAlbum, penyanyi), album))
        {
            printf("Daftar Lagu Album ");DisplayKata(album);printf(" oleh ");DisplayKata(penyanyi);printf(" :\n");
            DisplayVMap(*penyanyiAlbum, album);printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            STARTWORD();
            printf("\n");

            int idLagu =WordToInt(currentWord)-1;
            if (IsIdxValidSet(MapValue(*albumLagu, album), idLagu))
            {
                Word namaLagu = MapValue(*albumLagu, album).Elements[idLagu];
                Song lagu = createSong(namaLagu, album, penyanyi);
                enqueue(queueSong, lagu);

                printf("Berhasil menambahkan lagu \"");
                DisplayKata(namaLagu);
                printf("\" oleh \"");
                DisplayKata(penyanyi);
                printf("\" ke queue.\n");
            }
            else 
            {
                printf("ID Lagu %d tidak ada dalam daftar. Silakan coba lagi.\n", idLagu + 1);
            }
        }
        else
        {
            printf("Album ");DisplayKata(album);printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
    else
    {
        printf("Penyanyi ");DisplayKata(penyanyi);printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}

void queuePlaylist(Queue *queueSong, ArrayDin daftarPlaylist) {
/*
Proses: Procedure yang digunakan untuk menambahkan seluruh lagu yang ada dalam playlist yang dimasukkan ke dalam queue. Procedure ini akan menetima satu input, yaitu ID dari playlist. 
I.S.: Queue kosong atau queue berisi lagu yang sebelumnya telah di queue
F.S.: Queue berisi satu atau lebih lagu yang di queue dari suatu playlist yang dimasukkan. Proses memasukkan lagu dimulai dari lagu pertama dari PLAYLIST dan dimasukkan pada posisi TAIL queue
*/
    if (QisFull(*queueSong)) {
        printf("\nQueue penuh! Lagu dapat di-queue ketika tidak melalui maksimal queue.\n");
        return;
    }
    
    // for (int i = 0; i < LengthArrDin(daftarPlaylist); i++) {
    //     enqueue(daftarPlaylist.A[i]);
    // }

}

void queueSwap(Queue *queueSong, int x, int y) {
/*
Proses: Procedure yang digunakan untuk menukar lagu pada urutan ke-x dan urutan ke-y. Input pada Command ini adalah dua id lagu (x, y). 
I.S.: Posisi lagu dengan id x dan posisi lagu dengan id y tetap berdasarkan urutan queue sebelumnya atau salah satu dari x atau y tidak terdefinisi 
F.S.: Posisi lagu dengan id x berada di posisi lagu dengan id y, serta posisi lagu dengan id y berada di posisi lagu dengan id x (Swapping telah dilakukan) apabila x dan y terdefinisi 
*/
    // Cek  if x or y is out of bounds
    if (x + IDX_HEAD(*queueSong) > IDX_TAIL(*queueSong) || y + IDX_HEAD(*queueSong) > IDX_TAIL(*queueSong) || x < 0 || y < 0) {
        if  (x + IDX_HEAD(*queueSong) > IDX_TAIL(*queueSong) || x < 0){
            printf("\nLagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        }
        else{
            printf("\nLagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
        }
        return;
    }
    // Begin the swap
    Song temp;
    temp = queueSong->buffer[x];
    queueSong->buffer[x] = queueSong->buffer[y];
    queueSong->buffer[y] = temp;

    printf("\nLagu ");
    printf("\"");
    DisplayKata(queueSong->buffer[x].titleSong);
    printf("\" ");
    printf("berhasil ditukar dengan ");
    printf("\" ");
    DisplayKata(queueSong->buffer[y].titleSong);
    printf("\"\n");
    return;
}

void queueRemove(Queue *queueSong, int id) {
/*
Proses: Procedure yang digunakan untuk menghapus lagu dari queue berdasarkan id yang dimasukkan. Input pada Command ini adalah id lagu (id) yang ingin dihapus dari queue
I.S.: Terdapat lagu (berdasarkan id yang dimasukkan) pada queue atau id yang dimasukkan tidak terdefinisi 
F.S.: Lagu (id) dihapus dari queue apabila id terdefinisi   
*/
    if (id > Qlength(*queueSong) || id < 0) {
        printf("\nLagu dengan urutan ke %d tidak ada\n", id);
    }

    int ctr = 1;
    for (int i = IDX_HEAD(*queueSong); i <= IDX_TAIL(*queueSong); i++) {
        if (ctr == id) {
            Song foundSong = queueSong->buffer[i];
            for (int j = i; j < IDX_TAIL(*queueSong); j++) {
                queueSong->buffer[j] = queueSong->buffer[j+1];
            }

            queueSong->idxTail = queueSong->idxTail - 1;

            printf("\nLagu ");
            printf("\"");
            DisplayKata(queueSong->buffer[id].titleSong);
            printf("\" ");
            printf("oleh ");
            printf("\" ");
            DisplayKata(queueSong->buffer[id].singer);
            printf("\" telah dihapus dari queue!\n");
            return;
        }
        ctr++;
    }
}

void queueClear(Queue *queueSong) {
/*
Proses: Procedure yang digunakan untuk mengosongkan queue.
I.S.: Queue berisi lagu yang telah di-queue sebelumnya
F.S.: Queue kosong atau tidak berisi lagu 
*/
    Song temp;
    while (!QisEmpty(*queueSong)){
        dequeue(queueSong, &temp);
    }
    printf("\nQueue berhasil dikosongkan.\n");
}

void QUIT()
// QUIT merupakan command yang digunakan untuk keluar dari sesi aplikasi WayangWave.
// I.S. Sembarang dalam sesi
// F.S. Keluar dari sesi. Jika data sesi disimpan maka terbentuk suatu file bernama <filename> di folder save.
{
    char shouldSave = '0';
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    STARTWORD();
    if (currentWord.TabWord[0] == 'Y') {
        printf("Masukkan nama file untuk penyimpanan: ");
        STARTWORD();

        String file;
        file.length = currentWord.Length;

        int i;
        for (i=0; i<currentWord.Length; i++){
            file.content[i] = currentWord.TabWord[i];
        }

        SAVE(file);
    } else {
        printf("Kamu keluar dari WayangWave.\n");
        printf("Dadah ^_^/\n");
    }
}