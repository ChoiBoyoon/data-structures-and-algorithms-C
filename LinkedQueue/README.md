## LinkedQueue

* 전단, 후단 포인터를 관리할 필요 없음.
* 한계 용량에 제한이 없음 -> 가득 찬 상태인지 확인할 필요도 없음.
* 성능은 CircularQueue가 더 빠름. 크기가 예측 가능하고 고성능이 필요한 버퍼와 같은 경우 순환 큐가 더 적합함.

Node structure
```C
typedef struct tagNode{
  char* Data;
  struct tagNode* NextNode;
}
```
LinkedQueue structure
```C
typedef struct tagLinkedQueue{
  Node* Front;
  Node* Rear; //we use 4 bytes not to search for rear node everytime we need it. time complexity: O(n) -> (almost)0
  int Count;
} LinkedQueue;
```
