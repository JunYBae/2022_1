## 연습문제 풀이

### 09번
```
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert_back(ListNode* head, element value)
{
	if (head == NULL)
		insert_first(head, value);
	else {
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		p->data = value;
		p->link = NULL;
		ListNode* tmp = head;
		for (tmp = head; tmp->link != NULL; tmp = tmp->link) {}
		tmp->link = p;
		return head;
	}
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	if (head == NULL) return NULL;
	ListNode* removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* Delete(ListNode* head, ListNode* pre)
{
	ListNode* removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p = head;
	for (p = head; p->link != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("%d", p->data);

}


int main() { 
	ListNode* head = NULL;
	int count, value;
	printf("노드의 개수 : ");
	scanf_s("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &value);
		head = insert_back(head, value);
	}

	printf("생성된 연결 리스트 : ");
	print_list(head);
}
```

### 10번
```
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert_back(ListNode* head, element value)
{
	if (head == NULL)
		insert_first(head, value);
	else {
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		p->data = value;
		p->link = NULL;
		ListNode* tmp = head;
		for (tmp = head; tmp->link != NULL; tmp = tmp->link) {}
		tmp->link = p;
		return head;
	}
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	if (head == NULL) return NULL;
	ListNode* removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* Delete(ListNode* head, ListNode* pre)
{
	ListNode* removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p = head;
	for (p = head; p->link != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("%d", p->data);

}

int print_count(ListNode* head)
{
	ListNode* p = head;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
	{
		count++;
	}
	
	return count;
}


int main() { 
	ListNode* head = NULL;
	int count, value;
	printf("노드의 개수 : ");
	scanf_s("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &value);
		head = insert_back(head, value);
	}

	printf("연결 리스트 노드의 개수 : %d\n", print_count(head));
}
```

### 11번
```
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert_back(ListNode* head, element value)
{
	if (head == NULL)
		insert_first(head, value);
	else {
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		p->data = value;
		p->link = NULL;
		ListNode* tmp = head;
		for (tmp = head; tmp->link != NULL; tmp = tmp->link) {}
		tmp->link = p;
		return head;
	}
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	if (head == NULL) return NULL;
	ListNode* removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* Delete(ListNode* head, ListNode* pre)
{
	ListNode* removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p = head;
	for (p = head; p->link != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("%d", p->data);

}

int print_count(ListNode* head)
{
	ListNode* p = head;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
	{
		count++;
	}
	
	return count;
}

int print_sum(ListNode* head)
{
	ListNode* p = head;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
	{
		count += p->data;
	}

	return count;
}

int main() { 
	ListNode* head = NULL;
	int count, value;
	printf("노드의 개수 : ");
	scanf_s("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &value);
		head = insert_back(head, value);
	}

	printf("연결 리스트의 데이터 합 : %d\n", print_sum(head));
}
```

### 12번
```
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p = head;
	for (p = head; p->link != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("%d", p->data);

}

int print_count(ListNode* head, element value)
{
	ListNode* p = head;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
		if (p->data == value)
			count++;

	return count;
}



int main() {
	ListNode* head = NULL;
	int count, value;
	printf("노드의 개수 : ");
	scanf_s("%d", &count);
	for (int i = 0; i < count; i++) {
		printf("노드 #%d 데이터 : ", i + 1);
		scanf_s("%d", &value);
		head = insert_first(head, value);
	}

	printf("탐색할 값을 입력하시오: ");
	scanf_s("%d", &value);
	printf("%d는 연결 리스트에서 %d번 나타납니다.\n", value, print_count(head, value));
}
```

### 13번
```
```

### 14번
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
	char name[20];
	int age;
	double height;
}element;


typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;



ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head)
{
	ListNode* p = head;
	for (p = head; p != NULL; p = p->link)
	{
		printf("Name : %s\n", p->data.name);
		printf("Age  : %d\n", p->data.age);
		printf("Heigh: %lf\n", p->data.height);
		printf("\n");
	}

}

int main() {
	ListNode* head = NULL;
	element h1 = { "kim", 34, 1.7 };
	element h2 = { "park", 27, 1.2 };
	element h3 = { "lee", 48, 1.4 };
	element h4 = { "choi", 30, 1.3 };

	head = insert_first(head, h1);
	head = insert_first(head, h2);
	head = insert_first(head, h3);
	head = insert_first(head, h4);
	print_list(head);
	return 0;
}
```

### 15번
```
void max_min(ListNode* head)
{
	int max = INT_MIN, min = INT_MAX;
	ListNode* p = head;
	while (p != NULL)
	{
		if (max < p->data) max = p->data;
		if (min > p->data) min = p->data;
		p = p->link;
	}
	printf("최대 값 : %d, 최소 값: %d\n", max, min);
}
```

### 16번
```
```

### 17번
```
void print_list(ListNode* head)
{
	ListNode* p = head;
	for (p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}

}

ListNode* alternate(ListNode* head, ListNode* head2, ListNode* r) {
	while (head || head2) {
		if (head != NULL) {
			r = add(r, head->data);
			head = head->link;
		}
		if( head2 != NULL) {
			r = add(r, head2->data);
			head2 = head2->link;
		}
	}

	return r;
}
```
