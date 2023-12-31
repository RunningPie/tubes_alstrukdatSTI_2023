/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkarakter.h"
#include <stdio.h>

char currentChar;
boolean EOP;

FILE *pita;
static int retval;

void START()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       // if (isFile) {
       //        pita = fopen();
       // } else {
       //        pita = stdin;
       // }
       pita = stdin;
       
       ADV();
}

void STARTFILE(char* filename) {
       pita = fopen(filename, "r");
       if (pita == NULL){
              currentChar = '\0';
              return;
       }
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       if (currentChar == '\r'){
              retval = fscanf(pita, "%c", &currentChar);
       }
       EOP = feof(pita);
}

boolean isEOP() {
       return feof(pita);
}