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
        L.A[i] = ToKata("-9999");
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    return (isWordEq(L.A[0], ToKata("-9999")));
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType ListGet(List L, IdxType i){
    return (L.A[i]);
}
/* Prekondisi : list tidak kosong, i antara ListFirstIdx(T)..ListLastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor ListSET : Mengubah nilai list dan elemen list *** */
void ListSet(List *L, IdxType i, ElType v){
    (*L).A[i] = v;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int ListLength(List L){
    int i=0;
    while (!isWordEq(L.A[i], ToKata("-9999"))){
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType ListFirstIdx(List L){
    IdxType i=0;
    while (isWordEq(L.A[i], ToKata("-9999"))){
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

IdxType ListLastIdx(List L){
    if (IsEmpty(L)) {
        return InvalidIdx;
    } else {
        return (ListFirstIdx(L)+ListLength(L)-1);
    }
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean ListIsIdxValid (List L, IdxType i){
    return (i>=0 && i<=MaxEl-1);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean ListIsIdxEff (List L, IdxType i){
    return (i>=ListFirstIdx(L) && i<=ListLastIdx(L));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara ListFirstIdx(L)..ListLastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean ListSearch(List L, ElType X){
    int i;
    for (i=0; i<=ListLastIdx(L); i++){
        if (isWordEq(ListGet(L, i), X)){
            return true;
        }
    }
    return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara ListFirstIdx(L)..ListLastIdx(L) */

void ListInsertFirst(List *L, ElType X){
    ListInsertAt(L, X, 0);
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void ListInsertAt(List *L, ElType X, IdxType i){
    int j;
    for (j=ListLastIdx(*L)+1; j>i; j--){
        ListSet(L, j, ListGet(*L, j-1));
    }
    ListSet(L, i, X);
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void ListInsertLast(List *L, ElType X){
    ListInsertAt(L, X, ListLastIdx(*L)+1);
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void ListDeleteFirst(List *L){
    ListDeleteAt(L, 0);
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diListset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void ListDeleteAt(List *L, IdxType i){
    int j;
    // ListSet(L, i, Mark);
    for (j=i; j<ListLastIdx(*L); j++){
        ListSet(L, j, ListGet(*L, j+1));
    }
    ListSet(L, ListLastIdx(*L), ToKata("-9999"));
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void ListDeleteLast(List *L){
    ListDeleteAt(L, ListLastIdx(*L));
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diListset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

List ListConcat(List L1, List L2){
    List L3 = MakeList();
    // printList(L3);
    int i;
    for (i=0; i <= ListLength(L1); i++){
        // printf("i: %d AND ListLastIdx: %d\n", i, ListLength(L1));
        // ListSet(&L3, i, ListGet(L1, i));
        // L3.A[i] = L1.A[i];
        // printf("ListSetting %d to %d\n", L3.A[ListLastIdx(L3)], ListGet(L1, i));
        ListInsertLast(&L3, ListGet(L1, i));
    }
    for (i=0; i <= ListLength(L2); i++){
        // L3.A[ListLastIdx(L3)+i]
        // printf("i: %d AND ListLastIdx: %d\n", i, ListLength(L2));
        // printf("ListSetting %d to %d\n", L3.A[ListLastIdx(L3)], ListGet(L2, i));
        // ListSet(&L3, ListLastIdx(L3)+i+1, ListGet(L2, i));
        ListInsertLast(&L3, ListGet(L2, i));
    }
    return L3;
}

void DisplayList(List L) {
    int j = 1;
    if (IsEmpty(L)) {
        printf("List Kosong\n");
    } else {
        for (int i = ListFirstIdx(L); i <= ListLastIdx(L); i++) {
            printf("%d. ", j); DisplayKata(L.A[i]);
            printf("\n");
            j++;
        }
    }
}

/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */

// void printList(List L){
//     int i;
//     printf("[");
//     for (i=0; i<=ListLastIdx(L)+1; i++){
//         printf("%d ", ListGet(L, i));
//     }
//     printf("]\n");
// }

// int main() {

//     List L1 = MakeList();
//     printList(L1);
//     printf("Is L1 empty? %d\n", IsEmpty(L1));
//     printf("How long is L1? %d\n", ListLength(L1));
//     ListSet(&L1, 0, 80);
//     printList(L1);
//     printf("What is L1's first element? %d\n", ListGet(L1, 0));
//     ListSet(&L1, 1, 76);
//     printList(L1);
//     printf("What is L1's first index? %d\n", ListFirstIdx(L1));
//     printf("What is L1's last index? %d\n", ListLastIdx(L1));
//     printf("Is %d a valid index in L1? %d\n", 100, ListIsIdxValid(L1, 100));
//     printf("Is %d a valid effective index in L1? %d\n", 3, ListIsIdxEff(L1, 3));
//     printf("Is %d in L1? %d\n", 80, ListIsIdxValid(L1, 80));

//     printf("Test insert: \n");

//     ListInsertFirst(&L1, 95);
//     printf("Hasil insert first: ");
//     printList(L1);

//     ListInsertAt(&L1, 77, 3);
//     printf("Hasil insert at: ");
//     printList(L1);

//     InsertLast(&L1, 70);
//     printf("Hasil insert last: ");
//     printList(L1);

//     printf("Test Delete: \n");

//     ListDeleteFirst(&L1);
//     printf("Hasil delete first: ");
//     printList(L1);

//     ListDeleteLast(&L1);
//     printf("Hasil delete last: ");
//     printList(L1);

//     ListDeleteAt(&L1, 1);
//     printf("Hasil delete at: ");
//     printList(L1);

//     List L2 = MakeList();
//     ListSet(&L2, 0, 99);
//     ListSet(&L2, 1, 98);
//     ListSet(&L2, 2, 97);
//     printList(L2);

//     List L3 = MakeList();
//     printList(L3);
//     L3 = ListConcat(L1, L2);
//     printList(L3);

//     return 0;
// }