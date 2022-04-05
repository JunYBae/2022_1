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

### 07번
큐 항목 삽입 삭제 시간 복잡도는?
```
답: O(1)
```

### 08번
원형큐에 큐에 존재하는 요소의 개수 반환하는 get_count 추가
```
int get_count(Queue* s) {
	if (s->front <= s->rear)
		return s->rear - s->front;
	else
		return MAX_SIZE - (s->front - s->rear);     //ex)front = 3, rear = 1, size = 5;
}
```

### 09번
```
#include<stdio.h>

#define MAX_SIZE 100

typedef struct Stacktype {
	int stack[MAX_SIZE];
	int top;
};

void Stack_init(Stacktype* s) {
	s->top = -1;
}

void Stack_push(Stacktype* s, int item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stacktype* s) {
	return s->top == -1;
}

int Stack_pop(Stacktype* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

typedef struct Queuetype {
	Stacktype s1, s2;
}Queuetype;

void Queue_init(Queuetype* q) {
	q->s1.top = -1;
	q->s2.top = -1;
}

void Queue_push(Queuetype* q, int item) {
	Stack_push(&(q->s1), item);
}

int Queue_pop(Queuetype* q) {
	if (is_empty(&(q->s2))) {
		while (!is_empty(&(q->s1))) {
			Stack_push(&(q->s2), Stack_pop(&(q->s1)));
		}
	}
	return Stack_pop(&(q->s2));
}

int main(void) {
	Queuetype q;
	Queue_init(&q);
	Queue_push(&q, 5);
	Queue_push(&q, 4);
	Queue_push(&q, 3);
	printf("%d\n", Queue_pop(&q));
	printf("%d\n", Queue_pop(&q));
	printf("%d\n", Queue_pop(&q));
}
```
