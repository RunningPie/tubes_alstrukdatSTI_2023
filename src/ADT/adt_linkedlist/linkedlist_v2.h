#ifndef _LINKED_LIST_V2_
#define _LINKED_LIST_V2_

// Linked list dengan penunjuk ke elemen pertama dan terakhir

#include "../boolean.h"
#include "node.h"
#include <stdlib.h>

#define NIL NULL
#define IDX_UNDEF -1
#define UNDEF_VAL -1

typedef int ElType;
typedef struct node* Address;
typedef struct node { ElType info; Address next; } Node;

/* Definisi list: */
/* List kosong: First(L) = Last(L) = NIL */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P). */

typedef struct {
    Address first;
    Address last;
} LinkedList;

/* Selektor */
#define INFO(P) (P)->info
#define NEXT(P) (P)->next
#define FIRST(L) ((L).first)
#define LAST(L) ((L).last)

/* PROTOTYPE */
/************** TEST LIST KOSONG **************/
boolean LinkedListIsEmpty(LinkedList l);
/* Mengirim true jika lsit kosong: FIRST(L) = NIL
   dan LAST(L) = NIL */

/************** PEMBUATAN LIST KOSONG **************/
void CreateLinkedList(LinkedList *l);
/* I.S. sembarang */
/* F.S. Terbentuk list l kosong */
/* Jika gagal maka FIRST(l) = LAST(l) = NIL dan list gagal terbentuk */

/****************** SEARCHING ******************/
int indexOf(LinkedList l, ElType x);
/* Mengembalikan indeks node list dengan nilai X, atau IDX_UNDEF jika tidak ada */

/****************** OPERASI PRIMITIF ******************/
int LinkedListLength(LinkedList l);
/* Mengembalikan banyaknya elemen pada list l, 0 jika list kosong. */

ElType getElmt(LinkedList l, int idx);
/* Prekondisi: l terdefinisi */
/* Mengirimkan nilai elemen l pada indeks idx. */

void setElmt(LinkedList *l, int idx, ElType x);
/* I.S. List l terdefinisi */
/* F.S. Elemen l pada indeks ke-idx diganti nilainya menjadi val */

void LinkedListInsertFirst(LinkedList *l, ElType x);
/* I.S. List l terdefinisi */
/* F.S. Menambahkan elemen x sebagai elemen pertama List l */

void LinkedListInsertLast(LinkedList *l, ElType x);
/* I.S. List l terdefinisi */
/* F.S. x ditambahkan sebagai elemen terakhir l yang baru, */
/* yaitu menjadi elemen yang ditunjuk oleh LAST(L) */

void LinkedListDeleteFirst(LinkedList *l, ElType *x);
/* I.S. List l tidak kosong */
/* F.S. x adalah nilai elemen pertama list l sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void LinkedListDeleteAt(LinkedList *l, int idx, ElType *x);
/* I.S. l terdefinisi tidak kosong */
/* F.S. x diset dengan elemen l pada indeks ke-idx.
        Elemen l pada indeks ke-idx dihapus dari l. */

void LinkedListDeleteLast(LinkedList *l, ElType *x);
/* I.S. List l tidak kosong */
/* F.S. x adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */

#endif