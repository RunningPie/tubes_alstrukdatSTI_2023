#include "console.h"
#include <stdio.h>

#if defined(_WIN32) || defined(_WIN64)
    #define OS_TYPE "Windows"
#elif defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__APPLE__) || defined(__MACH__)
    #define OS_TYPE "Unix-like"
#else
    #define OS_TYPE "Unknown"
#endif

int main() {
    if (OS_TYPE == "Windows") {
        system("chcp 65001");
        system("cls");
    } else {
        system("clear");
    }
    // printf("            _                         _         _       _                           _    \n");
    // printf("           (_ )                      ( )_      ( )     ( )_                        ( )_  \n");
    // printf("  ___   __  | |   _ _  ___ ___    _ _|  _)    _| |  _ _|  _)  _ _  ___    __      _| |_) \n");
    // printf("/  __)/ __ \\| | / _  )  _   _  \\/ _  ) |    / _  |/ _  ) |  / _  )  _  \\/ _  \\  / _  | | \n");
    // printf("\\__  \\  ___/| |( (_| | ( ) ( ) | (_| | |_  ( (_| | (_| | |_( (_| | ( ) | (_) | ( (_| | | \n");
    // printf("(____/\\____)___)\\__ _)_) (_) (_)\\__ _)\\__)  \\__ _)\\__ _)\\__)\\__ _)_) (_)\\__  |  \\__ _)_) \n");
    // printf("                                                                       ( )_) |           \n");
    // printf("                                                                        \\___/            \n");

    printf("\n============================================= Selamat Datang di =============================================\n");    
        // printf("\n\033[1m                                                Wayang Wave                                                   \033[0m\n");
    printf("\n __   __   __  ______  __    __  ______  _______   ______       __   __   __  ______  __     __  ______  \n");
    printf("|  \\ |  \\ |  \\|      \\|  \\  |  \\|      \\|       \\ /      \\     |  \\ |  \\ |  \\|      \\|  \\   /  \\/      \\ \n");
    printf("| ▓▓ | ▓▓ | ▓▓ \\▓▓▓▓▓▓\\ ▓▓  | ▓▓ \\▓▓▓▓▓▓\\ ▓▓▓▓▓▓▓\\  ▓▓▓▓▓▓\\    | ▓▓ | ▓▓ | ▓▓ \\▓▓▓▓▓▓\\\\▓▓\\ /  ▓▓  ▓▓▓▓▓▓\\ \n");
    printf("| ▓▓ | ▓▓ | ▓▓/      ▓▓ ▓▓  | ▓▓/      ▓▓ ▓▓  | ▓▓ ▓▓  | ▓▓    | ▓▓ | ▓▓ | ▓▓/      ▓▓ \\▓▓\\  ▓▓| ▓▓    ▓▓ \n");
    printf("| ▓▓_/ ▓▓_/ ▓▓  ▓▓▓▓▓▓▓ ▓▓__/ ▓▓  ▓▓▓▓▓▓▓ ▓▓  | ▓▓ ▓▓__| ▓▓    | ▓▓_/ ▓▓_/ ▓▓  ▓▓▓▓▓▓▓  \\▓▓ ▓▓ | ▓▓▓▓▓▓▓▓ \n");
    printf(" \\▓▓   ▓▓   ▓▓\\▓▓    ▓▓\\▓▓    ▓▓\\▓▓    ▓▓ ▓▓  | ▓▓\\▓▓    ▓▓     \\▓▓   ▓▓   ▓▓\\▓▓    ▓▓   \\▓▓▓   \\▓▓     \\ \n");
    printf("  \\▓▓▓▓▓\\▓▓▓▓  \\▓▓▓▓▓▓▓_\\▓▓▓▓▓▓▓ \\▓▓▓▓▓▓▓\\▓▓   \\▓▓_\\▓▓▓▓▓▓▓      \\▓▓▓▓▓\\▓▓▓▓  \\▓▓▓▓▓▓▓    \\▓     \\▓▓▓▓▓▓▓ \n");
    printf("                      |  \\__| ▓▓                 |  \\__| ▓▓                                               \n");
    printf("                       \\▓▓    ▓▓                  \\▓▓    ▓▓                                              \n");
    printf("                        \\▓▓▓▓▓▓                    \\▓▓▓▓▓▓           \n");                                                         


    printf("\n============================================= ♫ Enjoy The Music ♫ =============================================\n");            

    boolean state = false, end = true;
    List daftarPenyanyi = MakeList();
    ArrayDin daftarPlaylist = MakeArrayDin();
    Queue queue; CreateQueue(&queue);
    Stack history; CreateEmptyStack(&history);
    Map penyanyiAlbum, albumLagu; MapCreateEmpty(&penyanyiAlbum); MapCreateEmpty(&albumLagu);
    Song currentSong;
    PasteSong(SongKosong, &currentSong);

    while (end) {
        printf("\n>> ");
        STARTSENTENCE();
        if (isWordEq(SenToWord(currentWord, 0), ToKata("START"))) {
            if (!state) {
                STARTWAYANGWAVE(&daftarPenyanyi, &penyanyiAlbum, &albumLagu);
                state = true;
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("LOAD"))) {
            if (!state) {
                // LOAD
                LOAD(SenToWord(currentWord, 1), &daftarPenyanyi, &penyanyiAlbum,
                &albumLagu, &state, &currentSong, &queue, &history, &daftarPlaylist);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("LIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("DEFAULT"))) {
            if (state) {
                // LIST DEFAULT
                LISTDEFAULT(daftarPenyanyi, &penyanyiAlbum, &albumLagu);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("LIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {
            if (state) {
                // LIST PLAYLIST
                LISTPLAYLIST(daftarPlaylist);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAY")) && isWordEq(SenToWord(currentWord, 1), ToKata("SONG"))) {
            if (state) {
                // PLAY SONG
                PLAYSONG(daftarPenyanyi, &penyanyiAlbum, &albumLagu, &queue, &history, &currentSong);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAY")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {
            if (state) {
                // PLAY PLAYLIST
                PLAYPLAYLIST(daftarPlaylist, &queue, &history, &currentSong);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("SONG"))) {
            if (state) {
                // QUEUE SONG
                enqueueSong(daftarPenyanyi, &penyanyiAlbum, &albumLagu, &queue);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {
            if (state) {
                // QUEUE PLAYLIST
                queuePlaylist(&queue, daftarPlaylist);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("SWAP"))) {
            if (state) {
                // QUEUE SWAP
                queueSwap(&queue, (WordToInt(SenToWord(currentWord, 2))-1), (WordToInt(SenToWord(currentWord, 3))-1));
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("REMOVE"))) {
            if (state) {
                // QUEUE REMOVE
                queueRemove(&queue, (WordToInt(SenToWord(currentWord, 2))-1));
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("CLEAR"))) {
            if (state) {
                // QUEUE CLEAR
                queueClear(&queue);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SONG")) && isWordEq(SenToWord(currentWord, 1), ToKata("NEXT"))) {
            if (state) {
                // SONG NEXT
                songNext(&queue, &history, &currentSong);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SONG")) && isWordEq(SenToWord(currentWord, 1), ToKata("PREVIOUS"))) {
            if (state) {
                // SONG PREVIOUS
                songPrev(&queue, &history, &currentSong);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("CREATE"))) {
            if (state) {
                // PLAYLIST CREATE
                PLAYLISTCREATE(&daftarPlaylist);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("ADD")) && isWordEq(SenToWord(currentWord, 2), ToKata("SONG"))) {
            if (state) {
                // PLAYLIST ADD SONG
                PLAYLISTADDSONG(daftarPenyanyi, &daftarPlaylist, &penyanyiAlbum, &albumLagu);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("ADD")) && isWordEq(SenToWord(currentWord, 2), ToKata("ALBUM"))) {
            if (state) {
                // PLAYLIST ADD ALBUM
                PLAYLISTADDALBUM(daftarPenyanyi, &daftarPlaylist, penyanyiAlbum, albumLagu);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("SWAP"))) {
            if (state) {
                // PLAYLIST SWAP
                PLAYLISTSWAP(daftarPenyanyi, &daftarPlaylist, penyanyiAlbum, albumLagu, WordToInt(SenToWord(currentWord, 2)), WordToInt(SenToWord(currentWord, 3)), WordToInt(SenToWord(currentWord, 4)));
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("REMOVE"))) {
            if (state) {
                // PLAYLIST REMOVE
                PLAYLISTREMOVE(daftarPenyanyi, &daftarPlaylist, penyanyiAlbum, albumLagu, WordToInt(SenToWord(currentWord, 2)), WordToInt(SenToWord(currentWord, 3)));
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("DELETE"))) {
            if (state) {
                // PLAYLIST DELETE
                PLAYLISTDELETE(daftarPenyanyi, &daftarPlaylist, penyanyiAlbum, albumLagu);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("STATUS"))) {
            if (state) {
                // STATUS
                STATUS(currentSong, queue);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SAVE"))) {
            if (state) {
                // SAVE
                SAVE(SenToWord(currentWord, 1), daftarPenyanyi,
                penyanyiAlbum, albumLagu, currentSong, queue, history, daftarPlaylist);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUIT"))) {
            if (state) {
                QUIT(daftarPenyanyi, penyanyiAlbum, albumLagu,
                currentSong, queue, history, daftarPlaylist);
                end = false; state = false;
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("HELP"))) {
            if (state) {
                help2();
            } else {
                help1();
            }
        } else {
            printf("\nCommand tidak diketahui!\n");
        }
    }
    printf("\n============================================= Kamu Keluar dari Wayang Wave =============================================\n");
    printf("\n \\\\                  =o)  \n");
    printf(" (o>                 /\\\\  \n");
    printf("_(()_Sampai Jumpa 👋_\\_V_ \n");
    printf(" //                   \\\\  \n");
    printf("                       \\\\ \n");
    printf("\n================================================ ♫ Keep Vibing ♫ ================================================\n");
}