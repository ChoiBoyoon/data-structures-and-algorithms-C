#include "CircularQueue.h"

//create queue (on free store)
void CQ_CreateQueue(CircularQueue** Queue, int Capacity){
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity+1));
    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

//destroy queue and its nodes from free store (with free())
void CQ_DestroyQueue(CircularQueue* Queue){
    free(Queue->Nodes);
    free(Queue);
}

//add data into the queue
void CQ_Enqueue(CircularQueue* Queue, ElementType Data){
    int Position = 0; //position of rear(where enqueue happens)
    if(Queue->Rear == Queue->Capacity){ //if rear reached the end of queue, set it to 0
        Position = Queue->Rear;
        Queue->Rear = 0;
    }
    else
        Position = Queue->Rear++;
    Queue->Nodes[Position].Data = Data;
}

//remove and return a data from queue
ElementType CQ_Dequeue(CircularQueue* Queue){
    int Position = Queue->Front; //position of front(where dequeue happens)
    if(Queue->Front == Queue->Capacity) //if front reached the end of queue, set it to 0
        Queue->Front=0;
    else
        Queue->Front++;
    return Queue->Nodes[Position].Data;
}

//return number of nodes inside the queue
int CQ_GetSize(CircularQueue* Queue){
    if(Queue->Front <= Queue->Front)
        return Queue->Rear - Queue->Front;
    else
        return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

//return 1 if the queue is empty
int CQ_IsEmpty(CircularQueue* Queue){
    return (Queue->Front == Queue->Rear);//if (front==rear) is True, the queue is empty
                                         //if (front==rear+1) is True, the queue is full
}

//return 1 if the queue is full
int CQ_IsFull(CircularQueue* Queue){
    if(Queue->Front < Queue->Rear)
        return (Queue->Rear - Queue->Front) == Queue->Capacity;
    else
        return (Queue->Rear+1) == Queue->Front;
}
