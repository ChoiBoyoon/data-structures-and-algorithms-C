//
//  main.c
//  DataStructureWithC
//
//  Created by boyoon choi on 20/11/2021.
//  Copyright © 2021 boyoon choi. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

int main(void) {
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;
    
    //add 5 new nodes
    for(i=0; i<5; i++){
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }
    
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);
    
    //print the list created above
    Count = SLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
        
    }
    
    //insert new node after 3rd node in the list
    printf("\nInserting 3000 after [2]...\n\n");
    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);
    SLL_InsertAfter(Current, NewNode);
    
    //print the list
    Count=SLL_GetNodeCount(List);
    for(i=0; i<Count; i++){
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }
    
    //remove and destroy every node in the list
    printf("\nDestroying List...\n");
    for(i=0; i<Count; i++){
        Current = SLL_GetNodeAt(List, 0);
        if(Current != NULL){
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
    
    return 0;
}
