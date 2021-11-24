#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType Data;
    //location of nodes is known by index of array -> we don't need pointer
} Node;

typedef struct tagArrayStack{
    int Capacity;   //size of stack
    int Top;        //location of top node
    Node* Nodes;    //Nodes points to first element of array assigned in free store. In C language, pointer can be used like an array.
} ArrayStack;

//declaration of functions
void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop(ArrayStack* Stack);
ElementType AS_Top(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);

#endif /* ArrayStack_h */
