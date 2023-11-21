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
    STARTWORD();
    if (isWordEq(currentWord, ToKata("LIST"))) {
        ADVWORD();
        if (isWordEq(currentWord, ToKata("DEFAULT"))) {

        } else if (isWordEq(currentWord, ToKata("PLAYLIST"))) {

        }
    } else if (isWordEq(currentWord, ToKata("PLAY"))) {
        ADVWORD();
        if (isWordEq(currentWord, ToKata("SONG"))) {

        } else if (isWordEq(currentWord, ToKata("PLAYLIST"))) {

        }
    } else if (isWordEq(currentWord, ToKata("QUEUE"))) {
        ADVWORD();
        if (isWordEq(currentWord, ToKata("SONG"))) {

        } else if (isWordEq(currentWord, ToKata("PLAYLIST"))) {

        } else if (isWordEq(currentWord, ToKata("SWAP"))) {

        } else if (isWordEq(currentWord, ToKata("REMOVE"))) {

        } else if (isWordEq(currentWord, ToKata("CLEAR"))) {

        }
    } else if (isWordEq(currentWord, ToKata("SONG"))) {
        ADVWORD();
        if (isWordEq(currentWord, ToKata("NEXT"))) {

        } else if (isWordEq(currentWord, ToKata("PREVIOUS"))) {

        }
    } else if (isWordEq(currentWord, ToKata("PLAYLIST"))) {
        ADVWORD();
        if (isWordEq(currentWord, ToKata("CREATE"))) {

        } else if (isWordEq(currentWord, ToKata("ADD"))) {

        } else if (isWordEq(currentWord, ToKata("SWAP"))) {

        } else if (isWordEq(currentWord, ToKata("REMOVE"))) {

        } else if (isWordEq(currentWord, ToKata("DELETE"))) {

        }
    } else if (isWordEq(currentWord, ToKata("STATUS"))) {

    } else if (isWordEq(currentWord, ToKata("SAVE"))) {
        ADVSENTENCE();
    } else if (isWordEq(currentWord, ToKata("QUIT"))) {
        QUIT();
        *stateWayang = false;
    } else if (isWordEq(currentWord, ToKata("HELP"))) {

    } else if (isWordEq(currentWord, ToKata("START")) || isWordEq(currentWord, ToKata("LOAD"))) {
        printf("Command tidak bisa dieksekusi!\n");
    } else {
        printf("Command tidak diketahui!\n");
    }
}
// fungsi untuk main
