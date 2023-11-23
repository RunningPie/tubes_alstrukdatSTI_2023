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

void LOAD(Word filename)
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

void LISTDEFAULT(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu) {
    printf("Daftar Penyanyi :\n");
    DisplayList(daftarPenyanyi);
    printf("\n");

    printf("Ingin melihat album yang ada? (Y/N): ");
    STARTWORD();
    printf("\n");

    if (currentWord.TabWord[0] == 'Y') {
        printf("Pilih penyanyi untuk melihat album mereka: ");
        STARTSENTENCE();
        printf("\n");
        Word penyanyi = currentWord;

        // DisplayList(daftarPenyanyi);
        // // printf("List Last Idx: %d\n", ListLastIdx(daftarPenyanyi));
        // DisplayKata(daftarPenyanyi.A[0]);
        // DisplayKata(penyanyi);
        
        // printf("%s == %s? %u (LINE 81)\n", daftarPenyanyi.A[0].TabWord[0], penyanyi.TabWord[0], isWordEq(daftarPenyanyi.A[0], penyanyi));

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
                STARTSENTENCE();
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

    if (IsEmptyArrDin(daftarPlaylist)) {
        printf("Kamu tidak memiliki playlist.\n");
    } 
    else {
        PrintArrayDin(daftarPlaylist);
    }
}

void PLAYSONG(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu, Queue *QueueL, Stack *historyL, Song *currentSong){
    printf("Daftar Penyanyi :\n");
    DisplayList(daftarPenyanyi);
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTSENTENCE();
    printf("\n");
    Word penyanyi = currentWord;

    if (ListSearch(daftarPenyanyi, penyanyi)) {
        printf("Daftar Album oleh ");
        DisplayKata(penyanyi);
        printf(" :\n");
        DisplayVMap(*penyanyiAlbum, penyanyi);
        printf("\n");

        printf("Masukkan Nama Album yang dipilih : ");
        STARTSENTENCE();
        printf("\n");
        Word album = currentWord;

        if (IsSetMember(MapValue(*penyanyiAlbum, penyanyi), album)) {
            printf("Daftar Lagu Album ");
            DisplayKata(album);
            printf(" oleh ");
            DisplayKata(penyanyi);
            printf(" :\n");
            DisplayVMap(*albumLagu, album);
            printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            STARTWORD();
            printf("\n");

            int idLagu = WordToInt(currentWord) - 1;
            if (IsIdxValidSet(MapValue(*albumLagu, album), idLagu)) {
                Word lagu;
                SalinKata(MapValue(*albumLagu, album).Elements[idLagu], &lagu);
                
                // Memutar lagu
                // SalinKata(penyanyi, &currentSong->Penyanyi);
                // SalinKata(album, &currentSong->Album);
                // SalinKata(lagu, &currentSong->Lagu);

                // Memasukkan lagu ke queue
                // enqueue(QueueL, currentSong);
// /N /R/N
                // Menambahkan lagu ke dalam history (stack)
                // PushStack(historyL, currentSong);
                // CreateQueue(QueueL);
                // CreateEmptyStack(historyL);

                printf("Memutar lagu \"");

                DisplayKata(lagu);
                printf("\" oleh \"");
                DisplayKata(penyanyi);
                printf("\".\n");
                SalinKata(penyanyi, &(*currentSong).Penyanyi);
                SalinKata(album, &(*currentSong).Album);
                SalinKata(lagu, &(*currentSong).Lagu);

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

void PLAYPLAYLIST(ArrayDin daftarPlaylist, Map *playlistSongs, Queue *QueueL, Stack *historyL, Song *onPlaySong) {
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
            CreateQueue(QueueL);
            CreateEmptyStack(historyL);

            // Enqueue semua lagu dari playlist yang dipilih
            *onPlaySong = playlist.first->info;
            Address currentSong = playlist.first;
            while (currentSong != NULL) {
                enqueue(QueueL, currentSong->info);
                PushStack(historyL, currentSong->info);
                currentSong = currentSong->next;
            }

            printf("Memutar playlist \"");
            DisplayKata(daftarPlaylist.A[idPlaylist].namaPlaylist);
            printf("\".\n");
        } else {
            printf("Playlist kosong. Tidak ada lagu yang dapat diputar.\n");
        }
    } else {
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", idPlaylist + 1);
    }
}


void PLAYLISTCREATE(ArrayDin *daftarPlaylist)
{
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTSENTENCE();

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
        ArrDinEl newPlaylist;
        newPlaylist = CreateArrDinEl(currentWord);
        InsertAtArrDin (daftarPlaylist, newPlaylist, daftarPlaylist->Neff);
        printf("Playlist ");DisplayKata(currentWord);printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
    }
}

void PLAYLISTADDSONG(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map *penyanyiAlbum, Map *albumLagu)
{
    printf("Daftar Penyanyi :\n");
    DisplayList(daftarPenyanyi);
    printf("\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTSENTENCE();
    printf("\n");
    Word penyanyi = currentWord;

    if (ListSearch(daftarPenyanyi,penyanyi))
    {
        printf("Daftar Album oleh ");DisplayKata(penyanyi);printf(" :\n");
        DisplayVMap(*penyanyiAlbum,penyanyi);printf("\n");

        printf("Masukkan Judul Album yang dipilih : ");
        STARTSENTENCE();
        printf("\n");
        Word album = currentWord;
        if(IsSetMember(MapValue(*penyanyiAlbum,penyanyi),album))
        {
            printf("Daftar Lagu Album ");DisplayKata(album);printf(" oleh ");DisplayKata(penyanyi);printf(" :\n");
            DisplayVMap(*albumLagu,album);printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            STARTWORD();
            printf("\n");

            int idLagu =WordToInt(currentWord)-1;
            if (IsIdxValidSet(MapValue(*albumLagu,album),idLagu))
            {
                Word lagu;
                SalinKata(MapValue(*albumLagu,album).Elements[idLagu],&lagu);
                printf("Daftar Playlist Pengguna :\n");
                PrintArrayDin(*daftarPlaylist);
                printf("\n");

                printf("Masukkan ID Playlist yang dipilih : ");
                STARTWORD();
                printf("\n");

                int idPlaylist =WordToInt(currentWord)-1;
                if (IsIdxValidArrDin(*daftarPlaylist,idPlaylist))
                {
                    Word namaPlaylist;
                    Song d;
                    LinkedList * playlist = &(daftarPlaylist->A[idPlaylist].pLinkedList);
                    // LinkedList ABC;
                    // CreateLinkedList(&ABC);
                    printf("Length: %d\n", LinkedListLength(*playlist));

                    SalinKata(daftarPlaylist->A[idPlaylist].namaPlaylist,&namaPlaylist);
                    CreateSong(&d, penyanyi, album, lagu);
                    // DisplaySong(d);
                    //Insert lagu ke playlist yang ada di daftar playlist
                    // printf("ok\n");

                    // printf("Panjang list: %d\n", LinkedListLength());
                    LinkedListInsertLast(playlist, d);
                    // belum bisa dibenerin, liat dulu cara penyimpanan playlist di comamnd "LIST PLAYLIST"
                    printf("Lagu dengan judul \"");DisplayKata(lagu);printf("\" pada album ");DisplayKata(album);printf(" oleh penyanyi \n");
                    DisplayKata(penyanyi);printf(" berhasil ditambahkan ke dalam playlist ");DisplayKata(namaPlaylist);printf(".\n");

                    printf("Length: %d\n", LinkedListLength(*playlist));
                    LinkedListDisplay(*playlist);
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

void PLAYLISTADDALBUM(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu)
{
    printf("Daftar Penyanyi :\n");
    DisplayList(daftarPenyanyi);
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTSENTENCE();
    printf("\n");
    Word penyanyi = currentWord;
    if (ListSearch(daftarPenyanyi,penyanyi))
    {
        printf("Daftar Album oleh ");DisplayKata(penyanyi);printf(" :\n");
        DisplayVMap(penyanyiAlbum,penyanyi);printf("\n");

        printf("Masukkan Judul Album yang dipilih : ");
        STARTSENTENCE();
        printf("\n");
        Word album = currentWord;
      
        if(IsSetMember(MapValue(penyanyiAlbum,penyanyi),album))
        {
            printf("Daftar Playlist Pengguna :\n");
            PrintArrayDin(*daftarPlaylist);
            printf("\n");

            printf("Masukkan ID Playlist yang dipilih : ");
            STARTWORD();
            printf("\n");

            int idPlaylist =WordToInt(currentWord)-1;
            if (IsIdxValidArrDin(*daftarPlaylist,idPlaylist))
            {
                Word playlist;
                Song d;
                SalinKata(GetArrDin(*daftarPlaylist, idPlaylist).namaPlaylist,&playlist);

                Word lagu;
                for(int i=0;i<MapValue(albumLagu,album).Count;i++)
                {
                    SalinKata(MapValue(albumLagu,album).Elements[i],&lagu);
                    CreateSong(&d,penyanyi,album,lagu);
                    LinkedListInsertLast(&(daftarPlaylist->A[idPlaylist].pLinkedList),d);
                    // cek komen line 122
                }
                printf("Album dengan judul \"");DisplayKata(album);printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
                DisplayKata(playlist);printf("\".\n");
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

void PLAYLISTSWAP(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu, int id, int x, int y)
{
    id -= 1;
    x -= 1;
    y -= 1;

    if (id<0 || id>=daftarPlaylist->Neff)
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", id+1);
        return;
    }
    else
    {
        LinkedList playlist = (*daftarPlaylist).A[id].pLinkedList;
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

            printf("Berhasil menukar lagu dengan nama ");DisplayKata(tempx.Lagu);printf(" dengan ");DisplayKata(tempy.Lagu);
            printf(" di playlist ");DisplayKata((daftarPlaylist->A[id].namaPlaylist));
        }
    }
}

void PLAYLISTREMOVE(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu, int id, int n)
{
    id -= 1;
    n -= 1;

    if (id<0 || id>=daftarPlaylist->Neff)
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", id+1);
    }
    else
    {
        LinkedList playlist = (*daftarPlaylist).A[id].pLinkedList;
        // CreateLinkedList(&playlist);
        if (n<0 || n>=LinkedListLength(playlist))
        {
            printf("Tidak ada lagu dengan urutan %d di playlist\n", n+1);
        }
        else 
        {
            LinkedListEl lagu;
            LinkedListDeleteAt(&playlist,&lagu,n);
            // printf("ok\n");

            printf("Lagu \"");DisplayKata(lagu.Lagu);printf("\" oleh \"");DisplayKata(lagu.Penyanyi);
            printf("” telah dihapus dari playlist “");DisplayKata(((daftarPlaylist->A)[id].namaPlaylist));printf("”!\n");
        }
    }
}

void PLAYLISTDELETE(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu)
{
    printf("Daftar Playlist Pengguna :\n");
    PrintArrayDin(*daftarPlaylist);
    printf("\n");

    printf("Masukkan ID Playlist yang dipilih : ");
    STARTWORD();
    printf("\n");

    int id =WordToInt(currentWord)-1;
    if (id<0 || id>=daftarPlaylist->Neff)
    {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", id+1);
    }
    else
    {
        ArrDinEl playlist;
        playlist=GetArrDin(*daftarPlaylist,id);
        DeleteAtArrDin(daftarPlaylist,id);

        printf("Playlist ID %d dengan judul \"", id+1);DisplayKata(playlist.namaPlaylist);printf("\" berhasil dihapus.\n");
    }
}

void STATUS(Song currentL, Queue QueueL)
{
    Song tempL = currentL;
    if(IsEmptySong(currentL))
    {
        printf("\nNow Playing :\nNo songs have been played yet. Please search for a song to begin playback.\n");
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
        PushStack(previousSong, *onPlaySong);
        dequeue(queueSong, onPlaySong);
        
        printf("\nMemutar lagu selanjutnya\n");
        printf("\"");
        DisplayKata(onPlaySong->Lagu);
        printf("\" oleh \"");
        DisplayKata(onPlaySong->Penyanyi);
        printf("\"\n");
    }
    else {
        PushStack(previousSong, *onPlaySong);
        *onPlaySong = InfoTop(*previousSong);
        printf("\nQueue kosong, memutar kembali lagu\n");
        printf("\"");
        DisplayKata(onPlaySong->Lagu);
        printf("\" oleh \"");
        DisplayKata(onPlaySong->Penyanyi);
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
        DisplayKata(onPlaySong->Lagu);
        printf("\" oleh \"");
        DisplayKata(onPlaySong->Penyanyi);
        printf("\"\n");
    }
    else{
        if(QisFull(*queueSong)){
            printf("\nDaftar lagu pada Queue sudah penuh!\n");
        }
        else{
            PopStack(previousSong, &tempSong); // Menyimpan Song Previous di posisi temporary
            *onPlaySong = InfoTop(*previousSong);
            enqueueFirst(queueSong, *onPlaySong); // Menyimpan Song yang sedang dimainkan menjadi HEAD DARI QUEUE SONG
            // Mengubah tempSong sebagai onPlaySong
            *onPlaySong = tempSong;

            printf("\nMemutar lagu sebelumnya\n");
            printf("\"");
            DisplayKata(onPlaySong->Lagu);
            printf("\" oleh \"");
            DisplayKata(onPlaySong->Penyanyi);
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
    STARTSENTENCE();
    printf("\n");
    Word penyanyi = currentWord;

    if (ListSearch(daftarPenyanyi,penyanyi))
    {
        printf("Daftar Album oleh ");DisplayKata(penyanyi);printf(" :\n");
        DisplayVMap(*penyanyiAlbum,penyanyi);printf("\n");

        printf("Masukkan Nama Album yang dipilih : ");
        STARTSENTENCE();
        printf("\n");
        Word album = currentWord;
        if(IsSetMember(MapValue(*penyanyiAlbum, penyanyi), album))
        {
            printf("Daftar Lagu Album ");DisplayKata(album);printf(" oleh ");DisplayKata(penyanyi);printf(" :\n");
            DisplaySet(MapValue(*albumLagu, album));printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            STARTWORD();
            printf("\n");

            int idLagu =WordToInt(currentWord)-1;
            if (IsIdxValidSet(MapValue(*albumLagu, album), idLagu))
            {
                Word namaLagu = MapValue(*albumLagu, album).Elements[idLagu];
                Song lagu; CreateSong(&lagu, penyanyi, album, namaLagu);
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
    // Cek if x or y is out of bounds
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
    DisplayKata(queueSong->buffer[y].Lagu);
    printf("\" ");
    printf("berhasil ditukar dengan ");
    printf("\"");
    DisplayKata(queueSong->buffer[x].Lagu);
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

    int ctr = 0;
    for (int i = IDX_HEAD(*queueSong); i <= IDX_TAIL(*queueSong); i++) {
        if (ctr == id) {
            Song foundSong = queueSong->buffer[i];
            for (int j = i; j < IDX_TAIL(*queueSong); j++) {
                queueSong->buffer[j] = queueSong->buffer[j+1];
            }

            queueSong->idxTail = queueSong->idxTail - 1;

            printf("\nLagu ");
            printf("\"");
            DisplayKata(foundSong.Lagu);
            printf("\" ");
            printf("oleh ");
            printf("\"");
            DisplayKata(foundSong.Penyanyi);

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

void SAVE(Word filename, List daftarPenyanyi, Map penyanyiAlbum,
Map albumLagu, Song currentSong, Queue currentQ, Stack currentHist)
/*
SAVE merupakan command yang digunakan untuk menyimpan state aplikasi terbaru ke dalam suatu file.
Command SAVE memiliki satu argumen yang merepresentasikan nama file yang akan disimpan.
Penyimpanan dilakukan pada folder tertentu, misal folder save.
*/
// I.S. Sembarang dalam sesi
// F.S. Terbentuk suatu file bernama <filename> di folder save.
{
    FILE *fp;
    printf("filename: %s\n", filename.TabWord);
    fp = fopen(filename.TabWord, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
    } 

    fprintf(fp, "%s\n", filename.TabWord);

    fprintf(fp, "%d\n", ListLength(daftarPenyanyi));


    int i;
    Word currentPenyanyi;
    Set albumCurrentPenyanyi;
    for (i = 0; i < ListLength(daftarPenyanyi); i++){
        SalinKata(daftarPenyanyi.A[i], &currentPenyanyi);
        albumCurrentPenyanyi = MapValue(penyanyiAlbum, currentPenyanyi);
        // printf("Jumlah album %s: %d\n", currentPenyanyi.TabWord, albumCurrentPenyanyi.Count);
        fprintf(fp, "%d %s\n", albumCurrentPenyanyi.Count, currentPenyanyi.TabWord);
        
        int j;
        Set laguCurrentAlbum;
        Word currentAlbum;
        for (j=0; j < albumCurrentPenyanyi.Count; j++){
            SalinKata(albumCurrentPenyanyi.Elements[j], &currentAlbum);
            laguCurrentAlbum = MapValue(albumLagu, currentAlbum);
            fprintf(fp, "%d %s\n", laguCurrentAlbum.Count, currentAlbum.TabWord);
            
            int k;
            Word currentLagu;
            for (k = 0; k < laguCurrentAlbum.Count; k++){
                SalinKata(laguCurrentAlbum.Elements[k], &currentLagu);
                fprintf(fp, "%s\n", currentLagu.TabWord);
            }
        }
    }
    // === batas default ===
    Word cSongPenyanyi, cSongAlbum, cSongLagu;
    SalinKata(currentSong.Penyanyi, &cSongPenyanyi);
    SalinKata(currentSong.Album, &cSongAlbum);
    SalinKata(currentSong.Lagu, &cSongLagu);
    if (currentSong.Penyanyi.Length > 0){
        fprintf(fp, "%s;%s;%s\n", cSongPenyanyi.TabWord, cSongAlbum.TabWord, cSongLagu.TabWord);
    } else {
        fprintf(fp, "-;-;-\n");
    }
    // printf("ini oke, ");
    fprintf(fp, "%d\n", Qlength(currentQ));

    if (!QisEmpty(currentQ)) {
        i = IDX_HEAD(currentQ);
        while (i <= IDX_TAIL(currentQ)){
            SalinKata(currentQ.buffer[i].Penyanyi, &cSongPenyanyi);
            SalinKata(currentQ.buffer[i].Album, &cSongAlbum);
            SalinKata(currentQ.buffer[i].Lagu, &cSongLagu);
            fprintf(fp, "%s;%s;%s\n", cSongPenyanyi.TabWord, cSongAlbum.TabWord, cSongLagu.TabWord);
            i++;
        }
    }

    fprintf(fp, "%d\n", LengthStack(currentHist));
    i = Top(currentHist);
    if (Top(currentHist) != -1){
        while (i > -1){
            SalinKata(currentHist.T[i].Penyanyi, &cSongPenyanyi);
            SalinKata(currentHist.T[i].Album, &cSongAlbum);
            SalinKata(currentHist.T[i].Lagu, &cSongLagu);
            fprintf(fp, "%s;%s;%s\n", cSongPenyanyi.TabWord, cSongAlbum.TabWord, cSongLagu.TabWord);
            i--;
        }
    }


    fclose(fp);

    return;
}

void QUIT(List daftarPenyanyi, Map penyanyiAlbum, Map albumLagu,
Song currentSong, Queue currentQ, Stack currentHist)
// QUIT merupakan command yang digunakan untuk keluar dari sesi aplikasi WayangWave.
// I.S. Sembarang dalam sesi
// F.S. Keluar dari sesi. Jika data sesi disimpan maka terbentuk suatu file bernama <filename> di folder save.
{
    char shouldSave = '0';
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    STARTWORD();
    if (currentWord.TabWord[0] == 'Y') {
        printf("Masukkan nama file untuk penyimpanan: ");
        ADVWORD();

        SAVE(currentWord, daftarPenyanyi, penyanyiAlbum, albumLagu,
        currentSong, currentQ, currentHist);
    } else {
        printf("Kamu keluar dari WayangWave.\n");
        printf("Dadah ^_^/\n");
    }
}

void InvalidSession() {
    printf("\nCommand tidak bisa dieksekusi!\n");
}
