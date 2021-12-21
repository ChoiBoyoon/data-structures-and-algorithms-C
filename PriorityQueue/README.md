## Priority Queue(우선순위 큐)
> 보통의 큐처럼 동작하지만 '우선순위' 속성을 갖는 데이터를 다룬다.

* 새 요소에 우선순위를 부여해서 큐에 삽입하고 가장 높은 우선순위를 갖는 요소부터 빠져나오도록 함.
* 우선순위의 기준은 프로그래머가 정하는 것. 본 예제 프로그램에선 '데이터의 값이 작을 수록 높은 것'으로.
* 우선순위 큐의 element들은 우선순위 오름차순으로 연결됨. 
  * 새 요소가 삽입되어야 하는 위치는 Heap의 도움을 받아 찾고, 
  * 제거(dequeue)는 전단만 제거해서 반환.

<img src="https://user-images.githubusercontent.com/22133824/146932589-4e05b5b6-6f4b-4c9e-bb2a-733a656cfb34.png" height=400px/>
img source: https://rajagoyal815.medium.com/
