#ifndef Heap_h
#define Heap_h

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagHeapNode {
    ElementType Data;
} HeapNode;

typedef struct tagHeap {
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
} Heap;

Heap* HEAP_Create(int InitialSize);
void HEAP_Destroy(Heap* H);
void HEAP_Insert(Heap* H, ElementType NewData);
void HEAP_DeleteMin(Heap* H, HeapNode* Root);
int HEAP_GetParent(int Index);
int HEAP_GetLeftChild(int Index);
void HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void HEAP_PrintNodes(Heap* H);

#endif /* Heap_h */
