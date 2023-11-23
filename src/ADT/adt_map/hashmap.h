#ifndef hashHashMap_H
#define hashHashMap_H
#include <stdio.h>
#include "../boolean.h"
#include "../struct.h"

/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open hashaddressing
*/

// #define false 0
// #define true 1

// typedef int bool;


/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void HashCreateEmpty(HashMap *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas HashMaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
hashaddress Hash(hashkeytype K);
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke HashMaxEl */

/* ********** Operator Dasar HashMap ********* */
hashvaluetype HashValue(HashMap M, hashkeytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void HashInsert(HashMap *M, hashkeytype k, hashvaluetype v);
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open hashaddressing linear probing dengan interval 1 jika index sudah terisi    */

#endif