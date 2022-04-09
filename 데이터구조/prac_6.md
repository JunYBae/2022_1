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
