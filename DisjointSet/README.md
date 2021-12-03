## 분리 집합(Disjoint Set)
> 서로 공통된 원소를 갖지 않는 집합들. 컴퓨터 과학자들이 수합에서 업어온 자료구조.
![image](https://user-images.githubusercontent.com/22133824/144575261-229de051-2dd7-405f-917f-91d5d67f6311.png)


* 분리 집합에는 교집합(Intersection)이 있을 수 없음.
* 서로 구분되어야 하는 데이터 집합을 다룰 때 아주 유용함.
* 집합 탐색: 어떤 한 원소가 소속되어 있는 집합을 알아내는 것.
* 분리 집합은 자식이 부모를 가리키는 포인터를 가짐. 루트 노드는 집합 그 자체(LinkedList에서 Head가 LinkedList를 나타낸 것처럼)


structure of disjoint set
```C
typedef struct tagDisjointSet{
  struct tagDisjointSet* Parent;
  void* Data;   //어떤 자료형의 데이터든 입력할 수 있음
}
```
