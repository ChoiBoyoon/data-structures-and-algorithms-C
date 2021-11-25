## LinkedListStack
> 

* Unlike ArrayStack, we don't need to set limit of size of stack in the beginning.
* 스택의 용량에 제한을 두지 않아도 된다.



**Node** structure
```C
typedef struct tagNode{
  char* Data; #char* points to the first character of string. (In C, we can use pointer like a string)
              #this one should be assigned in free store (using malloc(strlen(Data)+1)
  struct tagNode* NextNode;
} Node;
```

**(Linked-list) stack** structure
```C
typedef struct tagLinkedListStack{
  Node* List;
  Node* Top; #in order to avoid sequential search, we use 4 bytes and use pointer "Top"
} LinkedList;


result of the test code:
```
Size: 4, Top: 4th node

Popped: 4th node
Currnet Top: 3rd node

Popped: 3rd node
Currnet Top: 2nd node

Popped: 2nd node
Currnet Top: 1st node

Popped: 1st node
Stack is empty.

Program ended with exit code: 0
```
