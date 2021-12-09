## QuickSort
> 분할 정복(Divide and Conquer)에 기반한 알고리즘.

1. 데이터 집합 내에서 임의의 기준 요소를 선택, 기준 요소보다 작은 요소들은 순서에 관계 없이 무조건 기준 요소의 왼편에, 큰 값은 오른편에 위치시킴.
2. 다시 1에서와 같이 임의의 기준 요소를 선택하고 같은 방법으로 데이터 집합을 분할.
3. 1과 2의 과정을 더 이상 데이터 집합을 나눌 수 없을 때까지 반복.

수색 섬멸 작전, 재귀 호출(recursive call) 기능 사용.

![image](https://user-images.githubusercontent.com/22133824/145110215-e0066606-2b75-4bef-b4dd-99cf4f787cd2.png)


### 성능
> 퀵 정렬은 데이터 집합이 어떻게 정렬되어 있는지가 성능을 좌우 but 특별한 경우가 아닌 경우 아주 뛰어난 성능을 가짐(평균 **1.39nlog<sub>2</sub>n**)

* 이상적인 경우(데이터 요소들이 이리저리 흩어져 있는 경우): **nlog<sub>2</sub>n**
* 최악의 경우: **(n(n-1)/2)**
  * 데이터가 미리 정렬되어 있거나 역순으로 정렬되어 있는 경우  
  * 매 재귀 호출마다 데이터 집합의 분할이 1:(n-1)로 이루어지는 경우
* 평균 **1.39nlog<sub>2</sub>n**

### qsort() 함수
> C 표준 라이브러리 함수 (stdlib.h)

```C
void qsort(
  void *base, //address of an array of data elements
  size_t num, //number of elements
  size_t width, //size of one data element
  int (__cdecl *compare)(const void*, const void*) //비교를 수행한 결과를 반환하는 함수에 관한 포인터
);
```
*cf. 함수에 대한 포인터를 갖고 있으면, 해당 포인터가 가리키고 있는 메모리에 위치한 함수를 실행시킬 수 있음.*


  
 
