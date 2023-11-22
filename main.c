#include "src/console.h"
#include <stdio.h>

int main() {

    boolean state = false, end = true;
    List daftarPenyanyi = MakeList();
    ArrayDin daftarPlaylist = MakeArrayDin();
    Queue queue; CreateQueue(&queue);
    Stack history; CreateEmptyStack(&history);
    Map penyanyiAlbum, albumLagu; MapCreateEmpty(&penyanyiAlbum); MapCreateEmpty(&albumLagu);
    Song currentSong;

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
                LOAD(SenToWord(currentWord, 1));
                state = true;
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
                PLAYPLAYLIST(daftarPlaylist, &albumLagu, &queue, &history, &currentSong);
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
                queueRemove(&queue, WordToInt(SenToWord(currentWord, 2)));
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
                PLAYLISTADDSONG(daftarPenyanyi, &daftarPlaylist, penyanyiAlbum, albumLagu);
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
                SAVE(SenToWord(currentWord, 1), daftarPenyanyi, penyanyiAlbum, albumLagu);
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUIT"))) {
            if (state) {
                QUIT(daftarPenyanyi, penyanyiAlbum, albumLagu);
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
}