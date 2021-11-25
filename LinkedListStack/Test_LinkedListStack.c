#include "LinkedListStack.h"

int main(void){
    int i = 0;
    int Count = 0;
    Node* Popped;
    LinkedListStack* Stack;
    
    //create stack
    LLS_CreateStack(&Stack);
    
    //add 4 nodes into the stack
    LLS_Push(Stack, LLS_CreateNode("1st node"));
    LLS_Push(Stack, LLS_CreateNode("2nd node"));
    LLS_Push(Stack, LLS_CreateNode("3rd node"));
    LLS_Push(Stack, LLS_CreateNode("4th node"));
    
    Count = LLS_GetSize(Stack);
    printf("Size: %d, Top: %s\n\n", Count, LLS_Top(Stack)->Data);
    
    for(i=0; i<Count; i++){
        if(LLS_IsEmpty(Stack)) //prevent error
            break;
        Popped = LLS_Pop(Stack);
        printf("Popped: %s\n", Popped->Data);
        LLS_DestroyNode(Popped);
        
        if(!LLS_IsEmpty(Stack)) //if stack is not empty
            printf("Currnet Top: %s\n\n", LLS_Top(Stack)->Data);
        else    //if stack is empty
            printf("Stack is empty.\n\n");
        
    }
    LLS_DestroyStack(Stack);
    
    return 0; //end of main()
    
}
