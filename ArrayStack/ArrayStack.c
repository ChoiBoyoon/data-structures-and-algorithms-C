#include "ArrayStack.h"

//create a stack and its nodes on free store with malloc()
void AS_CreateStack(ArrayStack** Stack, int Capacity){
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);
    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = 0;
}

//destroy a stack and its nodes from free store with free()
void AS_DestroyStack(ArrayStack* Stack){
    free(Stack->Nodes); //destroy nodes first
    free(Stack);        //and destroy stack
}

//Push a node into(or "on top of") the stack
void AS_Push(ArrayStack* Stack, ElementType Data){
    int Position = Stack->Top;
    Stack->Nodes[Position].Data = Data;
    Stack->Top++;
}

//Pop a top node (remove it from a stack and return the removed node)
ElementType AS_Pop(ArrayStack* Stack){
    int Position = --(Stack->Top);
    return Stack->Nodes[Position].Data;
}

//return the Data field of top node
ElementType AS_Top(ArrayStack* Stack){
    int Position = Stack->Top -1;
    return Stack->Nodes[Position].Data;
}

//Get the size of the array(number of nodes in the stack)
int AS_GetSize(ArrayStack* Stack){
    return Stack->Top;
}

//return 1 is the stack is empty. In C language True is 1, False is 0 (int)
int AS_IsEmpty(ArrayStack* Stack){
    return (Stack->Top==0);
}
