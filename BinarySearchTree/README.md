## 이진 탐색 트리(Binary Search Tree)
> '이진 탐색'을 위한 '이진 트리'

* **이진 트리(binary tree)**: 자식 노드가 최대 두 개뿐인 노드. 컴파일러의 표현식 트리 등 다양한 용도로 쓰임.
* Linked list에서는 이진 탐색에 필요한 작업들이 불가능. 헤드와 테일 사이 '중앙 요소'를 알 수 없기 때문. 
* **이진 탐색 트리(binary search tree)**: '왼쪽 자식 노드는 나보다 작고, 오른쪽 자식 노드는 나보다 크다.'

<img src="https://user-images.githubusercontent.com/22133824/145681556-20c27702-72f9-41fe-a1cb-3880903b9d87.png" width=400px />

### 문제점
> 아래 그림처럼 이진 탐색 트리가 기형적으로 성장하면 검색의 효율을 극단적으로 떨어뜨림.

![image](https://user-images.githubusercontent.com/22133824/145682649-1fdeca15-5512-4bf3-90a5-89728cecc6b2.png)
* 실제 데이터를 담는 경우 위와 같이 성장할 확률이 높음.

Test code result:
```
1 3 17 22 34 98 123 317 424 760 9918 
After removing 98
1 3 17 22 34 123 317 424 760 9918 
After inserting 111
1 3 17 22 34 111 123 317 424 760 9918 
Program ended with exit code: 0
```
