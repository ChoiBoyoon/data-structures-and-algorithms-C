#include "BinaryTree.h"

int main(void){
    //create 7 nodes
    SBTNode* A = SBT_CreateNode('A');
    SBTNode* B = SBT_CreateNode('B');
    SBTNode* C = SBT_CreateNode('C');
    SBTNode* D = SBT_CreateNode('D');
    SBTNode* E = SBT_CreateNode('E');
    SBTNode* F = SBT_CreateNode('F');
    SBTNode* G = SBT_CreateNode('G');
    
    //make a tree
    A->LeftNode = B;
    B->LeftNode = C;
    B->RightNode = D;
    
    A->RightNode = E;
    E->LeftNode = F;
    E->RightNode = G;
    
    //print the tree
    printf("Preorder...\n");
    SBT_PreorderPrintTree(A);
    printf("\n\n");
    
    printf("Inorder...\n");
    SBT_InorderPrintTree(A);
    printf("\n\n");
    
    printf("PostOrder...\n");
    SBT_PostorderPrintTree(A);
    printf("\n\n");
    
    //now let's destroy the tree
    SBT_DestroyTree(A);
    
    return 0; //end of main()
    
    
}
