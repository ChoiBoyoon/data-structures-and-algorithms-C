#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(ElementType NewData){
    BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
    NewNode->Right = NULL;
    NewNode->Left = NULL;
    NewNode->Data = NewData;
    
    return NewNode;
}

void BST_DestroyNode(BSTNode* Node){
    free(Node);
}

void BST_DestroyTree(BSTNode* Tree){
    if(Tree->Right != NULL)
        BST_DestroyTree(Tree->Right);
    if(Tree->Left != NULL)
        BST_DestroyTree(Tree->Left);
    Tree->Right = NULL;
    Tree->Left = NULL;
    free(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target){
    if(Tree == NULL)
        return NULL;
    if(Tree->Data == Target)
        return Tree;
    else if(Tree->Data > Target)
        return BST_SearchNode(Tree->Right, Target);
    else
        return BST_SearchNode(Tree->Left, Target);
}

BSTNode* BST_SearchMinNode(BSTNode* Tree){
    if(Tree == NULL)
        return NULL;
    if(Tree->Left == NULL)
        return Tree;
    else
        return BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode* Tree, BSTNode* Child){
    if(Tree->Data < Child->Data){
        if(Tree->Right==NULL)
            Tree->Right = Child;
        else
            BST_InsertNode(Tree->Right, Child);
    }
    else if(Tree->Data > Child->Data){
        if(Tree->Left==NULL)
            Tree->Left = Child;
        else
            BST_InsertNode(Tree->Left, Child);
    }
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target){
    BSTNode* Removed = NULL;
    
    if(Tree==NULL)
        return NULL;
    
    if(Tree->Data > Target)
        Removed = BST_RemoveNode(Tree->Left, Tree, Target);
    else if(Tree->Data < Target)
        Removed = BST_RemoveNode(Tree->Right, Tree, Target);
    else{ //when we found target
        Removed = Tree;
        
        //if Removed is a leaf node, we just delete it
        if(Tree->Left==NULL && Tree->Right==NULL){
            if(Parent->Left == Tree)
                Parent->Left = NULL;
            else
                Parent->Right = NULL;
        }
        
        //Remove is not a leaf node
        else{
            //Remove has 2 children
            if(Tree->Left!=NULL && Tree->Right!=NULL){
                BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
                MinNode = BST_RemoveNode(Tree, NULL, MinNode->Data);
                Tree->Data = MinNode->Data;
            }
            //Remove has 1 child
            else{
                BSTNode* Temp = NULL;
                if(Tree->Left != NULL)
                    Temp = Tree->Left;
                else
                    Temp = Tree->Right;
                
                if(Parent->Left == Tree)
                    Parent->Left = Temp;
                else
                    Parent->Right = Temp;
            }
        }
    }
    return Removed;
}

void BST_InorderPrintTree(BSTNode* Node){
    if(Node == NULL)
        return;
    
    //print left tree
    BST_InorderPrintTree(Node->Left);
    
    //print root node
    printf("%d ", Node->Data);
    
    //print right tree
    BST_InorderPrintTree(Node->Right);
}
