## 연습문제 풀이

### 01번
```
int a[10][20]
int형 4바이트 x 10개 x 20개 = 800바이트
답: 800바이트
```

### 02번
```
1000번지
float a[100] 
10번째 주소 float 4바이트
답: 1040바이트
```

### 03번
```
(1)int array1[10] = 40
(2)double array2[10] = 80
(3)char array3[40] = 40
(4)float array4[10] = 40
답: 2번
```

### 04번
```
#include <stdio.h>
#include <math.h>
void print(int a[]) {
	for (int i = 0; i < 10; i++)
		a[i] = pow(2, i);
	for (int i = 0; i < 10; i++)
		printf("%d\n", a[i]);
}

int main() {
	int a[10] = {};
	print(a);
}
```
### 05번
```
#include <stdio.h>
#include <math.h>

struct person {
	char name[20];
	int age;
	float money;
};
```
### 06번
```
#include <stdio.h>

typedef struct {
	float real;
	float imaginary;
}complex;

int main() {
	complex c1, c2;
}
```

### 07번
```
#include <stdio.h>

typedef struct {
	float real;
	float imaginary;
}Complex;

Complex complex_add(Complex a, Complex b) {
	Complex tmp;
	tmp.real = a.real + b.real;
	tmp.imaginary = a.imaginary + b.imaginary;
	return tmp;
}
```

### 08번
```
#include <stdio.h>

static int SIZE = 5;

void insert(int array[], int loc, int value) {
	for (int i = SIZE - 1; i >= loc; i--)
		array[i + 1] = array[i];
	array[loc] = value;
	SIZE++;
}


int main() {
	int array[10] = { 1, 2, 3, 4, 5 };
	int loc = 0;
	int value = 10;
	insert(array, loc, value);
	
	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);

}
```

### 09번
```
최악의 경우 O(n) [loc = 0]
```

### 10번
```
#include <stdio.h>

int SIZE = 5;

void insert(int array[], int loc, int value) {
	for (int i = SIZE - 1; i >= loc; i--)
		array[i + 1] = array[i];
	array[loc] = value;
	SIZE++;
}

int Delete(int array[], int loc) {
	int temp = array[loc];
	for (int i = loc; i < SIZE - 1; i++)
		array[i] = array[i + 1];
	
	SIZE--;
	return temp;
	
}

int main() {
	int array[10] = { 1, 2, 3, 4, 5 };
	int loc = 0;
	int value = 10;

	insert(array, loc, value);
	
	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);

	Delete(array, loc);

	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);

}
```

### 11번
```
delete()의 함수 시간 복잡도
최악의 경우 O(n)
```

### 12번
```
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	char str[21];
}input;

int main() {
	input* a;
	a = (input*)malloc(sizeof(input));

	a->num = 100;
	strcpy(a->str, "just testing");
	printf("%d, %s", a->num, a->str);
	free(a);
}
```
