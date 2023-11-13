/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include <math.h>
#include "../boolean.h"
#include "../adt_mesinkarakter/mesinkarakter.h"
#include "../struct.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDFILE(char* filename);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void ADVSENTENCE();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopySentence */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopySentence();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = \n atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean isEndWord();

boolean isWordEq(Word Kata1, Word Kata2);
/* Membandingkan antara kata1 dan kata2
   I.S. : kata1, kata2 sembarang
   F.S. : true jika kata1 = kata2 dan sebaliknya 
          apabila kata1.length != kata2.length maka akan mengembalikan false */

Word ToKata(char *string);
/* Mengubah string inputan menjadi word
   I.S. : string sembarang 
   F.S. : string disimpan dalam tabword dan panjangnya dalam length */

int WordToInt(Word Kata);
/* Mengubah word menjadi integer
   I.S. : word.TabWord merupakan digit
   F.S. : mengembalikan dalam bentuk integer */

void SalinKata(Word Kata1, Word* Kata2 );
/* Menyalin Kata1 ke Kata2
   I.S. : Kata1 sembarang, Kata2 kosong
   F.S. : Kata1 dan Kata2 sama */

void DisplayKata(Word Kata);
/* Menuliskan word kata */

#endif