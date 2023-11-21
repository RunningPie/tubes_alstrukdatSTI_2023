#include <stdio.h>
#include "queue.h"

// Test ADT QUEUE
int main(){

    Queue q;
    printf("Creating new queue...\n\n");
    CreateQueue(&q);

    printf("Checking if queue is empty...\n");
    printf("Is queue empty? ");
    if (QisEmpty(q)) {
        printf("Yes\n\n");
    } else {
        printf("No...\n\n");
    }

    printf("Checking if queue is full...\n");
    printf("Is queue full? ");
    if (QisFull(q)) {
        printf("Yes\n\n");
    } else {
        printf("No...\n\n");
    }

    printf("Enqueuing new Song to Queue...\n\n");
    char* titleChar = "Hello";
    Word titleSong = ToKata(titleChar);

    char* albumChar = "25";
    Word albumSong = ToKata(albumChar);

    char* singerChar = "singer";
    Word singerSong = ToKata(singerChar);

    Song firstSong = createSong(titleSong, albumSong, singerSong);

    enqueue(&q, firstSong);

    printf("Display info for the head of the queue...\n\n");
    displaySongInfo(HEAD(q));
    printf("\n");

    printf("Queuing more songs to the queue...\n\n");
    enqueue(&q, createSong(ToKata("Second Song"), ToKata("Second Album"), ToKata("Second Singer")));
    enqueue(&q, createSong(ToKata("Third Song"), ToKata("Third Album"), ToKata("Third Singer")));
    enqueue(&q, createSong(ToKata("Fourth Song"), ToKata("Fourth Album"), ToKata("Fourth Singer")));
    printf("Displaying all element infos...\n\n");
    displayQueue(q);

    printf("Preemptive enqueue...\n\n");
    enqueueFirst(&q, createSong(ToKata("This Should be First"), ToKata("New Album"), ToKata("New Singer")));
    displaySongInfo(HEAD(q));
    printf("\n");
    printf("Displaying all queue elements...\n\n");
    displayQueue(q);
    return 0;
}