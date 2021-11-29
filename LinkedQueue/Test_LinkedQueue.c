#include "LinkedQueue.h"

int main(void){
    Node* Popped;
    LinkedQueue* Queue;
    
    LQ_CreateQueue(&Queue);
    
    LQ_Enqueue(Queue, LQ_CreateNode("A"));
    LQ_Enqueue(Queue, LQ_CreateNode("B"));
    LQ_Enqueue(Queue, LQ_CreateNode("C"));
    LQ_Enqueue(Queue, LQ_CreateNode("D"));
    
    printf("Queue Size: %d\n", Queue->Count);
    
    while(!LQ_IsEmpty(Queue)){ //escapes when Queue becomes empty
        Popped = LQ_Dequeue(Queue);
        printf("Dequeue : %s\n", Popped->Data);
        LQ_DestroyNode(Popped);
    }
    
    LQ_DestroyQueue(Queue);
    
    return 0; //end of main()
}
