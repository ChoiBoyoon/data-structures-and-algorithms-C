#ifndef LinkedQueue_h
#define LinkedQueue_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode{
    char* Data;
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue{
    Node* Front;
    Node* Rear;
    int Count;
} LinkedQueue;

//declaration of functions
void LQ_CreateQueue(LinkedQueue** Queue);
void LQ_DestroyQueue(LinkedQueue* Queue);

Node* LQ_CreateNode(char* NewData);
void LQ_DestroyNode(Node* _Node);

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);

int LQ_IsEmpty(LinkedQueue* Queue);

#endif /* LinkedQueue_h */
