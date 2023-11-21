/*
Struct.h adalah header untuk semua custom structure yang dibutuhkan tiap ADT
*/

#ifndef STRUCT_H
#define STRUCT_H

// #include "adt_mesinkata/mesinkata.h"

#define maxString 128

// Untuk ADT MesinKata
#define NMax 50
#define BLANK ' '
typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

// ADT SET
#define Nil 0
#define MaxEl 100

typedef Word infotype;
typedef struct
{
    infotype Elements[MaxEl];
    int Count;
} Set;

typedef struct {
    char content[maxString];    /* array penyimpan character string */
    int length;                 /* menyimpan panjang array of char di atas */
} String;

typedef struct {
    Word Penyanyi;
    Word Album;
    Word Lagu;
} Desc;

#endif