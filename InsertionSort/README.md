## Insertion Sort
> 삽입 정렬. 정렬이 필요한 요소를 뽑아내어 이를 다시 적당한 곳에 삽입.

* 구현이 간단.
* 성능도 버블 정렬과 비슷 but 평균적으로 삽입 정렬이 더 나은 성능을 보임. (요소의 개수가 n개일 떄, 연산을 (n**2+n-2)/2)번 수행)

![image](https://user-images.githubusercontent.com/22133824/144718583-685ce035-b70e-48e4-a526-1723c46fa4fb.png)

```memmove()```: C 표준 함수. 메모리의 내용을 이동시킴. 연속된 데이터를 단번에 이동시킬 때 아주 유용함.
```memcpy()```: 원본 데이터를 대상 메모리 주소로 '복사'

Test code result
```
1 2 3 4 5 6 7 8 
Program ended with exit code: 0
```
