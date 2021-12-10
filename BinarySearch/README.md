## 탐색 알고리즘 (Search Algorithms)

* 탐색, 또는 검색 알고리즘은 구글에서 갖아 돈을 많이 벌어들이는 기술.
* **이진 탐색**: 놀라운 효율로 검색을 수행 but 모든 자료구조에서 사용이 가능하진 않음. (정렬된 데이터 집합에서만 사용 가능)
* **이진 탐색 트리**: 데이터 집합의 크기가 동적으로 변경되는 경우, 이진 탐색의 효율로 탐색이 가능.
* **레드 블랙 트리**: 이진 탐색 트리를 한층 더 개선한 것.

## 이진 탐색(Binary Search)
> 정렬된 데이터 집합에서 사용할 수 있는 '고속' 탐색 알고리즘. **time complexity: O(logN)**

* 탐색 범위를 1/2씩 줄여나가는 방식
* 성능이 매우 뛰어나면서도 그 구조는 굉장히 간단함.

![image](https://user-images.githubusercontent.com/22133824/145482790-5ff451cd-b5c9-4200-8dab-d2aaf6bd1737.png)

#### In this exercise, we'll find a student who recorded score of 671.78
```C
typedef struct{
  int number;   //identifier of student
  double score; //score they got
}
```
test result (in both BinarySearch.c and BinarySearch2.c)
```
found: 1780 671.780000 
Program ended with exit code: 0
```
## bsearch()
> The function <b>Score* BinarySearch(Score ScoreList[]. int size, double target);</b> in BinarySearch.c can be replaced by **bsearch()**, C function in standard library.

* use case is implemented in <b>BinarySearch2.c</b>
