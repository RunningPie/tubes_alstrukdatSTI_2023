#include "set.h"

/* Definisi Set S kosong : S.Count = SetNil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas SetMaxEl */
/* Ciri Set kosong : count berSetNilai SetNil */
{
    (*S).Count = SetNil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count berSetNilai SetNil */
{
    return (S.Count == SetNil);
}

boolean IsFullSet(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count berSetNilai SetMaxEl */
{
    return (S.Count == SetMaxEl);
}

/* ********** Operator Dasar Set ********* */
void SetInsert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (!IsSetMember((*S), Elmt)){
        SalinKata(Elmt, &S->Elements[S->Count]);
        S->Count ++;
    }
}
void SetDelete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    int i;
    for (i = 0; i < S->Count; i++){
        if (isWordEq(S->Elements[i], Elmt)) {
            found = true;
            break;
        }
    }
    if (found) {
        for (int j = i; j < S->Count; j++) {
            SalinKata(S->Elements[j + 1], &S->Elements[j]); 
        }
        S->Count--;
    }
}

boolean IsIdxValidSet(Set s,int i)
{
    return (i<s.Count && i>=0);
}

boolean IsSetMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    int i;
    for (i=0; i < S.Count; i++){
        if (isWordEq(S.Elements[i], Elmt)){
            return true;
        }
    }
    return false;
}

void SalinSet(Set S1, Set *S2) {
    S2->Count = S1.Count;
    for (int i = 0; i < S1.Count; i++) {
        SalinKata(S1.Elements[i], &S2->Elements[i]);
    }
}

void DisplaySet(Set S) {
    if (IsEmptySet(S)) {
        printf("Kosong\n");
    } else {
        int j = 1;
        for (int i = 0; i < S.Count; i++) {
            printf("%d. ", j);
            DisplayKata(S.Elements[i]);
            printf("\n");
            j++;
        }
    }
}

