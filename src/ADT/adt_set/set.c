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
        S->Elements[S->Count] = Elmt;
        S->Count ++;
    }
}
void SetDelete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    int i;
    for (i=0; i < S->Count; i++){
        if (isWordEq(S->Elements[i], Elmt)) {
            break;
        }
    }
    if (!(i==S->Count)) {
        if (S->Count > 1){
            for (i=i+1; i < S->Count; i++){
                S->Elements[i-1] = S->Elements[i];
            }
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

void DisplaySet(Set S) {
    if (IsEmptySet(S)) {
        printf("Kosong\n");
    } else {
        int j = 1;
        for (int i = 0; i < S.Count; i++) {
            printf("%d. ", j);
            DisplayKata(S.Elements[i]);
            j++;
        }
    }
}
    