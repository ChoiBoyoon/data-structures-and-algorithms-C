## 이진 트리(Binary Tree)
> 모든 노드가 최대 2개의 자식을 가질 수 있는 트리.
> 특수한 자료구조. 자료를 담기 위해서가 아니라 아니라 컴파일러나 검색 등에 사용됨.

#### 사용 예
* **수식 이진 트리(Expression Binary Tree)**: 수식을 트리 형태로 표현하여 계산하게 해줌.
* **이진 탐색 트리(Binary Search Tree)**: 아주 빠른 데이터 검색을 가능하게 함.


![image](https://user-images.githubusercontent.com/22133824/144137096-3e1542c6-015d-4c0a-8a57-013607b87a65.png)

#### 이진 트리의 형태
* **포화 이진 트리(Full Binary Tree)**: 잎 노드들이 모두 같은 깊이에 존재
* **완전 이진 트리(Complete Binary Tree)**: 잎 노드들이 트리의 왼쪽부터 차곡차곡 채워짐

#### 이진 트리의 상태
* **높이 균형 트리(Height Balanced Tree)**: 루트 노드를 기준으로 왼쪽 하위 트리와 오른쪽 하위 트리의 높이가 1 이상 차이나지 않는 이진 트리
* **완전 높이 균형 트리(Completely Height Balanced Tree)**: 루트 노드를 기준으로 왼쪽 하위 트리와 오른쪽 하위 트리의 높이가 같은 이진 트리

<img src="https://user-images.githubusercontent.com/22133824/144216152-70718839-63de-4d68-9577-42cd2517a607.png" width=400px />


#### 순회(Traversal): 트리 내의 노드들 사이를 돌아다니는 것 / 효율적인 방법으로 원하는 데이터에 접근할 수 있는 방법을 제공
* **전위 순회(Preorder Traversal)**: 루트 노드부터 잎 노드까지 아래 방향으로 방문
* **중위 순회(Inorder Traversal)**: 왼쪽 하위 트리부터 오른쪽 트리 방향으로 방문
* **후위 순회(Postorder Traversal)**: 루트, 왼쪽 하위 트리, 오른쪽 하위 트리 순으로 방문

<img src="https://user-images.githubusercontent.com/22133824/144216075-29b815b2-7bff-4523-bf93-c4eedbbe0820.png" height=300px />

Node structure
```C
typedef struct tagSBTNode{
  struct tagSBTNode* Left;
  struct tagSBTNode* Right;
  ElementType Data;
} SBTNode;
```

Test code result
```
Preorder...
 A B C D E F G

Inorder...
 C B D A F E G

PostOrder...
 C D B F G E A

Program ended with exit code: 0
```
