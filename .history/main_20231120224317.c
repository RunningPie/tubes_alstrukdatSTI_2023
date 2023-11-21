#include "src/console.h"
#include <stdio.h>

int main() {

    boolean stateWAYANG = false;
    List daftarPenyanyi = MakeList();
    ArrayDin daftarPlaylist = MakeArrayDin();
    CQueue queue; CreateCCQueue(&queue);
    Stack history; CreateEmptyStack(&history);
    Map penyanyiAlbum, albumLagu; MapCreateEmpty(&penyanyiAlbum); MapCreateEmpty(&albumLagu);

    while(!stateWAYANG) {
        do {
            STARTWORD();
            if (!isWordEq(currentWord, ToKata("START")) && !isWordEq(currentWord, ToKata("LOAD")) && !isWordEq(currentWord, ToKata("HELP"))) {
                printf("Command tidak diketahui!\n");
            }
        } while (!isWordEq(currentWord, ToKata("START")) && !isWordEq(currentWord, ToKata("LOAD")) && !isWordEq(currentWord, ToKata("HELP")));
        if (isWordEq(currentWord, ToKata("START"))) {
            STARTWAYANGWAVE(&daftarPenyanyi, &penyanyiAlbum, &albumLagu);
            stateWAYANG = true;
        } else if (isWordEq(currentWord, ToKata("LOAD"))) {
            // LOAD
            stateWAYANG = true;
        } else if (isWordEq(currentWord, ToKata("HELP"))) {
            // HELP
        }
    }
    while (stateWAYANG) {
        menuLIST(&stateWAYANG);
    }  
}