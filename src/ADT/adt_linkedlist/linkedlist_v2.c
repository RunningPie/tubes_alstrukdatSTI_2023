#include "linkedlist_v2.h"
// #include "node.h"

Address newNode(LinkedListEl val) {
    Address p = (Address)

    malloc(sizeof(Node));

    if (p!=NULL) {
    INFO(p) = val;
    NEXT(p) = NULL;
    }
    return p;
}

/* Selektor */
#define INFO(P) (P)->info
#define NEXT(P) (P)->next
#define FIRST(L) ((L).first)
#define LAST(L) ((L).last)

/* PROTOTYPE */
/************** TEST LIST KOSONG **************/
boolean LinkedListIsEmpty(LinkedList l)
/* Mengirim true jika lsit kosong: FIRST(L) = NIL
   dan LAST(L) = NIL */
{
    return (FIRST(l) == NULL && LAST(l) == NULL);
}

/************** PEMBUATAN LIST KOSONG **************/
void CreateLinkedList(LinkedList *l)
/* I.S. sembarang */
/* F.S. Terbentuk list l kosong */
{
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}

/****************** SEARCHING ******************/
int indexOf(LinkedList l, LinkedListEl x)
/* Mengembalikan indeks node list dengan nilai X, atau IDX_UNDEF jika tidak ada */
{
    Address p;
    int idx;
    boolean found = false;

    p = FIRST(l);
    idx = 0;

    while (p != NULL && !found){
        if (INFO(p) == x){
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    }
    if (found) {
        return idx;
    } else {
        return IDX_UNDEF;
    }
}

/****************** OPERASI PRIMITIF ******************/
int LinkedListLength(LinkedList l)
/* Mengembalikan banyaknya elemen pada list l, 0 jika list kosong. */
{
    int count = 0;
    Address p = FIRST(l);

    while (p!=NULL){
        count++;
        p = NEXT(p);
    }

    return count;
}

LinkedListEl getElmt(LinkedList l, int idx)
/* Mengirimkan nilai elemen l pada indeks idx. */
{
    int count=0;
    Address p = FIRST(l);

    if (idx < 0 || idx > (LinkedListLength(l)-1)){
        return UNDEF_VAL;
    } else {
        while (count < idx) {
            count++;
            p = NEXT(p);
        }

        return INFO(p);
    }
}

void setElmt(LinkedList *l, LinkedListEl x, int idx)
/* I.S. List l terdefinisi */
/* F.S. Jika idx valid maka elemen l pada indeks ke-idx diganti nilainya menjadi val */
{
    int count=0;
    Address p = FIRST(*l);

    if (!(idx < 0 || idx > (LinkedListLength(*l)-1))){
        while (count < idx) {
            count++;
            p = NEXT(p);
        }
        INFO(p) = x;
    }
}

void LinkedListInsertFirst(LinkedList *l, LinkedListEl x)
/* I.S. List l terdefinisi */
/* F.S. Menambahkan elemen x sebagai elemen pertama List l */
{
    Address new = newNode(x);
    if (LinkedListIsEmpty(*l)){
        NEXT(new) = FIRST(*l);
        FIRST(*l) = new;
        LAST(*l) = new;
    } else {
        NEXT(new) = FIRST(*l);
        FIRST(*l) = new;
    }
}

void LinkedListInsertLast(LinkedList *l, LinkedListEl x)
/* I.S. List l terdefinisi */
/* F.S. x ditambahkan sebagai elemen terakhir l yang baru, */
/* yaitu menjadi elemen yang ditunjuk oleh LAST(L) */
{
    if (LinkedListIsEmpty(*l)){
        LinkedListInsertFirst(l, x);
    } else {
        Address p = newNode(x);
        if (p != NULL){
            NEXT(LAST(*l)) = p;
        }
    }
}

void LinkedListDeleteFirst(LinkedList *l, LinkedListEl *x)
/* I.S. List l tidak kosong */
/* F.S. x adalah nilai elemen pertama list l sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    Address p = FIRST(*l);
    (*x) = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
    if (FIRST(*l) == NULL){
        LAST(*l) = FIRST(*l);
    }
}

void LinkedListDeleteAt(LinkedList *l, LinkedListEl *x, int idx)
/* I.S. l terdefinisi tidak kosong */
/* F.S. x diset dengan elemen l pada indeks ke-idx.
        Elemen l pada indeks ke-idx dihapus dari l. */
{
    int count;
    Address current, prev;

    if (!(idx < 0 || idx > LinkedListLength(*l)-1)) {
        if (idx = 0) {
            LinkedListDeleteFirst(l, *x);
        } else {
            count = 0;
            prev = FIRST(*l);
            while (count < idx-1) {
                count++;
                prev = NEXT(prev);
            }
            current = NEXT(prev);
            (*x) = INFO(current);
            NEXT(prev) = NEXT(current);
            free(current);
        }
    }
}

void LinkedListDeleteLast(LinkedList *l, LinkedListEl *x)
/* I.S. List l tidak kosong */
/* F.S. x adalah terakhir pada list (yang ditunjuk loleh LAST(*l) sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
{
    Address p = LAST(*l);
    (*x) = INFO(p);
    Address prev = FIRST(*l);

    if (p != prev){
        while (NEXT(prev) != p) {
            prev = NEXT(prev);
        }
        LAST(*l) = prev;
    } else {
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
    }
    free(p);
}

void LinkedListInsertAt(LinkedList *l, LinkedListEl x, int i)
{
    Address p;
    p=newNode(x);
    if(p!=null)
    {
        if(i==0)
        {
            NEXT(P)=FIRST(*l);
            FIRST(*l)=p;
        }
        else
        {
            int ctr=0;
            Address loc = FIRST(*l);
            while (ctr<i-1)
            {
                ctr++;
                loc=NEXT(loc);
            }
            NEXT(p)=NEXT(loc);
            NEXT(loc)=p;
        }
    }
}

