//  LinkedList.h
//  DataStructureWithC
//
//  Created by boyoon choi on 20/11/2021.
//  Copyright © 2021 boyoon choi. All rights reserved.

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType Data;
    struct tagNode* NextNode;
} Node;

//declaration of functions
Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewHead);
void SLL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);

#endif /* LinkedList_h */
