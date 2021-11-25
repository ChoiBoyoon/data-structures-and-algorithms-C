## LinkedListStack
> 

* Unlike ArrayStack, we don't need to set limit of size of stack in the beginning.
* 스택의 용량에 제한을 두지 않아도 된다.



**Node** structure
```Python
typedef struct tagNode{
  char* Data; #char* points to the first character of string. (In C, we can use pointer like a string)
              #this one should be assigned in free store (using malloc(strlen(Data)+1)
  struct tagNode* NextNode;
} Node;
```

**(Linked-list) stack** structure
```Python
typedef struct tagLinkedListStack{
  Node* List;
  Node* Top; #in order to avoid sequential search, we use 4 bytes and use pointer "Top"
} LinkedList;
```
