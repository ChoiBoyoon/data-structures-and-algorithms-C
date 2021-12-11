#include "BinarySearchTree.h"

int main(void){
    //create Nodes
    BSTNode* Tree = BST_CreateNode(123);
    BSTNode* Node = NULL;
    
    //Add nodes to Tree
    BST_InsertNode(Tree, BST_CreateNode(22));
    BST_InsertNode(Tree, BST_CreateNode(9918));
    BST_InsertNode(Tree, BST_CreateNode(424));
    BST_InsertNode(Tree, BST_CreateNode(17));
    BST_InsertNode(Tree, BST_CreateNode(3));
    BST_InsertNode(Tree, BST_CreateNode(98));
    BST_InsertNode(Tree, BST_CreateNode(34));
    BST_InsertNode(Tree, BST_CreateNode(760));
    BST_InsertNode(Tree, BST_CreateNode(317));
    BST_InsertNode(Tree, BST_CreateNode(1));
    
    //print Tree
    BST_InorderPrintTree(Tree);
    printf("\n");
    
    //remove Node with Data field of 98
    printf("After removing 98\n");
    Node = BST_RemoveNode(Tree, NULL, 98);
    BST_DestroyNode(Node);
    BST_InorderPrintTree(Tree);
    printf("\n");
    
    //Let's insert a new Node with Data field of 111
    printf("After inserting 111\n");
    BST_InsertNode(Tree, BST_CreateNode(111));
    BST_InorderPrintTree(Tree);
    printf("\n");
    
    //Now let's destroy our Tree
    BST_DestroyTree(Tree);
    
    return 0; //end of main()
}
