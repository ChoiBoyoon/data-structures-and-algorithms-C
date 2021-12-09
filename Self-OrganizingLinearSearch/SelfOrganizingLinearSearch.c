#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//Linear search (=sequential search, time complexity O(n)
//data type is int in this case
Node* SLL_LinearSearch(Node* Head, int Target){
    Node* Current = Head;
    Node* Match = NULL; //address of Node to be returned
    
    while(Current!=NULL){
        if(Current->Data==Target){
            Match = Current;
        }
        else
            Current = Current->NextNode;
    }
    return Match;
}

//Move to front method. After searching an item, move it to front
Node* SLL_MoveToFront(Node** Head, int Target){
    Node* Current = (*Head);
    Node* Previous = NULL;
    Node* Match = NULL;
    
    while(Current != NULL){
        if(Current->Data==Target){
            Match = Current;
            if(Previous != NULL){
                Previous->NextNode = Current->NextNode;
                Current->NextNode=(*Head);
                (*Head)=Current;
            }
            break;
        }
        else{
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}

//Transpose method. After searching an item, move it one forward.
Node* SLL_Transpose(Node** Head, int Target){
    Node* Current = (*Head);
    Node* PPrevious = NULL;
    Node* Previous = NULL;
    Node* Match = NULL;
    
    while(Current != NULL){
        if(Current->Data == Target){
            Match = Current;
            if(Current != (*Head)){
                Previous->NextNode = Current->NextNode;
                Current->NextNode = Previous;
                if(PPrevious != NULL)
                    PPrevious->NextNode = Current;
                else
                    (*Head) = Current;
            }
            break;
        }
        else{
            if(PPrevious != NULL)
                PPrevious = Previous;
            Previous = Current;
            Current = Current->NextNode;
        }
    }
    return Match;
}

