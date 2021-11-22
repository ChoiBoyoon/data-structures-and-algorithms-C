//  DoublyLinkedList.h
//  DataStructureWithC
//
//  Created by boyoon choi on 22/11/2021.
//  Copyright © 2021 boyoon choi. All rights reserved.


#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType Data;
    struct tagNode* PrevNode; //pointer pointing to previous node
    struct tagNode* NextNode;
} Node;

//declaration of functions
Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, Node* NewNode);
void DLL_InsertAfter(Node* Current, Node* NewNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);

#endif /* DoublyLinkedList_h */
