## 연습문제 풀이

### 01번
문자 A, B, C, D, E를 큐에 넣었다가 다시 꺼내어 출력하면?
```
QUEUE -> A, B, C, D, E
답: A, B, C, D, E
```

### 02번
원형큐에서 front = 3, rear = 5 이면 저장된 요소의 개수는?
```
QUEUE -> front = 3, rear = 5
답: 원소의 개수 2개
```

### 03번
10, 20, 30, 40, 50 큐 상태에서 3개 원소 삭제 남아있는 항목은?
```
QUEUE -> element = 10, 20, 30, 40, 50
delete_queue x 3
QUEUE -> element = 40, 50
답: 40, 50
```

### 04번
원형큐 공백상태는?
```
Circle queue = 공백상태 -> front == rear
답: front == rear
```

### 05번
size = 10, front = 3, rear = 5 원형큐, 새로운 항목 더해졌을때 front, rear 값은?
```
circle queue : front = 3, rear = 5
equeue
circle queue : fornt = 3, rear = 6
답: front = 3, rear = 6
```

### 06번
```
(a) A추가
circle queue = |  | B | C | A |  |
(b) D추가
circle queue = |  | B | C | A | D |
(c) 삭제
circle queue = |  |  | C | A | D |
```

