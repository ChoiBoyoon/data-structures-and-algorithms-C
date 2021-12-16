## Red Black Tree
> 이진 탐색 트리가 균형을 잘 잡아 자랄 수 있게 해줌.

* 노트를 빨간색 또는 검은색으로 표시

```C
structure of struct of node
typedef struct tagRBTNode{
  struct tagRBTNode* Parent; //삽입, 삭제 연산을 수행할 때 요긴하게 사용됨
  struct tagRBTNode* Left;
  struct tagRBTNode* Right;
  
  enum{ RED, BLACK } Color;
  
  ElementType Data;
}
```
