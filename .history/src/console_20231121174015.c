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
    printf("\nFile konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
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

void menuLIST(boolean *stateWayang) {
    STARTSENTENCE();
    if (isWordEq(SenToWord(currentWord, 0), ToKata("LIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("DEFAULT"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("LIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAY")) && isWordEq(SenToWord(currentWord, 1), ToKata("SONG"))) {
        
    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAY")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("SONG"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("SWAP"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("REMOVE"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("CLEAR"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SONG")) && isWordEq(SenToWord(currentWord, 1), ToKata("NEXT"))) {
       
    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SONG")) && isWordEq(SenToWord(currentWord, 1), ToKata("PREVIOUS"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("CREATE"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("ADD"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("SWAP"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("REMOVE"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("DELETE"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("STATUS"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SAVE"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUIT"))) {
        QUIT();
        *stateWayang = false;
    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("HELP"))) {

    } else if (isWordEq(SenToWord(currentWord, 0), ToKata("START")) || isWordEq(SenToWord(currentWord, 0), ToKata("LOAD"))) {
        printf("\nCommand tidak bisa dieksekusi!\n");
    } else {
        printf("\nCommand tidak diketahui!\n");
    }
}
// fungsi untuk main
