#include "Calculator.h"

char NUMBER[] = {'0','1','2','3','4','5','6','7','8','9','.'}; //we get input as string type

//check is Cipher is number. if it's number, return 1
int IsNumber(char Cipher){
    int i = 0;
    int ArrayLength = sizeof(NUMBER);
    
    for(i=0; i<ArrayLength; i++){
        if(Cipher == NUMBER[i]) //is Cipher is one of NUMBER[] characters
            return 1; //return 1(True)
    }
    return 0; //return 0(False)
}

unsigned int GetNextToken(char* Expression, char* Token, int* TYPE){
    unsigned int i = 0;
    for(i=0; 0!=Expression[i]; i++){
        Token[i] = Expression[i];
        if(IsNumber(Expression[i+1]) != 1){
            *TYPE = OPERAND;
            if(IsNumber(Expression[i+1] != 1))
                break;
        }
        else{
            *TYPE = Expression[i];
            break;
        }
    } //end of for()
    Token[++i] = '\0'; //bc token is a string
    return i;
}

//convert operator priority to numbers so that we can compare them
int GetPriority(char Operator, int InStack){
    int Priority = -1;
    switch(Operator){
        case LEFT_PARENTHESIS:
            if(InStack)
                Priority = 3;
            else
                Priority = 0;
            break;
        case MULTIPLY: //* and / have same priority
        case DIVIDE:
            Priority = 1;
            break;
        case PLUS:  //+ and - have same priority
        case MINUS:
            Priority = 2;
            break;
    } //end of switch
    return Priority;
}

//check if the first operator is prior to the second operator.
int IsPrior(char OperatorInStack, char OperatorInToken){
    return (GetPriority(OperatorInStack,1)>GetPriority(OperatorInToken, 0));
}

//convert infix to postfix. no return, write result string on a given address.
void GetPostfix(char* InfixExpression, char* PostfixExpression){
    LinkedListStack* Stack;
    
    char Token[32]; //32 chars should be enough
    int Type = -1;
    unsigned int Position = 0;
    unsigned int Length = (int)strlen(InfixExpression);
    
    LLS_CreateStack(&Stack);
    
    while(Position<Length){
        Position += GetNextToken(InfixExpression, Token, &Type);
        if(Type==OPERAND){
            strcat(PostfixExpression, Token); //concatenation
            strcat(PostfixExpression, " ");
        }
        else if(Type == RIGHT_PARENTHESIS){
            while(!LLS_IsEmpty(Stack)){
                Node* Popped = LLS_Pop(Stack);
                if(Popped->Data[0]==LEFT_PARENTHESIS){
                    LLS_DestroyNode(Popped);
                    break;
                }
                else{
                    strcat(PostfixExpression, Popped->Data);
                    LLS_DestroyNode(Popped);
                }
            }//end of while
        } //end of else if(Type == RIGHT_PARENTHESIS)
        else{
            while(!LLS_IsEmpty(Stack) && !IsPrior(LLS_Top(Stack)->Data[0], Token[0])){
                Node* Popped = LLS_Pop(Stack);
                if(Popped->Data[0] != LEFT_PARENTHESIS)
                    strcat(PostfixExpression, Popped->Data);
                LLS_DestroyNode(Popped);
            }
            LLS_Push(Stack, LLS_CreateNode(Token));
        } //end of else
    } // end of while(Position<Length)
    
    while(!LLS_IsEmpty(Stack)){ //write leftovers in stack to PostfixExpression
        Node* Popped = LLS_Pop(Stack);
        if(Popped->Data[0] != LEFT_PARENTHESIS)
            strcat(PostfixExpression, Popped->Data);
        LLS_DestroyNode(Popped);
    }
    
    LLS_DestroyStack(Stack); //we no longer need stack, manually destroy
}

//do the calculation. input: postfix expression
double Calculate(char* PostfixExpression){
    LinkedListStack* Stack;
    Node* ResultNode;
    
    double Result;
    char Token[32];
    int Type = -1;
    unsigned int Read = 0;
    unsigned int Length = (int)strlen(PostfixExpression);
    
    LLS_CreateStack(&Stack);
    
    while(Read < Length){
        Read += GetNextToken(PostfixExpression, Token, &Type);
        if(Type == SPACE)
            continue;
        if(Type == OPERAND){ //number
            Node* NewNode = LLS_CreateNode(Token);
            LLS_Push(Stack, NewNode);
        }
        else{ //Type==OPERATOR
            char ResultString[32];
            double Operator1, Operator2, TempResult = 0.0;
            Node* OperatorNode;
            
            OperatorNode = LLS_Pop(Stack);
            Operator2 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);
            
            OperatorNode = LLS_Pop(Stack);
            Operator1 = atof(OperatorNode->Data);
            LLS_DestroyNode(OperatorNode);
            
            switch(Type){
                case PLUS:
                    TempResult = Operator1 + Operator2;
                    break;
                case MINUS:
                    TempResult = Operator1 - Operator2;
                    break;
                case MULTIPLY:
                    TempResult = Operator1 * Operator2;
                    break;
                case DIVIDE:
                    TempResult = Operator1 / Operator2;
                    break;
            } //end of switch
            
            gcvt(TempResult, 10, ResultString); //from double to string
            LLS_Push(Stack, LLS_CreateNode(ResultString));
        } //end of else (when type is operator)
    }//end of while(Read < Length)
    
    ResultNode = LLS_Pop(Stack);
    Result = atof(ResultNode->Data);
    LLS_DestroyNode(ResultNode);
    LLS_DestroyStack(Stack); //there was only one node(ResultNode) in the stack
    
    return Result;
} //end of double Calculate(char* PostfixExpression)
