#ifndef map_H
#define map_H

#include <stdio.h>
#include "../boolean.h"
#include "../adt_set/set.h"
#include "../struct.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0
#define MapMaxEl 10
#define Undefined -999

// typedef int bool;
typedef Word keytype;
typedef Set valuetype;

typedef struct {
	keytype Key;
	valuetype Value;
} MapEntry;

typedef struct {
	MapEntry Elements[MapMaxEl];
	int Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void MapCreateEmpty(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean MapIsEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean MapIsFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype MapValue(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void MapInsert(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void MapDelete(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean MapIsMember(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

void DisplayVMap(Map M, keytype k);
/* Menuliskan value dari Map */

void DisplayMap(Map M);

#endif