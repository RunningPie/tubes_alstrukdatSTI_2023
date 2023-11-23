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

    Song firstSong;
    CreateSong(&firstSong, titleSong, albumSong, singerSong);

    enqueue(&q, firstSong);

    printf("Display info for the head of the queue...\n\n");
    DisplaySong(HEAD(q));
    printf("\n");

    printf("Queuing more songs to the queue...\n\n");
    Song s1, s2, s3;
    CreateSong(&s1, ToKata("Second Song"), ToKata("Second Album"), ToKata("Second Singer"));
    CreateSong(&s2, ToKata("Third Song"), ToKata("Third Album"), ToKata("Third Singer"));
    CreateSong(&s3, ToKata("Fourth Song"), ToKata("Fourth Album"), ToKata("Fourth Singer"));
    enqueue(&q, s1);
    enqueue(&q, s2);
    enqueue(&q, s3);
    
    printf("Displaying all element infos...\n\n");
    displayQueue(q);

    printf("Preemptive enqueue...\n\n");
    Song s4;
    CreateSong(&s4, ToKata("This Should be First"), ToKata("New Album"), ToKata("New Singer"));
    enqueueFirst(&q, s4);
    DisplaySong(HEAD(q));
    printf("\n");
    printf("Displaying all queue elements...\n\n");
    displayQueue(q);
    return 0;
}