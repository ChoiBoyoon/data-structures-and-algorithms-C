#include "DoublyLinkedList.h"

int main(void){
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;
    
    //create 5 new nodes, and append to List
    for(i=0; i<5; i++){
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }
    
    //print the list
    Count = DLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }
    
    //insert a new node after 3rd node in the list
    printf("\nInserting 3000 after [2]...\n\n");
    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(Current, NewNode);
    
    //print the list again
    Count = DLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }
    
    //remove all nodes from the list and destroy them (from free store)
    printf("\nDestroying List...\n");
    Count = DLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = DLL_GetNodeAt(List, i);
        if(Current!=NULL){
            DLL_RemoveNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }
    
    return 0; //end of main()
}
