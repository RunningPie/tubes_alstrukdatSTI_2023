#include "hashmap.h"
/* Definisi HashMap M kosong : M.Count = HashNil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void HashCreateEmpty(HashMap *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas HashMaxEl */
/* Ciri HashMap kosong : count berHashNilai HashNil dengan seluruh isi key & value map HashUndefined */
{
    M->Count = HashNil;
    
    int i;
    for (i=0; i < HashMaxEl; i++){
        M->Elements[i].Key = HashUndefined;
        M->Elements[i].Value = HashUndefined;
    }
}

/* *** Index Penyimpanan dengan modulo *** */
hashaddress Hash(hashkeytype K)
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke HashMaxEl */
{
    return (K%HashMaxEl);
}

/* ********** Operator Dasar HashMap ********* */
hashvaluetype HashValue(HashMap M, hashkeytype k)
/* Mengembalikan HashNilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan HashUndefined */
/* Jika tidak ada key k pada M, akan mengembalikan HashUndefined */
{

    int i = Hash(k);
    while (M.Elements[i].Key != k) {
        if (M.Elements[i].Key == HashUndefined){
            break;
        } else {
            i = i + 1;
        }
    }
    if (M.Elements[i].Key == k) {
        return M.Elements[i].Value;
    } else {
        return HashUndefined;
    }
}

void HashInsert(HashMap *M, hashkeytype k, hashvaluetype v)
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open hashaddressing linear probing dengan interval 1 jika index sudah terisi    */
{
    int i=Hash(k);
    while (M->Elements[i].Key != HashUndefined){
        if (M->Elements[i].Key == k){
            break;
        } else {
            i = (i+1)%HashMaxEl;
        }
    }
    if (M->Elements[i].Key == HashUndefined){
        M->Elements[i].Key = k;
        M->Elements[i].Value = v;
        M->Count++;
    }
}