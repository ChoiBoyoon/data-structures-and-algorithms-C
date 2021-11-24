#include "ArrayStack.h"

int main(void){
    int i=0;
    ArrayStack* Stack = NULL;
    
    AS_CreateStack(&Stack, 10); //create a stack which can store 10 nodes
    
    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    AS_Push(Stack, 12);
    
    printf("Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));
    
    for(i=0; i<4; i++){
        if(AS_IsEmpty(Stack)) //if Stack is empty, get out of this for loop
            break;
        printf("Popped: %d\n", AS_Pop(Stack));
        
        if(!AS_IsEmpty(Stack)) //if Stack is not empty
            printf("Current Top: %d\n", AS_Top(Stack));
        else
            printf("Stack is empty.\n");
    }
    
    AS_DestroyStack(Stack);
    
    return 0; //end of main()
}
