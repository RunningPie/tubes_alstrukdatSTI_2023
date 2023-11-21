#include "set.h"

int main() {
    Set S; CreateEmptySet(&S);
    SetInsert(&S, ToKata("HALO"));
    SetInsert(&S, ToKata("KAMU"));
    SetInsert(&S, ToKata("KAMU"));
    SetInsert(&S, ToKata("KOK"));
    SetInsert(&S, ToKata("LUCU"));
    DisplaySet(S);
    SetDelete(&S, ToKata("LUCU"));
    DisplaySet(S);
}