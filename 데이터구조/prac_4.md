## 연습문제 풀이
### 01번
```
처음 top의 값 = -1
값이 넣어지면 1이 증가하게 된다.
답: top = 0
```

### 02번
```
스택에 A, B, C, D, E를 넣으면,
A, B, C, D, E 순서로 들어간다.
값을 꺼낼 때에는,
E, D, C, B, A 순으로 빠진다.
답: E, D, C, B, A
```

### 03번
```
10, 20, 30, 40, 50
 -- 값 3개 POP --
10, 20
답: 10, 20
```

### 04번
```
top은 배열 원소의 위치를 말하기 때문에
저장된 요소의 개수는 top+1 이다.
답: 4
```

### 05번
```
스택 공백 상태  : top == -1
스택 포화 상태  : top == MAX_STACK_SIZE - 1
```

### 06번
```
O(1)
```

### 07번
```
B+E
```

### 08번
```
push(A, 1)  // top = 0 stack = 1
push(A, 2)  // top = 1 stack = 1, 2
push(A, 3)  // top = 2 stack = 1, 2, 3
pop(A)      // top = 1 stack = 1, 2
push(A, 4)  // top = 2 stack = 1, 2, 4
push(A, 5)  // top = 3 stack = 1, 2, 4, 5
pop(A)      // top = 2 stack = 1, 2, 4
```

### 09번
```
push(A, a) // top = 0 stack = a
push(A, b) // top = 1 stack = a, b
push(A, c) // top = 2 stack = a, b, c
push(B, d) // top = 0 stack = d
push(B, pop(A)) A: top = 1 stack = a, b  B: top = 1 stack = d, c
push(A, pop(B)) A: top = 2 stack = a, b, c B: top = 0 stack = d
pop(B)     // top = -1 stack = 
```

