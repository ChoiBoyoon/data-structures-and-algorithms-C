### Circular Linked List
> a variation of a linked list where the tail node points to the head node, completing a full circle of nodes.
* Cost to get to tail node decreases -> ```append_node()``` functionality increases drastically.
* Need to pay more attention with pointers when there's 0-1 node in the list. (```Head->NextNode``` and ```Head->PrevNode``` are both Head itself)

### 환형 링크드 리스트(Circular Linked List)
> 헤드가 테일을 물고 있는 형태의 링크드 리스트.
* 테일에 접근하는 비용이 크게 작아짐 -> ```append_node()``` 함수의 기능을 획기적으로 개선 가능.
* 리스트에 노드가 없거나, 하나 있을 때 연산에 주의.
![image](https://user-images.githubusercontent.com/22133824/142841085-1371c1d5-62b7-49a5-8408-dabf42046090.png)
