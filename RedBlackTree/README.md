## Red Black Tree
> 이진 탐색 트리가 균형을 잘 잡아 자랄 수 있게 해줌.

* 노트를 빨간색 또는 검은색으로 표시



### 규칙
1. 모든 노드는 빨간색 아니면 검은색이다.
2. 루트 노드는 검은색이다.
3. 잎 노드는 검은색이다.
4. 빨간 노드의 자식들은 모두 검은색이다.
5. 루트 노드에서 모든 잎 노드 사이에 있는 검은색 노드의 수는 모두 동일하다.

![image](https://user-images.githubusercontent.com/22133824/146392660-ed7f628e-d530-4589-957b-e83d457157eb.png)

<i>* <b>NIL node</b>: 아무 데이터도 갖고 있지 않지만 색깔만 검은색인 더미 노드. 레드 블랙 트리를 구현하기 쉽게 하기 위해 존재</i>

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
