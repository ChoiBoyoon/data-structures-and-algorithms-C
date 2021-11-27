## Circular Queue

* **큐(Queue)**: 제일 먼저 들어간 데이터가 제일 먼저 나오는 자료구조. FIFO(First In First Out)
* 데이터 입력이 폭주하는 경우, 밀려드는 데이터를 '보관할 장소'로 사용됨. ('완충 장치', 버퍼)
* 주요 기능: 삽입(enqueue), 제거(dequeue)
* 배열로 구현한 큐 -> 전단(head), 후단(rear) 포인터로 요소들의 위치를 관리
* Circular Queue: Circular Linked List처럼 전단 바로 전 후단이 옴. 
* 비어있는 상태와 가득 찬 상태를 구별하기 위해 전단과 후단 사이를 1 비움. (front==rear면 공백 상태, front==rear+1이면 포화 상태)

![image](https://user-images.githubusercontent.com/22133824/143689174-bf863b5a-a450-4ca6-9833-0185a57be7fa.png)
