#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData){
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;
    return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node){
    free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root){
    if(Root->LeftChild!=NULL){
        LCRS_DestroyTree(Root->LeftChild); //recursive function
    }
    if(Root->RightSibling!=NULL){
        LCRS_DestroyTree(Root->RightSibling); //recursive function
    }
    Root->LeftChild = NULL;
    Root->RightSibling = NULL;
    
    LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode){
    if(ParentNode->LeftChild==NULL) //if ParentNode doesn't have child node
        ParentNode->LeftChild = ChildNode; //ChildNode becomes its first child node
    else{
        LCRSNode* TempNode = ParentNode->LeftChild; //TempNode is ParentNode's first child node
        while(TempNode->RightSibling!=NULL)
            TempNode = TempNode->RightSibling; //TempNode becomes last child node of ParentNode
        TempNode->RightSibling = ChildNode; //Now ChildNode is the last child node of ParentNode
    }
}

void LCRS_PrintTree(LCRSNode* Node, int Depth){
    int i = 0;
    for(i=0; i<Depth; i++)
        printf(" ");
    
    printf("%c\n", Node->Data);
    
    if(Node->LeftChild!=NULL)
        LCRS_PrintTree(Node->LeftChild, Depth+1); //recursive function
    
    if(Node->RightSibling!=NULL)
        LCRS_PrintTree(Node->RightSibling, Depth); //recursive function
}
