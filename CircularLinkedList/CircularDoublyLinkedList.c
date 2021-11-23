#include "CircularDoublyLinkedList.h"

//create a new node on free store with malloc()
Node* CDLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL; //initialize pointers as NULL
    NewNode->NextNode = NULL;
    return NewNode; //return memory address of newly created node
}

//destroy node from free store with free()
void CDLL_DestroyNode(Node* Node){
    free(Node);
}

//append a node to an existing list(new node becomes a tail node)
void CDLL_AppendNode(Node** Head, Node* NewNode){
    //if a given list is empty
    if((*Head)==NULL){ //in circular list, no node points to NULL
        *Head = NewNode;
        (*Head)->NextNode = (*Head);
        (*Head)->PrevNode = (*Head);
    }
    else{
        //insert new node between head and tail
        Node* Tail = (*Head)->PrevNode; //getting to tail node is easier
        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;
        
        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail; //NewNode becomes the tail node
    }
}

//insert NewNode after Current node
void CDLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;
    
    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

//remove node from a given list
void CDLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head==Remove){
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;
        
        *Head = Remove->NextNode;
        
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else{
        Node* Temp = Remove;
        Remove->PrevNode->NextNode = Temp->NextNode;
        Remove->NextNode->PrevNode = Temp->PrevNode;
        
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}

//get node at n-th location
Node* CDLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    while(Current!=NULL && (--Location)>=0){
        Current = Current->NextNode;
    }//so that Current points to n-th node
    return Current; //return the memory address of n-th node
}

//count number of nodes in a given list
int CDLL_GetNodeCount(Node* Head){
    unsigned int Count = 0;
    Node* Current = Head;
    
    while(Current != NULL){ //repeat until Current points to tail node
        Current = Current->NextNode;
        Count++;
        
        if(Current==Head) //if there's only one node un the list, Current->NextNode is still head node
            break;
    }
    return Count;
}

//print data stored on prev node, current node, and next node
void PrintNode(Node* _Node){
    if(_Node->PrevNode==NULL)
        printf("Prev: NULL");
    else
        printf("Prev: %d", _Node->PrevNode->Data);
    
    printf("Current: %d", _Node->Data);
    
    if(_Node->NextNode==NULL)
        printf("Next: NULL");
    else
        printf("Next: %d", _Node->NextNode->Data);
}
