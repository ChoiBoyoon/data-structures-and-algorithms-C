#include "LinkedList.h"

//create new Node
Node* SLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node)); //create new Node on automatic memory
    NewNode->Data=NewData;
    NewNode->NextNode=NULL; //pointer to next node, initialized as NULL
    
    return NewNode; //return memory address of newly created Node
}

//destroy Node
void SLL_DestroyNode(Node* Node){
    free(Node);
}

//append Node to existing list
void SLL_AppendNode(Node** Head, Node* NewNode){
    if((*Head)==NULL){ //if Head is NULL (List is empty), NewNode becomes Head
        *Head=NewNode;
    }
    else{ //find Tail and append New Node
        Node* Tail = (*Head);
        while(Tail->NextNode != NULL){ //escapes while when Tail variable locates tail node
            Tail = Tail->NextNode; //move to next node
        }
        Tail->NextNode=NewNode; //"NewNode" becomes new tail node
    }
}

//Insert NewNode after Current node
void SLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode->NextNode=Current->NextNode;
    Current->NextNode=NewNode;
}

//Insert new head node
void SLL_InsertNewHead(Node** Head, Node* NewHead){
    if(*Head==NULL){ //if it's already an empty list
        (*Head) = NewHead; //NewHead is head now
    }
    else{
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

//Remove Node.
//better call SLL_DestroyNode() after this function.
void SLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head==Remove){ //if Head should be removed
        *Head=Remove->NextNode; //unlink Head
    }
    else{
        Node* Current = *Head;
        while(Current!=NULL && Current->NextNode!=Remove){
            Current=Current->NextNode; //locate Remove node
        }
        if(Current!=NULL){
            Current->NextNode=Remove->NextNode; //unlink
        }
    }
}

//Search Node at n-th location.
//one of shortcomings of linked list. time complexity: O(n)
Node* SLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    while(Current!=NULL && (--Location)>=0){
        Current=Current->NextNode; //locate n-th node
    }
    return Current;
}

//count Nodes in list
int SLL_GetNodeCount(Node* Head){
    int Count = 0;
    Node* Current = Head;
    while(Current!=NULL){ //stops right after Current reaches tail node
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}
