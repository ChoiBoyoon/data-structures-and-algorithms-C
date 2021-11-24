### 스택
* 원래 건초나 짚더미와 같은 뭔가를 쌓아놓은 더미를 뜻함.
* 중간에 데이터를 삽입/삭제하는 것을 허용하지 않음. 요소의 삽입과 삭제가 자료구조의 한쪽 끝에서만 이루어짐.
* 가장 마지막에 들어간 데이터가 제일 먼저 나오고(Last In - First Out, LIFO) 가장 먼저 들어간 데이터는 가장 나중에 나오게 됨(First In - Last Out)
* 자동 메모리가 스택 기반으로 동작
* 대부분의 네트워크 프로토콜도 스택을 기반으로 구성
* 주요 기능 : 삽입(push), 제거(pop)
* 배열을 이용한 스택 : 구현이 간단함. 스택 생성 초기에 사용자가 부여한 용량만큼의 노드를 한꺼번에 생성함

```C
typedef struct tagNode{
  ElementType Data;
  //노드가 존재하는 위치는 배열의 인덱스로 알 수 있음 -> 포인터 필요 없음.
} Node

typedef struct tagArrayStack{
  int Capacity; //용량
  int Top;      //최상위 노드의 위치
  Node* Nodes;  //노드 배열. 포인터를 배열로 사용할 수 있는 C언어의 특성을 이용. (Nodes 포인터는 자유 저장소에 할당한 배열의 첫 번째 요소를 가리킴)
} ArrayStack;
```

![image](https://user-images.githubusercontent.com/22133824/143220181-95d68ec0-0e76-403e-bb21-6785af3fb06b.png)

### Stack

```C
typedef struct tagNode{
  ElementType Data;
  //location of node is known by index of array -> pointer is not necessary
} Node

typedef struct tagArrayStack{
  int Capacity; //size of stack
  int Top;      //location of top node
  Node* Nodes;  //Nodes points to first element of array assigned in free store. In C language, pointer can be used like an array.
} ArrayStack;
```

result of the test code:
```
Capacity: 10, Size: 4, Top: 12

Popped: 12
Current Top: 11
Popped: 11
Current Top: 37
Popped: 37
Current Top: 3
Popped: 3
Stack is empty.
Program ended with exit code: 0
```
