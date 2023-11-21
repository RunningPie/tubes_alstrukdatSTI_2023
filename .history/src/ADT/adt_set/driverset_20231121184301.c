#include "set.h"

int main() {
    Set S; CreateEmptySet(&S);
    SetInsert(&S, ToKata("HALO"));
    SetInsert(&S, ToKata("KAMU"));
    SetInsert(&S, ToKata("KAMU"));
    SetInsert(&S, ToKata("KOK"));
    SetInsert(&S, ToKata("LUCU"));
    DisplaySet(S); printf("\n");
    SetDelete(&S, ToKata("LUCU"));
    SetInsert(&S, ToKata("WKWKWK"));
    DisplaySet(S);
}