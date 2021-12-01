#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode{
    struct tagSBTNode* LeftNode;
    struct tagSBTNode* RightNode;
    ElementType Data;
} SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData);
void SBT_DestroyNode(SBTNode* Node);
void SBT_DestroyTree(SBTNode* Root); //해당 노드와 해당 노드의 하위 트리를 destroy

void SBT_PreorderPrintTree(SBTNode* Node);
void SBT_InorderPrintTree(SBTNode* Node);
void SBT_PostorderPrintTree(SBTNode* Node);

#endif /* BinaryTree_h */
