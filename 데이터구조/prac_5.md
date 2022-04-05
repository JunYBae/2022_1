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
스택 2개로 queue 
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

### 10번
원형 queue 피보나치 구현
```
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_MAX_SIZE 10
typedef int element;

typedef struct Queuetype {
	element Queue[QUEUE_MAX_SIZE];
	int front, rear;
};

void init(Queuetype* q) {
	q->front = q->rear = 0;
	return;
}

bool is_full(Queuetype* q) {
	return ((q->rear + 1) % QUEUE_MAX_SIZE == q->front);
}

bool is_empty(Queuetype* q) {
	return q->front == q->rear;
}

void push(Queuetype* q, element item) {
	if (!is_full(q)) {
		q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;
		q->Queue[q->rear] = item;
	}
	else {
		fprintf(stderr, "메모리가 가득찼습니다.\n");
		exit(1);
	}
	return;
}

element pop(Queuetype* q) {
	if (is_empty(q)) {
		fprintf(stderr, "메모리가 비어있습니다.\n");
		exit(1);
	}
	else {
		q->front = (q->front + 1) % QUEUE_MAX_SIZE;
		return q->Queue[q->front];
	}
}

int fibo(Queuetype* q, element item) {
	if (item == 0)
		return 0;
	else if (item == 1)
		return 1;
	else {
		for (int i = 2; i <= item; i++) {
			int sum = pop(q);
			push(q, sum + q->Queue[q->rear]);
		}
	}
	return q->Queue[q->rear];
}


int main(void) {
	Queuetype q;
	init(&q);
	push(&q, 0);
	push(&q, 1);
	int n = 6;
	printf("%d", fibo(&q, n));
}
```

### 11번
```
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef char element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}Dequetype;

void init_deque(Dequetype* s) {
	s->front = s->rear = 0;
}

int is_empty(Dequetype* s) {
	return s->front == s->rear;
}

int is_full(Dequetype* s) {
	return (s->front == (s->rear + 1) % MAX_QUEUE_SIZE);
}

void deque_print(Dequetype* s) {
	printf("DEQUE(front=%d rear=%d) = ", s->front, s->rear);
	if (!is_empty(s)) {
		int i = s->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%c | ", s->data[i]);
			if (i == s->rear)
				break;
		} while (i != s->front);
	}
	printf("\n");
}

void add_rear(Dequetype* s, element item) {
	if (!is_full(s)) {
		s->rear = (s->rear + 1) % MAX_QUEUE_SIZE;
		s->data[s->rear] = item;
	}
	else {
		printf("덱 포화 상태\n");
	}
}

void add_front(Dequetype* s, element item) {
	if (!is_full(s)) {
		s->data[s->front] = item;
		s->front = (s->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	}
	else {
		printf("덱 포화 상태\n");
	}
}

element delete_rear(Dequetype* s) {
	if (is_empty(s)) {
		printf("덱 공백 상태\n");
		exit(1);
	}
	else {
		element tmp = s->rear;
		s->rear = (s->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		return s->data[tmp];
	}
}

element delete_front(Dequetype* s) {
	if (is_empty(s)) {
		printf("덱 공백 상태\n");
		exit(1);
	}
	else {
		s->front = (s->front + 1) % MAX_QUEUE_SIZE;
		return s->data[s->front];
	}
}

void check_pelindrome(char a[]) {
	Dequetype q;
	init_deque(&q);

	int i = 0, j = 0;

	while (a[i] != NULL) {
		if ('a' <= a[i] && 'z' >= a[i]) {
			add_rear(&q, a[i]);
			j++;
		}
		else if ('A' <= a[i] && 'Z' >= a[i]) {
			add_rear(&q, a[i] - ('A'- 'a'));
			j++;
		}
		i++;
	}

	while (!(j == 0 || j == 1)) {
		if (delete_front(&q) != delete_rear(&q)) {
			printf("회문이 아닙니다.\n");
			return;
		}
		j = j - 2;
	}
	printf("회문이 맞습니다.\n");
	return;
}

int main(void) {
	char I[20] = "mad@.,Am";
	char T[20] = "rac.er";

	check_pelindrome(I);
	check_pelindrome(T);
}
```
