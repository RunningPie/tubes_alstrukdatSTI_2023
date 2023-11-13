#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"


ArrayDin MakeArrayDin()
{
    ArrayDin array;
    array.A         = (ElType*)(malloc(InitialSize*(sizeof(ElType))));
    array.Capacity  = InitialSize;
    array.Neff      = 0;
    return array;
}

void DeallocateArrayDin(ArrayDin *array)
{
    free((*array).A);
    (*array).Capacity = 0;
    (*array).Neff     = 0;
}

boolean IsEmptyArrDin(ArrayDin array)
{
    return (array.Neff == 0);
}

int LengthArrDin(ArrayDin array)
{
    return (array.Neff);
}

ElType GetArrDin(ArrayDin array, IdxType i)
{
    return ((array.A)[i]);
}

int GetCapacityArrDin(ArrayDin array)
{
    return array.Capacity;
}

void InsertAtArrDin(ArrayDin *array, ElType el, IdxType i)
{
    if((*array).Neff == (*array).Capacity)
    {
        (*array).A         = realloc((*array).A, 2*((*array).Capacity)*sizeof(ElType));
        (*array).Capacity *= 2;
    }
    
    for(int j = (*array).Neff; j > i; j--)
    {
        ((*array).A)[j] = ((*array).A)[j-1];
    }
    ((*array).A)[i] = el;
    (*array).Neff++;
}

void InsertLastArrDin(ArrayDin *array, ElType el)
{
    InsertAtArrDin(array, el, (*array).Neff);
}

void InsertFirstArrDin(ArrayDin *array, ElType el)
{
    InsertAtArrDin(array, el, 0);
}

void DeleteAtArrDin(ArrayDin *array, IdxType i)
{
    for(int j = i; j < (*array).Neff - 1; j++)
    {
        (*array).A[j] = (*array).A[j+1]; 
    }
    (*array).Neff--;
}

void DeleteLastArrDin(ArrayDin *array)
{
    DeleteAtArrDin(array, (*array).Neff - 1);
}

void DeleteFirstArrDin(ArrayDin *array)
{
    DeleteAtArrDin(array, 0);
}

void PrintArrayDin(ArrayDin array)
{
    printf("[");
    for(int i = 0; i < array.Neff-1; i++)
    {
        printf("%d, ", array.A[i]);
    }
    if(array.Neff) printf("%d]\n", array.A[array.Neff-1]);
    else printf("]\n");
}

void ReverseArrayDin(ArrayDin *array)
{
    for(int i = 0; i < (*array).Neff/2; i++)
    {
        ElType temp = (*array).A[i];
        (*array).A[i] = (*array).A[(*array).Neff-i-1];
        (*array).A[(*array).Neff-i-1] = temp; 
    }
}

ArrayDin CopyArrayDin(ArrayDin array)
{
    return array;
}

IdxType SearchArrayDin(ArrayDin array, ElType el)
{
    for(int i = 0; i < array.Neff; i++)
    {
        if(isWordEq(array.A[i], el)) return i;
    }
    return -1;
}

