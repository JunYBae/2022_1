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

### 10번
```
#include <stdio.h>
#include <stdlib.h>
typedef int element;
#define MAX_SIZE 100

typedef struct {
	element source[MAX_SIZE];
	int size;
}Stack;

void init_stack(Stack* s) {
	s->size = -1;
}

int is_empty(Stack* s) {
	return (s->size == -1);
}

int is_full(Stack* s) {
	return (s->size == MAX_SIZE - 1);
}

void push(Stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->source[++(s->size)] = item;
}

element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->source[(s->size)--];
}

element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->source[s->size];
}

int main() {
	Stack stack_tmp;
	init_stack(&stack_tmp);

	int tmp, item_tmp;
	printf("정수 배열의 크기: ");
	scanf_s("%d", &tmp);

	printf("정수를 입력하세요: ");
	for (int i = 0; i < tmp; i++) {
		scanf_s("%d", &item_tmp);
		push(&stack_tmp, item_tmp);
	}

	printf("반전된 정수 배열 : ");
	for (int i = 0; i < tmp; i++) {
		printf("%d ", pop(&stack_tmp));
	}

	
}
```

### 11번
```
#include <stdio.h>
#include <stdlib.h>
typedef char element;
#define MAX_SIZE 100

typedef struct {
	element source[MAX_SIZE];
	int size;
}Stack;

void init_stack(Stack* s) {
	s->size = -1;
}

int is_empty(Stack* s) {
	return (s->size == -1);
}

int is_full(Stack* s) {
	return (s->size == MAX_SIZE - 1);
}

void push(Stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->source[++(s->size)] = item;
}

element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->source[(s->size)--];
}

element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->source[s->size];
}

int main() {
	Stack stack;
	init_stack(&stack);

	char a[100];
	int i = 0, count = 1;

	printf("수식: ");
	scanf_s("%s", a, 100);

	while (a[i] != NULL) {
		
		
		if (a[i] == '(') {
			push(&stack, count);
			printf("%d ", count);
			count++;
		}

		else {
			printf("%d ",pop(&stack));
		}
		i++;
	}
	
}
```

### 12번
```
#include <stdio.h>
#include <stdlib.h>
typedef char element;
#define MAX_SIZE 100

typedef struct {
	element source[MAX_SIZE];
	int size;
}Stack;

void init_stack(Stack* s) {
	s->size = -1;
}

int is_empty(Stack* s) {
	return (s->size == -1);
}

int is_full(Stack* s) {
	return (s->size == MAX_SIZE - 1);
}

void push(Stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->source[++(s->size)] = item;
}

element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->source[(s->size)--];
}

element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->source[s->size];
}

int main() {
	Stack stack;
	Stack print_stack;
	init_stack(&stack);
	init_stack(&print_stack);

	char a[MAX_SIZE];
	int i = 0, count = 1;

	printf("문자열을 입력하시오: ");
	scanf_s("%s", a, MAX_SIZE);

	while (a[i] != NULL) {
		char tmp = a[i];
		count = 1;
		while (a[i + 1] == tmp || tmp == a[i + 1] - ('A' - 'a') || tmp == a[i + 1] + ('A' - 'a')) {
			count++;
			i++;
		}

		push(&stack, count + '0');
		
		if (tmp >= 'a' && tmp <= 'z')
			push(&stack, tmp);
		else
			push(&stack, tmp - ('A' - 'a'));
		i++;
	}

	while (!is_empty(&stack)) 
		push(&print_stack, pop(&stack));

	printf("압축된 문자열: ");
	while (!is_empty(&print_stack))
		printf("%c", pop(&print_stack));
	
}
```

### 13번
```
#include <stdio.h>
#include <stdlib.h>
typedef char element;
#define MAX_SIZE 100

typedef struct {
	element source[MAX_SIZE];
	int size;
}Stack;

void init_stack(Stack* s) {
	s->size = -1;
}

int is_empty(Stack* s) {
	return (s->size == -1);
}

int is_full(Stack* s) {
	return (s->size == MAX_SIZE - 1);
}

void push(Stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->source[++(s->size)] = item;
}

element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->source[(s->size)--];
}

element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->source[s->size];
}

int main() {
	Stack stack;
	Stack print_stack;
	init_stack(&stack);
	init_stack(&print_stack);

	char a[MAX_SIZE];
	int i = 0;

	printf("문자열을 입력하시오: ");
	scanf_s("%s", a, MAX_SIZE);

	while (a[i] != NULL) {

		if (a[i] != a[i + 1])
			push(&stack, a[i]);
		i++;
	}

	while (!is_empty(&stack)) 
		push(&print_stack, pop(&stack));

	printf("압축된 문자열: ");
	while (!is_empty(&print_stack))
		printf("%c", pop(&print_stack));
	
}
```
