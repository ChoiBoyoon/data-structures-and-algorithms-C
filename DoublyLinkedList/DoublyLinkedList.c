#include "DoublyLinkedList.h"

//create a new node
Node* DLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node)); //allocate pointer variable on free store
    
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL; //initialize pointers to NULL
    NewNode->NextNode = NULL;
    
    return NewNode;
}

//destroy a node
void DLL_DestroyNode(Node* Node){
    free(Node);
}

//append a node to a given list
void DLL_AppendNode(Node** Head, Node* NewNode){
    if((*Head)==NULL){ //it Head==NULL(list is empty), NewNode is head node
        *Head = NewNode;
    }
    else{
        Node* Tail = (*Head); //locate tail node
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }
        Tail->NextNode=NewNode;
        NewNode->PrevNode=Tail;
    }
}

//insert a node after a specific node inside a given list
void DLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;
    
    if(Current->NextNode!=NULL){ //if Current is not tail node
        Current->NextNode->PrevNode=NewNode; //if Current is tail node, this line is not necessary
    }
    Current->NextNode=NewNode;
}

//remove an existing node from a given list
void DLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head==Remove){ //if we want to remove head node
        *Head = Remove->NextNode; //new head
        if((*Head)!=NULL)
            (*Head)->PrevNode=NULL;
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else{ //Remove is not a head node
        Node* Temp = Remove;
        if(Remove->PrevNode != NULL)
            Remove->PrevNode->NextNode = Temp->NextNode;
        if(Remove->NextNode != NULL)
            Remove->NextNode->PrevNode = Temp->PrevNode;
        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
}

//get node at a specific location (get n-th node)
Node* DLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    while(Current!=NULL && (--Location)>=0){
        Current = Current->NextNode; //locate the n-th node
    }
    return Current;
}

//count a number of nodes in a given list
int DLL_GetNodeCount(Node* Head){
    unsigned int Count = 0;
    Node* Current = Head;
    while(Current!=NULL){
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}
