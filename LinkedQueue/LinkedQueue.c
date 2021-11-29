#include "LinkedQueue.h"

//create queue on free store and initialize its fields
void LQ_CreateQueue(LinkedQueue** Queue){
    //create queue on free store with malloc()
    (*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL; //field initialization
    (*Queue)->Count = 0;
}

//destroy queue and its nodes
void LQ_DestroyQueue(LinkedQueue* Queue){
    while(!LQ_IsEmpty(Queue)){ //escapes when Queue becomes empty
        Node* Popped = LQ_Dequeue(Queue);
        LQ_DestroyNode(Popped);
    }
    free(Queue);
}

//create new node. as datatype here is string, we need to call malloc() 2 times.
Node* LQ_CreateNode(char* NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData)+1);
    
    strcpy((NewNode)->Data, NewData);
    (NewNode)->NextNode = NULL;
    
    return NewNode;
}

//destroy(=free) string (_Node->Data) and node itself from free store
void LQ_DestroyNode(Node* _Node){
    free(_Node->Data);
    free(_Node);
}

//enqueue(add NewNode to rear of the queue)
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode){
    if(Queue->Front == NULL){ //if queue is empty, NewNode is Front node
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
    }
    else{
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
    }
    Queue->Count++;
}

//dequeue(remove front node from the queue)
Node* LQ_Dequeue(LinkedQueue* Queue){
    Node* Front = Queue->Front; //front node to be removed and returned
    
    if(Queue->Front == NULL) //if Queue is empty, return NULL (we don't do Count-- here)
        return Front;
    else if(Queue->Front->NextNode == NULL){ //if there's only one node in the queue,
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else{
        Queue->Front = Queue->Front->NextNode;
    }
    Queue->Count--;
    return Front;
}

//check if the queue is empty
int LQ_IsEmpty(LinkedQueue* Queue){
    return (Queue->Front)==NULL;
}
