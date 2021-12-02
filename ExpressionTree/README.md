## Expression Tree(수식 트리)
> 수식을 표현하는 이진 트리
> 수식 이진 트리(Expression Binary Tree)라고 부르기도 함.

* 피연산자는 잎 노드
* 연산자는 루트 노드 또는 가지 노드
* 수식 트리의 성질에 적합한 노드 순회 방법: 후위 순회
* 후위 표기식을 이용해 트리를 구축 (중위 표기식은 컴퓨터가 처리하기에 적합하지 않음)

![image](https://user-images.githubusercontent.com/22133824/144508759-ae745a1c-6f92-4537-a854-e34280ae3ccd.png)

test code result
```C
Preorder...
 / * 7 2 - 5 2

Inorder...
((( 7) *( 2)) /(( 5) -( 2)))

Postorder...
 7 2 * 5 2 - /

Evaluation Result: 4.666667 
Program ended with exit code: 0
```
