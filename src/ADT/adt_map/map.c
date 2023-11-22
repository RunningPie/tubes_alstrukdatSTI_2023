#include "map.h"

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void MapCreateEmpty(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean MapIsEmpty(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return (M.Count == Nil);
}

boolean MapIsFull(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return (M.Count == MapMaxEl);
}

/* ********** Operator Dasar Map ********* */
valuetype MapValue(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    int i;
    for (i=0; i < M.Count; i++){
        if (isWordEq(M.Elements[i].Key, k)){
            return M.Elements[i].Value;
        }
    }
    Set S; CreateEmptySet(&S);
    return S;
}

void MapInsert(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (!MapIsMember((*M), k) && !MapIsFull(*M)){
        SalinKata(k, &M->Elements[M->Count].Key);
        SalinSet(v, &M->Elements[M->Count].Value);
        M->Count ++;
    } 
}

void MapDelete(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    int i;
    for (i=0; i < M->Count; i++){
        if (isWordEq(M->Elements[i].Key, k)){
            break;
        }
    }
    if (isWordEq(M->Elements[i].Key, k)) {
        for (int j = i; j < M->Count; j++) {
            SalinKata(M->Elements[i + 1].Key, &M->Elements[i].Key);
            SalinSet(M->Elements[i + 1].Value, &M->Elements[i].Value);
        }
        M->Count--;
    }
}

boolean MapIsMember(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    int i;
    for (i=0; i < M.Count; i++){
        if (isWordEq(M.Elements[i].Key, k)) {
            return true;
        }
    }
    return false;
}

void DisplayVMap(Map M, keytype k) {
    if (MapIsMember(M, k)) {
        DisplaySet(MapValue(M, k));
    } else {
        printf("Key tidak valid\n");
    }
}

void DisplayMap(Map M) {
    if (MapIsEmpty(M)) {
        printf("Kosong\n");
    }
    else {
        for (int i = 0; i < M.Count; i++) {
            printf("Key %d: ", i+1);
            DisplayKata(M.Elements[i].Key);
            printf("\n");
            DisplaySet(M.Elements[i].Value);
        }
    }
}