#include <stdio.h>
#include "queue.h"

int main(){

    Queue q;
    printf("Creating new queue...\n");
    CreateQueue(&q);

    printf("Checking if queue is empty...\n");
    printf("Is queue empty? ");
    if (QisEmpty(q)) {
        printf("Yes\n");
    } else {
        printf("No...\n");
    }

    printf("Checking if queue is full...\n");
    printf("Is queue full? ");
    if (QisFull(q)) {
        printf("Yes\n");
    } else {
        printf("No...\n");
    }

    printf("Enqueuing new Song to Queue...\n");
    char* titleChar = "Hello";
    Word titleSong = ToKata(titleChar);

    char* albumChar = "25";
    Word albumSong = ToKata(albumChar);

    char* singerChar = "singer";
    Word singerSong = ToKata(singerChar);

    Song firstSong = createSong(titleSong, albumSong, singerSong);

    enqueue(&q, firstSong);

    printf("Display info for the head of the queue...\n");
    displaySongInfo(HEAD(q));

    return 0;
}