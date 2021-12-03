#include "DisjointSet.h"

//make Set2 point to Set1
void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2){
    Set2 = DS_FindSet(Set2);
    Set2->Parent = Set1;
}

//return Root of the Set
DisjointSet* DS_FindSet(DisjointSet* Set){
    while(Set->Parent!=NULL){
        Set = Set->Parent;
    }
    return Set;
}

//create new node(new set)
DisjointSet* DS_MakeSet(void* NewData){
    DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet));
    NewNode->Data = NewData;
    NewNode->Parent = NULL;
    return NewNode;
}

//destroy theset
void DS_DestroySet(DisjointSet* Set){
    free(Set);
}
