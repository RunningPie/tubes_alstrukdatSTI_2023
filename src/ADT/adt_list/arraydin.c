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

boolean IsEmpty(ArrayDin array)
{
    return (array.Neff == 0);
}

int Length(ArrayDin array)
{
    return (array.Neff);
}

ElType Get(ArrayDin array, IdxType i)
{
    return ((array.A)[i]);
}

int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i)
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

void InsertLast(ArrayDin *array, ElType el)
{
    InsertAt(array, el, (*array).Neff);
}

void InsertFirst(ArrayDin *array, ElType el)
{
    InsertAt(array, el, 0);
}

void DeleteAt(ArrayDin *array, IdxType i)
{
    for(int j = i; j < (*array).Neff - 1; j++)
    {
        (*array).A[j] = (*array).A[j+1]; 
    }
    (*array).Neff--;
}

void DeleteLast(ArrayDin *array)
{
    DeleteAt(array, (*array).Neff - 1);
}

void DeleteFirst(ArrayDin *array)
{
    DeleteAt(array, 0);
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
        if(array.A[i] == el) return i;
    }
    return -1;
}

