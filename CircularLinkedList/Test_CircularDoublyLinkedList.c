#include "CircularDoublyLinkedList.h"

int main(void){
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;
    
    //creat 5 nodes
    for(i=0; i<5; i++){
        NewNode = CDLL_CreateNode(i); //CreateNode works fine
        CDLL_AppendNode(&List, NewNode);
        printf("\n");
    }
    
    //print the list "List"
    Count = CDLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = CDLL_GetNodeAt(List, i);
        printf("List [%d] : %d\n", i ,Current->Data);
    }
    
    //insert a new node containing 3000 after 3rd node in the list "List"
    printf("\nInserting 3000 After [2]...\n\n");
    Current = CDLL_GetNodeAt(List,2);
    NewNode = CDLL_CreateNode(3000);
    CDLL_InsertAfter(Current, NewNode);
    
    //print the list "List"
    //in order to check if the list is circular, we loop 2 times (Count*2)
    Count = CDLL_GetNodeCount(List);
    for(i=0; i<Count*2; i++){
        if(i==0) //in the 1st loop, Current points to head node
            Current = List;
        else //after 2nd loop, Current points to next node
            Current = Current->NextNode;
        
        printf("List[%d] : %d\n", i, Current->Data);
    }
    
    //remove all the nodes from the list, and from memory
    printf("\nDestroying the List...\n");
    Count = CDLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = CDLL_GetNodeAt(List, i);
        if(Current!=NULL){
            printf("destroying List[%d] : %d\n",i,Current->Data);
            CDLL_RemoveNode(&List, Current);
            CDLL_DestroyNode(Current);
        }
    }
    printf("\n");
    return 0; //end of main()
}
