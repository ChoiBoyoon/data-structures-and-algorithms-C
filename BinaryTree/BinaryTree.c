#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType NewData){
    SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
    NewNode->LeftNode = NULL;
    NewNode->RightNode = NULL;
    NewNode->Data = NewData;
    
    return NewNode;
}

void SBT_DestroyNode(SBTNode* Node){
    free(Node);
}

void SBT_DestroyTree(SBTNode* Root){
    if(Root==NULL)
        return;
    if(Root->LeftNode!=NULL)
        SBT_DestroyTree(Root->LeftNode);
    if(Root->RightNode!=NULL)
        SBT_DestroyTree(Root->RightNode);
    SBT_DestroyNode(Root);
        
}

void SBT_PreorderPrintTree(SBTNode* Node){
    if(Node==NULL)
        return;
    //print root node
    printf(" %c", Node->Data);
    
    //print left subtree
    SBT_PreorderPrintTree(Node->LeftNode);
    
    //print right subtree
    SBT_PreorderPrintTree(Node->RightNode);
}

void SBT_InorderPrintTree(SBTNode* Node){
    if(Node==NULL)
        return;
    //print left subtree
    SBT_InorderPrintTree(Node->LeftNode);
    
    //print root node
    printf(" %c", Node->Data);
    
    //print right subtree
    SBT_InorderPrintTree(Node->RightNode);
}

void SBT_PostorderPrintTree(SBTNode* Node){
    if(Node==NULL)
        return;
    //print left subtree
    SBT_PostorderPrintTree(Node->LeftNode);
    
    //print right subtree
    SBT_PostorderPrintTree(Node->RightNode);
    
    //print root node
    printf(" %c", Node->Data);
}
