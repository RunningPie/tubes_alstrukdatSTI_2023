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
#define WORDLENGTH(w) (w).Length
typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

// ADT SET
#define SetNil 0
#define SetMaxEl 100

typedef Word infotype;
typedef struct
{
    infotype Elements[SetMaxEl];
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
} Song;

// HashMap
#define HashNil 0
#define HashMaxEl 16
#define HashUndefined -9999

typedef int hashkeytype;
typedef int hashvaluetype;
typedef int hashaddress;

typedef struct
{
	hashkeytype Key;
	hashvaluetype Value;
} HashInfotype;

typedef struct
{
    HashInfotype Elements[HashMaxEl];
	hashaddress Count;
} HashMap;


#endif