#include "ExpressionTree.h"

int main(void){
    ETNode* Root = NULL;
    char PostfixExpression[20] = "72*52-/";
    ET_BuildExpressionTree(PostfixExpression, &Root);
    
    //print Tree
    printf("Preorder...\n");
    ET_PreorderPrintTree(Root);
    printf("\n\n");
    
    printf("Inorder...\n");
    ET_InorderPrintTree(Root);
    printf("\n\n");
    
    printf("Postorder...\n");
    ET_PostorderPrintTree(Root);
    printf("\n\n");
    
    printf("Evaluation Result: %f \n", ET_Evaluate(Root));
    
    //destroy the tree
    ET_DestroyTree(Root);
    
    return 0;
}
