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

