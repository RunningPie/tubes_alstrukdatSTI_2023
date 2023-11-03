#include "list.h"
#include <stdio.h>

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList(){
    List L;
    int i;
    for (i=0; i<MaxEl; i++){
        L.A[i] = Mark;
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    return (L.A[0] == Mark);
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    return (L.A[i]);
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(List *L, IdxType i, ElType v){
    (*L).A[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    int i=0;
    while (L.A[i] != Mark){
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
    IdxType i=0;
    while (L.A[i] == Mark){
        i++;
    }
    if (IsEmpty(L)){
        return InvalidIdx;
    } else {
        return i;
    }
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(List L){
    if (IsEmpty(L)) {
        return InvalidIdx;
    } else {
        return (FirstIdx(L)+Length(L)-1);
    }
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
    return (i>=0 && i<=MaxEl-1);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (List L, IdxType i){
    return (i>=FirstIdx(L) && i<=LastIdx(L));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(List L, ElType X){
    int i;
    for (i=0; i<=LastIdx(L); i++){
        if (Get(L, i) == X){
            return true;
        }
    }
    return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(List *L, ElType X){
    InsertAt(L, X, 0);
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(List *L, ElType X, IdxType i){
    int j;
    for (j=LastIdx(*L)+1; j>i; j--){
        Set(L, j, Get(*L, j-1));
    }
    Set(L, i, X);
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(List *L, ElType X){
    InsertAt(L, X, LastIdx(*L)+1);
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(List *L){
    DeleteAt(L, 0);
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(List *L, IdxType i){
    int j;
    // Set(L, i, Mark);
    for (j=i; j<LastIdx(*L); j++){
        Set(L, j, Get(*L, j+1));
    }
    Set(L, LastIdx(*L), Mark);
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLast(List *L){
    DeleteAt(L, LastIdx(*L));
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List Concat(List L1, List L2){
    List L3 = MakeList();
    // printList(L3);
    int i;
    for (i=0; i <= Length(L1); i++){
        // printf("i: %d AND LastIdx: %d\n", i, Length(L1));
        // Set(&L3, i, Get(L1, i));
        // L3.A[i] = L1.A[i];
        // printf("Setting %d to %d\n", L3.A[LastIdx(L3)], Get(L1, i));
        InsertLast(&L3, Get(L1, i));
    }
    for (i=0; i <= Length(L2); i++){
        // L3.A[LastIdx(L3)+i]
        // printf("i: %d AND LastIdx: %d\n", i, Length(L2));
        // printf("Setting %d to %d\n", L3.A[LastIdx(L3)], Get(L2, i));
        // Set(&L3, LastIdx(L3)+i+1, Get(L2, i));
        InsertLast(&L3, Get(L2, i));
    }
    return L3;
}
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */

// void printList(List L){
//     int i;
//     printf("[");
//     for (i=0; i<=LastIdx(L)+1; i++){
//         printf("%d ", Get(L, i));
//     }
//     printf("]\n");
// }

// int main() {

//     List L1 = MakeList();
//     printList(L1);
//     printf("Is L1 empty? %d\n", IsEmpty(L1));
//     printf("How long is L1? %d\n", Length(L1));
//     Set(&L1, 0, 80);
//     printList(L1);
//     printf("What is L1's first element? %d\n", Get(L1, 0));
//     Set(&L1, 1, 76);
//     printList(L1);
//     printf("What is L1's first index? %d\n", FirstIdx(L1));
//     printf("What is L1's last index? %d\n", LastIdx(L1));
//     printf("Is %d a valid index in L1? %d\n", 100, IsIdxValid(L1, 100));
//     printf("Is %d a valid effective index in L1? %d\n", 3, IsIdxEff(L1, 3));
//     printf("Is %d in L1? %d\n", 80, IsIdxValid(L1, 80));

//     printf("Test insert: \n");

//     InsertFirst(&L1, 95);
//     printf("Hasil insert first: ");
//     printList(L1);

//     InsertAt(&L1, 77, 3);
//     printf("Hasil insert at: ");
//     printList(L1);

//     InsertLast(&L1, 70);
//     printf("Hasil insert last: ");
//     printList(L1);

//     printf("Test Delete: \n");

//     DeleteFirst(&L1);
//     printf("Hasil delete first: ");
//     printList(L1);

//     DeleteLast(&L1);
//     printf("Hasil delete last: ");
//     printList(L1);

//     DeleteAt(&L1, 1);
//     printf("Hasil delete at: ");
//     printList(L1);

//     List L2 = MakeList();
//     Set(&L2, 0, 99);
//     Set(&L2, 1, 98);
//     Set(&L2, 2, 97);
//     printList(L2);

//     List L3 = MakeList();
//     printList(L3);
//     L3 = Concat(L1, L2);
//     printList(L3);

//     return 0;
// }