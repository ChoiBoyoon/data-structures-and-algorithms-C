## Circular Queue

* **큐(Queue)**: 제일 먼저 들어간 데이터가 제일 먼저 나오는 자료구조. FIFO(First In First Out)
* 데이터 입력이 폭주하는 경우, 밀려드는 데이터를 '보관할 장소'로 사용됨. ('완충 장치', 버퍼)
* 주요 기능: 삽입(enqueue), 제거(dequeue)
* 배열로 구현한 큐 -> 전단(head), 후단(rear) 포인터로 요소들의 위치를 관리
* Circular Queue: Circular Linked List처럼 전단 바로 전 후단이 옴. 
* 비어있는 상태와 가득 찬 상태를 구별하기 위해 전단과 후단 사이를 1 비움. (front==rear면 공백 상태, front==rear+1이면 포화 상태)

![image](https://user-images.githubusercontent.com/22133824/143689174-bf863b5a-a450-4ca6-9833-0185a57be7fa.png)


test code results
```
Dequeue: 1, Front: 1, Rear: 4
Dequeue: 2, Front: 2, Rear: 4
Dequeue: 3, Front: 3, Rear: 4
Capacity : 10, Size: -1

Dequeue: 4, Front: 4, Rear: 2
Dequeue: 100, Front: 5, Rear: 2
Dequeue: 101, Front: 6, Rear: 2
Dequeue: 102, Front: 7, Rear: 2
Dequeue: 103, Front: 8, Rear: 2
Dequeue: 104, Front: 9, Rear: 2
Dequeue: 105, Front: 10, Rear: 2
Dequeue: 106, Front: 0, Rear: 2
Dequeue: 107, Front: 1, Rear: 2
Dequeue: 108, Front: 2, Rear: 2
Program ended with exit code: 0
```
