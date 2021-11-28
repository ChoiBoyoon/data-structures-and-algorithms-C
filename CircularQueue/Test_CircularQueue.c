#include "CircularQueue.h"

int main(void){
    int i;
    CircularQueue* Queue;
    
    //create a queue with capacity of 10
    CQ_CreateQueue(&Queue, 10);
    
    //enqueue 4 data nodes
    CQ_Enqueue(Queue, 1);
    CQ_Enqueue(Queue, 2);
    CQ_Enqueue(Queue, 3);
    CQ_Enqueue(Queue, 4);
    
    for(i=0; i<3; i++){
        printf("Dequeue: %d, ", CQ_Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
    }
    
    //add new nodes to the queue until full
    i = 100;
    while(CQ_IsFull(Queue)==0){ //stops when the queue gets full
        CQ_Enqueue(Queue, i++);
    }
    
    //print and dequeue all the nodes in the queue
    printf("Capacity : %d, Size: %d\n\n", Queue->Capacity, CQ_GetSize(Queue));
    while(CQ_IsEmpty(Queue)==0){ //stops when the queue gets empty
        printf("Dequeue: %d, ", CQ_Dequeue(Queue));
        printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
    }
    
    //now destroy queue and its nodes
    CQ_DestroyQueue(Queue);
    
    return 0; //end of program
}
