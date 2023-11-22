#include "map.h"

int main() {
    Map M; MapCreateEmpty(&M);
    Set S1, S2; CreateEmptySet(&S1); CreateEmptySet(&S2);
    SetInsert(&S1, ToKata("AHIHIHIH"));
    SetInsert(&S1, ToKata("TUTURUUU"));
    SetInsert(&S1, ToKata("TENENENG"));
    SetInsert(&S1, ToKata("HIYAHIYA"));

    SetInsert(&S2, ToKata("KU"));
    SetInsert(&S2, ToKata("AAA"));
    SetInsert(&S2, ToKata("EE"));
    SetInsert(&S2, ToKata("EYA"));

    MapInsert(&M, ToKata("kunci emas"), S1);
    MapInsert(&M, ToKata("kunci rusak"), S2);
    MapInsert(&M, ToKata("kunci akai"), S2);

    DisplayMap(M); printf("\n");

    MapDelete(&M, ToKata("kunci akai"));

    DisplayMap(M); printf("\n");

    DisplayVMap(M, ToKata("kunci emas"));
}