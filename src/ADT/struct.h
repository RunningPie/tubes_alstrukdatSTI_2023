/*
Struct.h adalah header untuk semua custom structure yang dibutuhkan tiap ADT
*/

#ifndef STRUCT_H
#define STRUCT_H

#define maxString 128

typedef struct {
    char content[maxString];    /* array penyimpan character string */
    int length;                 /* menyimpan panjang array of char di atas */
} String;

#endif