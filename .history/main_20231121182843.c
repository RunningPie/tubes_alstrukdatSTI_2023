#include "src/console.h"
#include <stdio.h>

int main() {

    boolean state = false, end = true;
    List daftarPenyanyi = MakeList();
    ArrayDin daftarPlaylist = MakeArrayDin();
    Queue queue; CreateQueue(&queue);
    Stack history; CreateEmptyStack(&history);
    Map penyanyiAlbum, albumLagu; MapCreateEmpty(&penyanyiAlbum); MapCreateEmpty(&albumLagu);

    while(end) {
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
                state = true;
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("LIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("DEFAULT"))) {
            if (state) {
                // LIST DEFAULT
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("LIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {
            if (state) {
                // LIST PLAYLIST
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAY")) && isWordEq(SenToWord(currentWord, 1), ToKata("SONG"))) {
            if (state) {
                // PLAY SONG
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAY")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {
            if (state) {
                // PLAY PLAYLIST
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("SONG"))) {
            if (state) {
                // QUEUE SONG
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("PLAYLIST"))) {
            if (state) {
                // QUEUE PLAYLIST
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("SWAP"))) {
            if (state) {
                // QUEUE SWAP
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("REMOVE"))) {
            if (state) {
                // QUEUE REMOVE
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUEUE")) && isWordEq(SenToWord(currentWord, 1), ToKata("CLEAR"))) {
            if (state) {
                // QUEUE CLEAR
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SONG")) && isWordEq(SenToWord(currentWord, 1), ToKata("NEXT"))) {
            if (state) {
                // SONG NEXT
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SONG")) && isWordEq(SenToWord(currentWord, 1), ToKata("PREVIOUS"))) {
            if (state) {
                // SONG PREVIOUS
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("CREATE"))) {
            if (state) {
                // PLAYLIST CREATE
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("ADD"))) {
            if (state) {
                // PLAYLIST ADD
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("SWAP"))) {
            if (state) {
                // PLAYLIST SWAP
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("REMOVE"))) {
            if (state) {
                // PLAYLIST REMOVE
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("PLAYLIST")) && isWordEq(SenToWord(currentWord, 1), ToKata("DELETE"))) {
            if (state) {
                // PLAYLIST DELETE
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("STATUS"))) {
            if (state) {
                // STATUS
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("SAVE"))) {
            if (state) {
                // SAVE
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("QUIT"))) {
            if (state) {
                QUIT();
                end = false; state = false;
            } else {
                InvalidSession();
            }
        } else if (isWordEq(SenToWord(currentWord, 0), ToKata("HELP"))) {

        } else {
            printf("\nCommand tidak diketahui!\n");
        }
    }
}