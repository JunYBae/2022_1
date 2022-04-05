## 연습문제 풀이
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
### 6번
