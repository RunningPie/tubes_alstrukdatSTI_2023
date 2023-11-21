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

void LISTDEFAULT(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu) {
    printf("Daftar Penyanyi :\n");
    DisplayList(daftarPenyanyi);
    printf("\n");

    printf("Ingin melihat album yang ada? (Y/N): ");
    STARTWORD();
    printf("\n");

    if (currentWord.TabWord[0] == 'Y') {
        printf("Pilih penyanyi untuk melihat album mereka: ");
        STARTWORD();
        printf("\n");
        Word penyanyi = currentWord;

        if (ListSearch(daftarPenyanyi, penyanyi)) {
            printf("Daftar Album oleh ");
            DisplayKata(penyanyi);
            printf(" :\n");
            DisplayVMap(*penyanyiAlbum, penyanyi);
            printf("\n");

            printf("Ingin melihat lagu yang ada? (Y/N): ");
            STARTWORD();
            printf("\n");

            if (currentWord.TabWord[0] == 'Y') {
                printf("Pilih album untuk melihat lagu yang ada di album: ");
                STARTWORD();
                printf("\n");
                Word album = currentWord;

                if (IsSetMember(MapValue(*penyanyiAlbum, penyanyi), album)) {
                    printf("Daftar Lagu di ");
                    DisplayKata(album);
                    printf(":\n");
                    DisplayVMap(*albumLagu, album);
                    printf("\n");
                } 
                else {
                    printf("Album ");
                    DisplayKata(album);
                    printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
                }
            }
        } 
        else {
            printf("Penyanyi ");
            DisplayKata(penyanyi);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
}

void LISTPLAYLIST(ArrayDin daftarPlaylist) {
    printf("Daftar playlist yang kamu miliki:\n");

    if (ArrayDinIsEmpty(daftarPlaylist)) {
        printf("Kamu tidak memiliki playlist.\n");
    } 
    else {
        PrintArrayDin(daftarPlaylist);
    }
}

void PLAYSONG(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu, Queue *queueSong, Stack *historySong) {
    printf("Daftar Penyanyi :\n");
    DisplayList(daftarPenyanyi);
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTWORD();
    printf("\n");
    Word penyanyi = currentWord;

    if (ListSearch(daftarPenyanyi, penyanyi)) {
        printf("Daftar Album oleh ");
        DisplayKata(penyanyi);
        printf(" :\n");
        DisplayVMap(*penyanyiAlbum, penyanyi);
        printf("\n");

        printf("Masukkan Nama Album yang dipilih : ");
        STARTWORD();
        printf("\n");
        Word album = currentWord;
        if (IsSetMember(MapValue(*penyanyiAlbum, penyanyi), album)) {
            printf("Daftar Lagu Album ");
            DisplayKata(album);
            printf(" oleh ");
            DisplayKata(penyanyi);
            printf(" :\n");
            DisplayVMap(*penyanyiAlbum, album);
            printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            STARTWORD();
            printf("\n");

            int idLagu = WordToInt(currentWord) - 1;
            if (IsIdxValidSet(MapValue(*albumLagu, album), idLagu)) {
                Song lagu = createSong(MapValue(*albumLagu, album).Elements[idLagu], album, penyanyi);

                // Clear queue dan history
                QueueClear(queueSong);
                StackClear(historySong);

                printf("Memutar lagu \"");
                DisplayKata(lagu.titleSong);
                printf("\" oleh \"");
                DisplayKata(lagu.singer);
                printf("\".\n");
            } else {
                printf("ID Lagu %d tidak ada dalam daftar. Silakan coba lagi.\n", idLagu + 1);
            }
        } else {
            printf("Album ");
            DisplayKata(album);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    } else {
        printf("Penyanyi ");
        DisplayKata(penyanyi);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}

void PLAYPLAYLIST(ArrayDin daftarPlaylist, Queue *queueSong, Stack *historySong) {
    printf("Daftar Playlist Pengguna :\n");
    PrintArrayDin(daftarPlaylist);
    printf("\n");

    printf("Masukkan ID Playlist yang dipilih : ");
    STARTWORD();
    printf("\n");

    int idPlaylist = WordToInt(currentWord) - 1;
    if (IsIdxValidArrDin(daftarPlaylist, idPlaylist)) {
        LinkedList playlist;

        // LinkedList = daftarPlaylist.TabWord[idPlaylist]

        if (!LinkedListIsEmpty(playlist)) {
            // Clear queue dan history
            QueueClear(queueSong);
            StackClear(historySong);

            // Enqueue semua lagu dari playlist yang dipilih
            LinkedListEl currentSong = playlist.First;
            while (currentSong != NULL) {
                enqueue(queueSong, currentSong.Value);
                PushStack(historySong, currentSong.Value);
                currentSong = currentSong.Next;
            }

            printf("Memutar playlist \"");
            DisplayKata(daftarPlaylist.A[idPlaylist]);
            printf("\".\n");
        } else {
            printf("Playlist kosong. Tidak ada lagu yang dapat diputar.\n");
        }
    } else {
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", idPlaylist + 1);
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