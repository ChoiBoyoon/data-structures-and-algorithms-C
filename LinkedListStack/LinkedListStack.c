#include "LinkedListStack.h"

//create stack on free store with malloc()
void LLS_CreateStack(LinkedListStack** Stack){
    (*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}

//destroy stack from free store using malloc()
void LLS_DestroyStack(LinkedListStack* Stack){
    while(!LLS_IsEmpty(Stack)){ //repeat until stack becomes empty
        Node* Popped = LLS_Pop(Stack);
        LLS_DestroyNode(Popped);
    }
    free(Stack);
}

//create a node. Data type is string -> we call malloc() 2 times
Node* LLS_CreateNode(char* NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = (char*)malloc(strlen(NewData)+1); //+1 for '\0'
    strcpy(NewNode->Data, NewData); //copy the string to Data field
    NewNode->NextNode = NULL;
    return NewNode; //return the address
}

//two pointers in node -> we call free() 2 times
void LLS_DestroyNode(Node* _Node){
    free(_Node->Data);
    free(_Node->NextNode);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode){
    if(Stack->List == NULL){ //if head node is empty(if stack is empty)
        Stack->List = NewNode;
    }
    else{
        Node* CurrentTop = Stack->List; //locate top node
        while(CurrentTop->NextNode!=NULL){
            CurrentTop = CurrentTop->NextNode;
        }
        CurrentTop->NextNode = NewNode; //new node becomes new top node
    }
    Stack->Top = NewNode; //update Top field of Stack as well
}

//remove top node from the stack and return it
Node* LLS_Pop(LinkedListStack* Stack){
    Node* TopNode = Stack->Top; //node to be removed and returned
    if(Stack->List == Stack->Top){ //if there's only one node in the stack
        Stack->List = NULL; //this stack becomes an empty stack
        Stack->Top = NULL;
    }
    else{
        Node* NewTop = Stack->List; //NewTop will be new top node
        while(NewTop!=NULL && NewTop->NextNode!=Stack->Top){ //locate 2nd last node
            NewTop = NewTop->NextNode;
        }
        Stack->Top = NewTop;
        NewTop->NextNode = NULL; //this line is not entirely necessary
    }
    return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack){
    return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack){
    int Count = 0;
    Node* Current = Stack->List;
    while(Current!=NULL){
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}

//if the stack is empty, return 1, else 0
int LLS_IsEmpty(LinkedListStack* Stack){
    return ((Stack->List)==NULL);
}
