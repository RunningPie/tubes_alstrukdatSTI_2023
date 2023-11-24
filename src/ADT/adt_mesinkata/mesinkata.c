#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;
int currSenWordCount;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK || currentChar == '\n')
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
    IgnoreBlanks();
}

void STARTSENTENCE() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopySentence();
    }
    IgnoreBlanks();
}

void STARTWORDFILE(char* filename) {
    STARTFILE(filename);
    if (currentChar != '\0') {
        IgnoreBlanks();
        if (currentChar == '\n')
        {
            endWord = true;
        }
        else
        {
            endWord = false;
            CopySentence();
        }
        IgnoreBlanks();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
    IgnoreBlanks();
}

void ADVSENTENCE()
{
    IgnoreBlanks();
    // printf("currentChar: %c\n", currentChar);
    // DisplayKata(currentWord); printf("\n");
    if (currentChar == '\n')
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopySentence();
    }
    IgnoreBlanks();
    // printf("currentChar: %c\n", currentChar);
    // DisplayKata(currentWord); printf("\n");
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && !isEOP()) 
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

void CopySentence()
{
    currentWord.Length = 0;
    currSenWordCount = 0;
    while (currentChar != MARK && currentChar != '\n' && currentChar != '\r' && !isEOP()) 
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            if (currentChar == BLANK){
                currSenWordCount++;
            }
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
            // printf("currentChar Update: %c\n", currentChar);
        }
        else
            break;
    }
}

boolean isEndWord() {
    return endWord;
}

boolean isWordEq(Word Kata1, Word Kata2) {
    if (Kata1.Length != Kata2.Length) {
        return false;
    }
    for (int i = 0; i < Kata1.Length; i++) {
        if (Kata1.TabWord[i] != Kata2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

Word ToKata(char *String) {
    Word Kata;
    int len = 0;
    while (String[len] != '\0') {
        len++;
    }
    Kata.Length = len;
    // printf("Panjang kata: %d\n", Kata.Length);

    for (int i = 0; i < Kata.Length; i++) {
        Kata.TabWord[i] = String[i];
    }
    Kata.TabWord[len] = '\0';
    return Kata;
}

int WordToInt(Word Kata) {
    int hasil = 0;
    for (int i = 0; i < Kata.Length; i++) {
        if (Kata.TabWord[i] - '0' > 0) {
            hasil = hasil * 10 + (Kata.TabWord[i] - '0');
        }
    }
    return hasil;
}

Word SenToWord(Word sentence, int idxKata) {
    int count = 0; 
    Word Kata; Kata.Length = 0;

    int i = 0;
    while (i < sentence.Length && count <= idxKata) {
        Kata.TabWord[Kata.Length] = sentence.TabWord[i];
        if (sentence.TabWord[i] == ' ') {
            if (count < idxKata) {
                Kata.Length = 0;
            } count++;
        }
        if (sentence.TabWord[i] != ' ') {
            Kata.Length++;
        }
        i++;
    }
    Kata.TabWord[Kata.Length] = '\0';
    return Kata;    
}

void SalinKata(Word Kata1, Word* Kata2) {
    Kata2->Length = Kata1.Length;
    for (int i = 0; i < Kata2->Length; i++) {
        Kata2->TabWord[i] = Kata1.TabWord[i];
    }
    Kata2->TabWord[Kata2->Length] = '\0';
}

void DisplayKata(Word Kata) {
    for (int i = 0; i < Kata.Length; i++) {
        printf("%c", Kata.TabWord[i]);
    }
}

String WordToString(Word Kata) {
    String str;
    str.length = Kata.Length;

    int i;
    for (i=0; i<Kata.Length; i++){
        str.content[i] = Kata.TabWord[i];
    }
    return str;
}

void ConcatKata(Word Kata1, Word Kata2, Word *temp){
    // Word (*temp);
    (*temp).Length = Kata1.Length;
    int i;
    for (i = 0; i < Kata1.Length; i++){
        (*temp).TabWord[i] = Kata1.TabWord[i];
    }
    for (i = (*temp).Length; i < ((*temp).Length+Kata2.Length); i++){
        (*temp).TabWord[i] = Kata2.TabWord[i-(*temp).Length];
    }
    (*temp).Length += Kata2.Length;
    (*temp).TabWord[(*temp).Length] = '\0';

}