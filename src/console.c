#include "console.h"

boolean CheckValidFile(Word filename){
    if ((filename.TabWord[filename.Length-3] != 'T') && (filename.TabWord[filename.Length-3] != 't')){
        // printf("%c == T\n", filename.TabWord[filename.Length-3]);
        return false;
    }
    if ((filename.TabWord[filename.Length-2] != 'X') && (filename.TabWord[filename.Length-2] != 'x')){
        // printf("%c == X\n", filename.TabWord[filename.Length-2]);
        return false;
    }
    if ((filename.TabWord[filename.Length-1] != 'T') && (filename.TabWord[filename.Length-1] != 't')){
        return false;
    }
    return true;
}

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

void LOAD(Word filename, List *daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu,
boolean * state,  Song *currentSong, Queue *currentQ, Stack *currentHist,
ArrayDin *daftarPlaylist)
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
    int i, j, k, Npenyanyi, Nalbum, Nlagu, NQueue, NStack, NPL;
    Word penyanyi, album, lagu, loadDir;
    Set Salbum, Slagu;
    CreateEmptySet(&Salbum);
    CreateEmptySet(&Slagu);

    if (!CheckValidFile(filename)){ //handling filename yang belakangnya bukan .txt
        // printf("CheckValidFile: %d\n", CheckValidFile(filename));
        ConcatKata(filename, ToKata(".txt"), &filename);
    }

    // STARTSENTENCE();
    // SalinKata(currentWord, &filename);

    ConcatKata(ToKata("save/"), filename, &loadDir);
    // printf("loading: %s\n", loadDir.TabWord);

    STARTWORDFILE(loadDir.TabWord);
    // printf("ok\n");
    if (currentChar != '\0'){
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
        // CURRENT SONG
        ADVSENTENCE();
        if (currentWord.TabWord[0] != '-'){
            SalinKata(currentWord, &((*currentSong).Penyanyi));
            currentChar = BLANK;
            ADVSENTENCE();
            SalinKata(currentWord, &((*currentSong).Album));
            currentChar = BLANK;
            ADVSENTENCE();
            SalinKata(currentWord, &((*currentSong).Lagu));
        }

        // QUEUE
        ADVSENTENCE();
        NQueue = WordToInt(currentWord);
        // printf("%d\n", NQueue);
        // currentChar = BLANK;
        for (i = 0; i < NQueue; i++){
            Song qSong;
            ADVSENTENCE(); currentChar = BLANK;
            SalinKata(currentWord, &(qSong.Penyanyi));
            ADVSENTENCE(); currentChar = BLANK;
            SalinKata(currentWord, &(qSong.Album));
            ADVSENTENCE();
            SalinKata(currentWord, &(qSong.Lagu));

            enqueue(currentQ, qSong);
            // printf("enqueue ok\n");

        }

        // STACK
        ADVSENTENCE();
        NStack = WordToInt(currentWord);
        Stack tempStack;
        CreateEmptyStack(&tempStack);
        // printf("%d\n", NQueue);
        // currentChar = BLANK;
        for (i = 0; i < NStack; i++){
            Song tempSong;
            ADVSENTENCE(); currentChar = BLANK;
            SalinKata(currentWord, &(tempSong.Penyanyi));
            ADVSENTENCE(); currentChar = BLANK;
            SalinKata(currentWord, &(tempSong.Album));
            ADVSENTENCE();
            SalinKata(currentWord, &(tempSong.Lagu));

            PushStack(&tempStack, tempSong);
            // printf("enqueue ok\n");
        }
        for (i = 0; i < NStack; i++){
            Song sSong;
            PopStack(&tempStack, &sSong);
            PushStack(currentHist, sSong);
            // printf("enqueue ok\n");
        }
        // printf("STACK OK\n");

        // PLAYLIST
        ADVSENTENCE();
        NPL = WordToInt(currentWord);
        // printf("NPL OK\n");
        for (i = 0; i < NPL; i++){
            // printf("i: %d\n", i);
            ArrDinEl tempADEl;
            // printf("ARDINEL OK\n");
            ADVSENTENCE();
            // printf("ADVSEN OK\n");
            int NPLS = WordToInt(SenToWord(currentWord, 0));
            // printf("NPLS: %d\n", NPLS);
            Word currentKataJudul;
            SalinKata(SenToWord(currentWord, 1), &currentKataJudul);
            // DisplayKata(currentKataJudul);
            int idxSen = 2;
            // printf("currSWC: %d\n", currSenWordCount);
            while (idxSen <= currSenWordCount){
                ConcatKata(currentKataJudul, ToKata(" "), &currentKataJudul);
                ConcatKata(currentKataJudul, SenToWord(currentWord, idxSen), &currentKataJudul);
                idxSen++;
            }
            SalinKata(currentKataJudul, &(tempADEl.namaPlaylist));
            tempADEl = CreateArrDinEl(currentKataJudul);
            for (j = 0; j < NPLS; j++){
                Song sPL;
                // printf("j: %d\n", j);
                ADVSENTENCE(); currentChar = BLANK;
                SalinKata(currentWord, &(sPL.Penyanyi));
                ADVSENTENCE(); currentChar = BLANK;
                SalinKata(currentWord, &(sPL.Album));
                ADVSENTENCE();
                SalinKata(currentWord, &(sPL.Lagu));

                LinkedListInsertLast(&(tempADEl.pLinkedList), sPL);
                // LinkedListDisplay(tempADEl.pLinkedList);
            }
            InsertAtArrDin(daftarPlaylist, tempADEl, i);
            // PrintArrayDin(*daftarPlaylist);
        }

        printf("\nSave file berhasil dibaca. WayangWave berhasil dijalankan.\n");
        (*state) = true;
    } else {
        printf("\n Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
        (*state) = false;
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
    printf("Daftar playlist yang kamu miliki:");

    if (IsEmptyArrDin(daftarPlaylist)) {
        printf("Kamu tidak memiliki playlist.\n");
    } 
    else {
        PrintArrayDin(daftarPlaylist);
    }
}

void PLAYSONG(List daftarPenyanyi, Map *penyanyiAlbum, Map *albumLagu, Queue *queueSong, Stack *historySong, Song *currentSong) {
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
                Song lagu; CreateSong(&lagu, penyanyi, album, MapValue(*albumLagu, album).Elements[idLagu]);

                // Clear queue dan history
                queueClear(queueSong);
                clearStack(historySong);
                // nanti benerin lagi

                printf("Memutar lagu \"");
                DisplayKata(lagu.Lagu);
                printf("\" oleh \"");
                DisplayKata(lagu.Penyanyi);
                printf("\".\n");

                PasteSong(lagu, currentSong);
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

void PLAYPLAYLIST(ArrayDin daftarPlaylist, Queue *QueueL, Stack *historyL, Song *onPlaySong) {
    printf("Daftar Playlist Pengguna :");
    PrintArrayDin(daftarPlaylist);
    printf("\n");

    printf("Masukkan ID Playlist yang dipilih : ");
    STARTWORD();
    printf("\n");

    int idPlaylist = WordToInt(currentWord) - 1;
    if (IsIdxValidArrDin(daftarPlaylist, idPlaylist)) {
        LinkedList playlist;
        CreateLinkedList(&playlist);
        CreateQueue(QueueL);
        CreateEmptyStack(historyL);
        // LinkedList = daftarPlaylist.TabWord[idPlaylist]
        playlist = daftarPlaylist.A[idPlaylist].pLinkedList;
        // Clear queue dan history
       

        // Enqueue semua lagu dari playlist yang dipilih
        Address currentSong = playlist.first;
        currentSong != NULL ? *onPlaySong = playlist.first->info : CreateEmptySong(onPlaySong);
        while (currentSong != NULL){
            enqueue(QueueL, currentSong->info);
            PushStack(historyL, currentSong->info);
            currentSong = currentSong->next;
        }
        if (!LinkedListIsEmpty(playlist)) {
            printf("Memutar playlist \"");
            DisplayKata(daftarPlaylist.A[idPlaylist].namaPlaylist);
            printf("\".\n");
        } 
        else {
            printf("Playlist kosong. Tidak ada lagu yang dapat diputar.\n");
        }
    }
    else {
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", idPlaylist + 1);
    }

}


void PLAYLISTCREATE(ArrayDin *daftarPlaylist)
{
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
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
        printf("\nMinimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
    }
    else
    {
        LinkedList playlist;
        CreateLinkedList(&playlist);
        ArrDinEl newPlaylist;
        newPlaylist = CreateArrDinEl(currentWord);
        InsertAtArrDin (daftarPlaylist, newPlaylist, daftarPlaylist->Neff);
        printf("\nPlaylist ");DisplayKata(currentWord);printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
    }
}

void PLAYLISTADDSONG(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map *penyanyiAlbum, Map *albumLagu)
{
    printf("\nDaftar Penyanyi :\n");
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
                printf("Daftar Playlist Pengguna :");
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
                    // printf("Length: %d\n", LinkedListLength(*playlist));

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

                    // printf("Length: %d\n", LinkedListLength(*playlist));
                    // LinkedListDisplay(*playlist);
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
    printf("\nDaftar Penyanyi :\n");
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
            printf("Daftar Playlist Pengguna :");
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

    if (((id+1) == WordToInt(ToKata("SWAP"))) || (x == y))
    {
        printf("\nArgumen input kurang, tidak melakukan swap\n");
        return;
    }
    else if (id<0 || id>=daftarPlaylist->Neff){
        printf("\nTidak ada playlist dengan playlist ID %d\n", id+1);
        return;
    }
    else
    {
        LinkedList playlist = (*daftarPlaylist).A[id].pLinkedList;
        if (x<0 || x>=LinkedListLength(playlist) || y<0 || y>=LinkedListLength(playlist))
        {
            printf("\nTidak ada lagu dengan urutan %d atau %d di playlist\n", x+1, y+1);
        }
        else 
        {
            LinkedListEl tempx,tempy;
            tempx = getElmt(playlist,x);  
            tempy = getElmt(playlist,y);
            setElmt(&playlist,tempy,x);
            setElmt(&playlist,tempx,y);

            printf("\nBerhasil menukar lagu dengan nama \"");DisplayKata(tempx.Lagu);printf("\" dengan \"");DisplayKata(tempy.Lagu);
            printf("\" di playlist \"");DisplayKata((daftarPlaylist->A[id].namaPlaylist));printf("\"\n");
        }
    }
}

void PLAYLISTREMOVE(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu, int id, int n)
{
    id -= 1;
    n -= 1;

    if (id<0 || id>=daftarPlaylist->Neff)
    {
        printf("\nTidak ada playlist dengan playlist ID %d\n", id+1);
    }
    else
    {
        LinkedList playlist = (*daftarPlaylist).A[id].pLinkedList;
        // CreateLinkedList(&playlist);
        if (n<0 || n>=LinkedListLength(playlist))
        {
            printf("\nTidak ada lagu dengan urutan %d di playlist\n", n+1);
        }
        else 
        {
            LinkedListEl lagu;
            LinkedListDeleteAt(&playlist,&lagu,n);
            // printf("ok\n");

            printf("\nLagu \"");DisplayKata(lagu.Lagu);printf("\" oleh \"");DisplayKata(lagu.Penyanyi);
            printf("\" telah dihapus dari playlist \"");DisplayKata(((daftarPlaylist->A)[id].namaPlaylist));printf("\"!\n");
        }
    }
}

void PLAYLISTDELETE(List daftarPenyanyi, ArrayDin *daftarPlaylist, Map penyanyiAlbum, Map albumLagu)
{
    printf("\nDaftar Playlist Pengguna :");
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
        printf("\nNow Playing :\n%s - %s - %s\n\n", tempL.Penyanyi.TabWord, tempL.Lagu.TabWord, tempL.Album.TabWord);
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
        if (onPlaySong->Penyanyi.TabWord[0] != '\0'){
            printf("\nMemutar lagu selanjutnya\n");
            printf("\"");
            DisplayKata(onPlaySong->Lagu);
            printf("\" oleh \"");
            DisplayKata(onPlaySong->Penyanyi);
            printf("\"\n");
        } else {
            printf("\nTidak ada lagu yang dimainkan.\n");
            PasteSong(SongKosong, onPlaySong);
        }
    }
    else {
        PushStack(previousSong, *onPlaySong);
        *onPlaySong = InfoTop(*previousSong);
        printf("\nQueue kosong. ");
        if (onPlaySong->Penyanyi.TabWord[0] != '\0'){
            printf("Memutar kembali lagu\n");
            printf("\"");
            DisplayKata(onPlaySong->Lagu);
            printf("\" oleh \"");
            DisplayKata(onPlaySong->Penyanyi);
            printf("\"\n");
        } else {
            printf("Tidak ada lagu yang dimainkan.\n");
            PasteSong(SongKosong, onPlaySong);
        }

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
    // Song tempSong;
    if (IsEmptyStack(*previousSong)){
        printf("\nRiwayat lagu kosong. ");
        if (onPlaySong->Penyanyi.TabWord[0] != '\0'){
            printf("Memutar kembali lagu\n");
            printf("\"");
            DisplayKata(onPlaySong->Lagu);
            printf("\" oleh \"");
            DisplayKata(onPlaySong->Penyanyi);
            printf("\"\n");
        } else {
            printf("Tidak ada lagu yang dimainkan\n");
            PasteSong(SongKosong, onPlaySong);
        }

    }
    else{
        if(QisFull(*queueSong)){
            printf("\nDaftar lagu pada Queue sudah penuh!\n");
        }
        else{
            enqueueFirst(queueSong, *onPlaySong); // Menyimpan Song yang sedang dimainkan menjadi HEAD DARI QUEUE SONG
            PopStack(previousSong, onPlaySong); // Menyimpan Song Previous di current song
            // *onPlaySong = InfoTop(*previousSong);
            // Mengubah tempSong sebagai onPlaySong
            // *onPlaySong = tempSong;

            if (onPlaySong->Penyanyi.TabWord[0] != '\0'){
                printf("Memutar lagu sebelumnya\n");
                printf("\"");
                DisplayKata(onPlaySong->Lagu);
                printf("\" oleh \"");
                DisplayKata(onPlaySong->Penyanyi);
                printf("\"\n");
            } else {
                printf("\nTidak ada lagu yang dimainkan\n");
                PasteSong(SongKosong, onPlaySong);
            }
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

    printf("Daftar Playlist Pengguna :");
    PrintArrayDin(daftarPlaylist);
    printf("\n");

    int idPlaylist;
    printf("Masukkan ID Playlist: "); STARTWORD();
    idPlaylist = WordToInt(currentWord)-1;
    // printf("%d\n", idPlaylist);
    if (idPlaylist < 0 || idPlaylist > LengthArrDin(daftarPlaylist)){
        LinkedList playlist = daftarPlaylist.A[idPlaylist].pLinkedList;
        Address currentSong = playlist.first;
        while (currentSong != NULL){
            enqueue(queueSong, INFO(currentSong));
            // PushStack(historyL, currentSong->info);
            currentSong = currentSong->next;
        }
        
        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", daftarPlaylist.A[idPlaylist].namaPlaylist.TabWord);
        // for (int i = 0; i < LengthArrDin(daftarPlaylist); i++) {
        //     enqueue(daftarPlaylist.A[i]);
        // }
    } else {
        printf("Tidak ada playlist dengan ID tersebut\n");
    }

}

void queueSwap(Queue *queueSong, int x, int y) {
/*
Proses: Procedure yang digunakan untuk menukar lagu pada urutan ke-x dan urutan ke-y. Input pada Command ini adalah dua id lagu (x, y). 
I.S.: Posisi lagu dengan id x dan posisi lagu dengan id y tetap berdasarkan urutan queue sebelumnya atau salah satu dari x atau y tidak terdefinisi 
F.S.: Posisi lagu dengan id x berada di posisi lagu dengan id y, serta posisi lagu dengan id y berada di posisi lagu dengan id x (Swapping telah dilakukan) apabila x dan y terdefinisi 
*/
    // printf("x: %d\n", x);
    // printf("swap: %d\n", WordToInt(ToKata("SWAP")));
    if (x+1 == WordToInt(ToKata("SWAP"))){
        printf("\nArgumen input kurang, tidak melakukan swap.\n");
    } else if (x==y){
        printf("\nArgumen x dan y sama... Tidak melakukan perubahan pada queue.\n");
    } else {
        if (Qlength(*queueSong) > 1) {
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
        } else if (Qlength(*queueSong) == 1){
            printf("\nHanya ada 1 lagu dalam queue... Tidak bisa melakukan swap.\n");
        } else {
            printf("\nQueue kosong. Tidak bisa melakukan swap.\n");
        }
    }
}

void queueRemove(Queue *queueSong, int id) {
/*
Proses: Procedure yang digunakan untuk menghapus lagu dari queue berdasarkan id yang dimasukkan. Input pada Command ini adalah id lagu (id) yang ingin dihapus dari queue
I.S.: Terdapat lagu (berdasarkan id yang dimasukkan) pada queue atau id yang dimasukkan tidak terdefinisi 
F.S.: Lagu (id) dihapus dari queue apabila id terdefinisi   
*/
    if (id+1 == WordToInt(ToKata("REMOVE"))) {
        printf("\nArgumen 'id' belum diberikan!\n");
    } else {
        if (!QisEmpty(*queueSong)){
        if (id > Qlength(*queueSong) || id < 0) {
            printf("\nLagu dengan urutan ke %d tidak ada\n", id+1);
        }

        int ctr = 0;
        for (int i = IDX_HEAD(*queueSong); i <= IDX_TAIL(*queueSong); i++) {
            if (ctr == id) {
                Song foundSong = queueSong->buffer[i];
                if (IDX_HEAD(*queueSong) == IDX_TAIL(*queueSong)) {
                    IDX_HEAD(*queueSong) = -1;
                    IDX_TAIL(*queueSong) = -1;
                } else {
                    for (int j = i; j < IDX_TAIL(*queueSong); j++) {
                        queueSong->buffer[j] = queueSong->buffer[j+1];
                    }

                    queueSong->idxTail = queueSong->idxTail - 1;
                }
                if (foundSong.Lagu.TabWord[0] != '\0'){
                    printf("\nLagu ");
                    printf("\"");
                    DisplayKata(foundSong.Lagu);
                    printf("\" ");
                    printf("oleh ");
                    printf("\"");
                    DisplayKata(foundSong.Penyanyi);

                    printf("\" telah dihapus dari queue!\n");
                    return;
                } else {
                    printf("\nTidak ada lagu pada id tersebut!\n");
                }
            }
            ctr++;
    }
    } else {
        printf("\nQueue kosong. Tidak bisa melakukan remove\n");
    }
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
Map albumLagu, Song currentSong, Queue currentQ, Stack currentHist,
ArrayDin daftarPlaylist)
/*
SAVE merupakan command yang digunakan untuk menyimpan state aplikasi terbaru ke dalam suatu file.
Command SAVE memiliki satu argumen yang merepresentasikan nama file yang akan disimpan.
Penyimpanan dilakukan pada folder tertentu, misal folder save.
*/
// I.S. Sembarang dalam sesi
// F.S. Terbentuk suatu file bernama <filename> di folder save.
{
    FILE *fp;
    if (!CheckValidFile(filename)){ //handling filename yang belakangnya bukan .txt
        // printf("CheckValidFile: %d\n", CheckValidFile(filename));
        ConcatKata(filename, ToKata(".txt"), &filename);
    }
    if (isWordEq(filename, ToKata("SAVE.txt"))){
        printf("\nArgumen filename belum diberikan!\n");
        printf("Autosaving dengan nama auto_save.txt...\n");
        SalinKata(ToKata("auto_save.txt"), &filename);
    }
    Word saveDir;
    // printf("OK\n");
    ConcatKata(ToKata("save/"), filename, &saveDir);
    // printf("sAVING AT: %s\n", saveDir.TabWord);
    fp = fopen(saveDir.TabWord, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    } 

    // fprintf(fp, "%s\n", filename.TabWord);
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

    // SIMPAN DATA STACK
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

    // SIMPAN DATA PLAYLIST
    // printf("sampe playlist aman\n");
    fprintf(fp, "%d", LengthArrDin(daftarPlaylist));
    if (LengthArrDin(daftarPlaylist) > 0){
        fprintf(fp, "\n");
    }
    for (i = 0; i < LengthArrDin(daftarPlaylist); i++){
        ArrDinEl currentPlaylist = daftarPlaylist.A[i];
        fprintf(fp, "%d %s", LinkedListLength(currentPlaylist.pLinkedList), currentPlaylist.namaPlaylist.TabWord);
        if (!LinkedListIsEmpty(currentPlaylist.pLinkedList)) {
            fprintf(fp, "\n");
            Address p = currentPlaylist.pLinkedList.first;
            while (p != NULL){
                if ((i == LengthArrDin(daftarPlaylist)-1) && NEXT(p) == NULL){
                    fprintf(fp, "%s;%s;%s", p->info.Penyanyi.TabWord, p->info.Album.TabWord, p->info.Lagu.TabWord);
                } else {
                    fprintf(fp, "%s;%s;%s\n", p->info.Penyanyi.TabWord, p->info.Album.TabWord, p->info.Lagu.TabWord);
                }
                    p = NEXT(p);
                
            }
        }
    }


    fclose(fp);
    printf("\nSave file berhasil disimpan.\n");
    return;
}

void QUIT(List daftarPenyanyi, Map penyanyiAlbum, Map albumLagu,
Song currentSong, Queue currentQ, Stack currentHist, ArrayDin daftarPlaylist)
// QUIT merupakan command yang digunakan untuk keluar dari sesi aplikasi WayangWave.
// I.S. Sembarang dalam sesi
// F.S. Keluar dari sesi. Jika data sesi disimpan maka terbentuk suatu file bernama <filename> di folder save.
{
    char shouldSave = '0';
    printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N) ");
    STARTWORD();
    if (currentWord.TabWord[0] == 'Y') {
        printf("Masukkan nama file untuk penyimpanan: ");
        STARTWORD();

        SAVE(currentWord, daftarPenyanyi, penyanyiAlbum, albumLagu,
        currentSong, currentQ, currentHist, daftarPlaylist);
    }
}

void InvalidSession() {
    printf("\nCommand tidak bisa dieksekusi!\n");
}
