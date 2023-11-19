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

void PLAYLISTCREATE(ArrayDin daftarPlaylist)
{
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTWORD();

    int count=0;
    for (int i=0;i<currentWord.Length;i++)
    {
        if (currentWord.TabWord[i] != BLANK)
        {
            count++;
        }
    }

    if (count < 3)
    {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
    }
    else
    {
        LinkedList playlist;
        CreateLinkedList(&playlist);
        InsertAtArrDin (&daftarPlaylist, currentWord, daftarPlaylist.Neff);
        printf("Playlist ");DisplayKata(currentWord);printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
    }
}

void PLAYLISTADDSONG(List daftarPenyanyi,ArrayDin daftarPlaylist, Map *penyanyiAlbum, Map *albumLagu)
{
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

        printf("Masukkan Judul Album yang dipilih : ");
        STARTWORD();
        printf("\n");
        Word album = currentWord;
        if(IsSetMember(MapValue(*penyanyiAlbum,penyanyi),album))
        {
            printf("Daftar Lagu Album ");DisplayKata(album);printf(" oleh ");DisplayKata(penyanyi);printf(" :\n");
            DisplayVMap(*penyanyiAlbum,album);printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            STARTWORD();
            printf("\n");

            int idLagu =WordToInt(currentWord)-1;
            if (IsIdxValidSet(MapValue(*albumLagu,album),idLagu))
            {
                Word lagu;
                SalinKata(MapValue(*albumLagu,album).Elements[idLagu],&lagu);
                printf("Daftar Playlist Pengguna :\n");
                PrintArrayDin(daftarPlaylist);
                printf("\n");

                printf("Masukkan ID Playlist yang dipilih : ");
                STARTWORD();
                printf("\n");

                int idPlaylist =WordToInt(currentWord)-1;
                if (IsIdxValidArrDin(daftarPlaylist,idPlaylist))
                {
                    Word playlist;
                    Desc d;
                    SalinKata(daftarPlaylist.A[idPlaylist],&playlist);
                    CreateDesc(&d,penyanyi,album,lagu);
                    //Insert lagu ke playlist yang ada di daftar playlist
                    // LinkedListInsertAt(&daftarPlaylist,d,LinkedListLength(daftarPlaylist.TabWord[idPlaylist]));
                    // belum bisa dibenerin, liat dulu cara penyimpanan playlist di comamnd "LIST PLAYLIST"
                    printf("Lagu dengan judul “");DisplayKata(lagu);printf("” pada album ");DisplayKata(album);printf(" oleh penyanyi \n");
                    DisplayKata(penyanyi);printf(" berhasil ditambahkan ke dalam playlist ");DisplayKata(playlist);printf(".\n");
                }
                else 
                {
                    printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", idPlaylist + 1);
                }
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

void PLAYLISTADDALBUM(List daftarPenyanyi, Map *penyanyiAlbum, ArrayDin daftarPlaylist, Map *albumLagu)
{
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

        printf("Masukkan Judul Album yang dipilih : ");
        STARTWORD();
        printf("\n");
        Word album = currentWord;

        if(IsSetMember(MapValue(*penyanyiAlbum,penyanyi),album))
        {
            printf("Daftar Playlist Pengguna :\n");
            PrintArrayDin(daftarPlaylist);
            printf("\n");

            printf("Masukkan ID Playlist yang dipilih : ");
            STARTWORD();
            printf("\n");

            int idPlaylist =WordToInt(currentWord)-1;
            if (IsIdxValidArrDin(daftarPlaylist,idPlaylist))
            {
                Word playlist;
                Desc d;
                SalinKata(GetArrDin(daftarPlaylist, idPlaylist),&playlist);

                Word lagu;
                for(int i=0;i<MapValue(*albumLagu,album).Count;i++)
                {
                    SalinKata(MapValue(*albumLagu,album).Elements[i],&lagu);
                    CreateDesc(&d,penyanyi,album,lagu);
                    // LinkedListInsertAt((&daftarPlaylist).TabWord[idPlaylist],d,LinkedListLength(daftarPlaylist.TabWord[idPlaylist]));
                    // cek komen line 122
                }
                printf("Album dengan judul “");DisplayKata(album);printf("” berhasil ditambahkan ke dalam playlist pengguna “");
                DisplayKata(playlist);printf("”.\n");
            }
            else
            {
                printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", idPlaylist + 1);
            }            
        } 
        else 
        {
            printf("Album ");DisplayKata(album); printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }       
    }
    else
    {
        printf("Penyanyi ");DisplayKata(penyanyi); printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}

void PLAYLISTSWAP(List daftarPenyanyi, Map *penyanyiAlbum, ArrayDin daftarPlaylist, Map *albumLagu)
{
    int id,x,y;
    ADVWORD();
    id=WordToInt(currentWord)-1;
    ADVWORD();
    x=WordToInt(currentWord)-1;
    ADVWORD();
    y=WordToInt(currentWord)-1;

    if (id<0 || id>=daftarPlaylist.Neff)
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", id+1);
        return;
    }
    else
    {
        LinkedList playlist; //= (daftarPlaylist.A[id])->TabWord;
        if (x<0 || x>=LinkedListLength(playlist) || y<0 || y>=LinkedListLength(playlist))
        {
            printf("Tidak ada lagu dengan urutan %d atau %d di playlist\n", x+1, y+1);
        }
        else 
        {
            LinkedListEl tempx,tempy;
            tempx = getElmt(playlist,x);  
            tempy = getElmt(playlist,y);
            setElmt(&playlist,tempy,x);
            setElmt(&playlist,tempx,y);

            printf("Berhasil menukar lagu dengan nama “");DisplayKata(tempx.Lagu);printf("” dengan “");DisplayKata(tempy.Lagu);
            printf("” di playlist “");DisplayKata((daftarPlaylist.A[id]));
        }
    }
}

void PLAYLISTREMOVE(List daftarPenyanyi, Map *penyanyiAlbum, ArrayDin daftarPlaylist, Map *albumLagu)
{
    int id,n;
    ADVWORD();
    id=WordToInt(currentWord)-1;
    ADVWORD();
    n=WordToInt(currentWord)-1;

    if (id<0 || id>=daftarPlaylist.Neff)
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", id+1);
    }
    else
    {
        LinkedList playlist;// = daftarPlaylist.TabWord[id];
        if (n<0 || n>=LinkedListLength(playlist))
        {
            printf("Tidak ada lagu dengan urutan %d di playlist\n", n+1);
        }
        else 
        {
            LinkedListEl lagu;
            LinkedListDeleteAt(&playlist,n,&lagu);

            printf("Lagu “");DisplayKata(lagu.Lagu);printf("” oleh “");DisplayKata(lagu.Penyanyi);
            // printf("” telah dihapus dari playlist “");DisplayKata((playlist));printf("”!\n");
        }
    }
}

void PLAYLISTDELETE(List daftarPenyanyi, Map *penyanyiAlbum, ArrayDin daftarPlaylist, Map *albumLagu)
{
    printf("Daftar Playlist Pengguna :\n");
    PrintArrayDin(daftarPlaylist);
    printf("\n");

    printf("Masukkan ID Playlist yang dipilih : ");
    STARTWORD();
    printf("\n");

    int id =WordToInt(currentWord)-1;
    if (id<0 || id>=daftarPlaylist.Neff)
    {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", id+1);
    }
    else
    {
        ElType playlist;
        playlist=GetArrDin(daftarPlaylist,id);
        DeleteAtArrDin(&daftarPlaylist,id);

        printf("Playlist ID %d dengan judul ”", id+1);DisplayKata(playlist);printf("” berhasil dihapus.\n");
    }
}

void STATUS()
{
    Desc tempL = currentL;
    if(IsEmptyDesc(currentL))
    {
        printf("Now Playing :\nNo songs have been played yet. Please search for a song to begin playback.\n");
    }
    else 
    {
        printf("Now Playing :\n%s - %s - %s\n\n", tempL.Penyanyi.TabWord, tempL.Lagu.TabWord, tempL.Album.TabWord);
    }

    int index=1;
    printf("Queue : \n");
    Queue newL = QueueL;
    while(!QisEmpty(newL) && !QisEmpty(QueueL))
    {
        dequeue(&newL,&tempL);
        printf("%d. %s - %s - %s\n",index, tempL.Penyanyi.TabWord, tempL.Lagu.TabWord, tempL.Album.TabWord);
        index++;
    }
    if (QisEmpty(QueueL))
    {
        printf("Your queue is empty.\n");
    }
    START();
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