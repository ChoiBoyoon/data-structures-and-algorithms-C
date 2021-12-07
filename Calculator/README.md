## 수식 분석기 기반의 사칙 연산 계산기
> input ex: ```1 + 3.334 / (4.28 * (110 - 772))```
> -> 요소의 우선순위를 파악하고 알맞게 계산

### Step 1. 중위 표기식 -> 후위 표기식 (using Dijkstra algorithm)
* **후위 표기식(Reverse Polish Notation, Postfix Notation)** : 연산자를 피연산자 뒤에 위치시킴. (ex. 1 2 +)
* **중위 표기식(Infix Notation)** : 연산자가 피연산자 가운데에 위치. (ex: 1 + 2)

### Step 2. 후위 표기식을 계산 (stack 이용)
1. 식의 왼쪽부터 요소를 읽어내면서 피연산자는 스택에 담음.
2. 연산자가 나타난 경우에는 스택에서 피연산자 두 개를 꺼내 연산을 실행, 그 연산 결과를 다시 스택에 삽입.

![image](https://user-images.githubusercontent.com/22133824/143606908-c6549582-321d-482a-aedc-1163025ed003.png)

*cf. **토큰(token)**: 텍스트 분석에서 토큰은 '최소 단위의 기호 또는 단어'*
