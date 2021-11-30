## LCRSTree : Left Child Right Sibling Tree
>

* **트리(Tree)**: 나무를 닮은 자료구조.
* 사용 예시: 운영체제의 파일 시스템, HTML이나 XML문서를 다룰 때 사용하는 DOM(Document Object Model), 검색 엔진, 데이터베이스
![image](https://user-images.githubusercontent.com/22133824/144130887-066f1f7a-2516-4fc2-acbf-a04b50b77e01.png)

#### 뿌리, 가지, 잎 모두 똑같은 노드. 트리 내의 위치에 따라 명칭이 달라짐.
* **뿌리(root)**: 트리 자료구조의 가장 위에 있는 노드
* **가지**: 루트와 잎 사이에 있는 모든 노드
* **잎(단말 노드, terminal node)**: 가지의 끝에 있는 노드
* **경로**: 한 노드에서부터 다른 한 노드까지 이르는 길 사이에 놓여있는 노드들의 순서.
  * 길이(length): 출발 노드에서 목적지 노드까지 거쳐야 하는 노드의 개수
  * 깊이(depth): 루트 노드에서 해당 노드까지의 경로의 길이.
  * 레벨(level): 깊이가 같은 노드의 집합.
  * 차수(degree)
    * 노드의 차수: 그 노드의 자식 노드 개수
    * 트리의 차수: 트리 내에 있는 노드들 가운데 자식 노드가 가장 많은 노드의 차수

#### 트리 표현하기
* 중첩된 괄호(nested parenthesis)
* 중첩된 집합(nested set)
* **들여쓰기(indentation)**: 자료의 계층적인 특성을 잘 나타냄. ex)윈도우 탐색기의 폴더 트리

#### 노드 표현하기
* **N-링크**: 노드가 N개의 링크를 가지고 있어 이 링크들이 각각 자식 노드를 가리키도록 노드를 구성.<br/>차수가 노드마다 달라지는 트리에는 적용하기 어려움.
* **왼쪽 자식-오른쪽 형제 표현(LCRS, Left Child Right Sibling)** : N개의 차수를 가진 노드의 표현이 두 개의 포인터로 가능.
![image](https://user-images.githubusercontent.com/22133824/144132142-e039e8b0-4bfb-4b85-9c5b-fd3cb92a76db.png)

#### Node structure
```C
typedef struct tagLCRSNode{
    struct tagLCRSNode* LeftChild;
    struct tagLCRSNode* RightNode;
    ElementType Data;
}LCRSNode;
```
#### Test code result
```C
A
 B
  C
  D
   E
   F
 G
  H
 I
  J
   K
Program ended with exit code: 0
```
