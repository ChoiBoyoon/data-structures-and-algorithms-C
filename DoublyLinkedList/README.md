### 더블 링크드 리스트(Doubly Linked List) : 링크드 리스트의 탐색 기능을 개선한 자료구조. (양방향 탐색이 가능)
각 노드는 자신의 앞에 있는 노드를 가리키는 포인터도 갖고 있음.

```
typedef struct tagNode{
    ElementType Data;
    struct tagNode* PrevNode; //pointer pointing to previous node
    struct tagNode* NextNode;
} Node;
```
