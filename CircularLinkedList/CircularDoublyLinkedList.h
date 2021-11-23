#ifndef CircularDoublyLinkedList_h
#define CircularDoublyLinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; //change this line if element type should be modified

typedef struct tagNode{ //same as doubly linked list
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

//declaration of functions
Node* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
void CDLL_RemoveNode(Node** Head, Node* Remove);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void PrintNode(Node* _Node);

#endif /* CircularDoublyLinkedList_h */
