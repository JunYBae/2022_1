## 실습문제 풀이

### 01번
(1)
```
#include <iostream>
using namespace std;

int add(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

int add(int a[], int n, int b[]) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + a[i] + b[i];
	}
	return sum;
}


int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}
```
(2)
```
#include <iostream>
using namespace std;


int add(int a[], int n, int *b = NULL) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + a[i];
	}
	if (b != NULL) {
		for (int i = 0; i < n; i++) {
			sum = sum + b[i];
		}
	}
	return sum;
}


int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}
```

### 02번
(1)
```
#include<iostream>
#include<string>
using namespace std;
 
class Person {
    int id;
    double weight;
    string name;
public:
    Person();
    Person(int id, string name);
    Person(int id, string name, double weight);
    void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};
 
Person::Person() {
    id = 1;
    weight = 20.5;
    name = "Grace";
}
 
Person::Person(int id, string name) {
    this->id = id;
    weight = 20.5;
    this->name = name;
}
 
Person::Person(int id, string name, double weight) {
    this->id = id;
    this->weight = weight;
    this->name = name;
}
 
int main() {
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
}
```
(2)
```
#include <iostream>
using namespace std;


class Person {
	int id;
	double weight;
	string name;
public:
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
	Person(int id = 1, string name = "grace", double weight = 20.5) {
		this->id = id;
		this->name = name;
		this->weight = weight;
	}
};


int main() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
	return 0;
}
```

### 03번
(1)
```
int big(int a, int b) {
	return (a > b ? a : b) < 100 ? (a > b ? a : b) : 100;
}

int big(int a, int b, int c) {
	return (a > b ? a : b) < c ? (a > b ? a : b) : c;
}

int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
	return 0;
}
```
(2)
```
#include <iostream>
using namespace std;

int big(int a, int b, int c = 100) {
	return (a > b ? a : b) < c ? (a > b ? a : b) : c;
}

int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
	return 0;
}
```

### 04번
```
#include <iostream>
using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n = 100, int val = 0);
	MyVector(int n, int val);
	~MyVector() { delete[] mem; }
};

MyVector::MyVector(int n = 100, int val = 0) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++) mem[i] = val;
}
```

### 05번
```
#include <iostream>
using namespace std;

class ArrayUtility{
public:
	static void intToDouble(int source[], double dest[], int size) {
		for (int i = 0; i < size; i++) {
			dest[i] = (double)source[i];
		}
	}
	static void doubleToInt(double source[], int dest[], int size) {
		for (int i = 0; i < size; i++) {
			dest[i] = (int)source[i];
		}
	}
};

int main() {
	int x[] = { 1,2,3,4,5 };
	double y[5];
	double z[] = { 9.9, 8.8, 7.7, 6.6, 5.6 };

	ArrayUtility::intToDouble(x, y, 5);
	for (int i = 0; i < 5; i++)cout << y[i] << ' ';
	cout << endl;

	ArrayUtility::doubleToInt(z, x, 5);
	for (int i = 0; i < 5; i++)cout << x[i] << ' ';
	cout << endl;
	return 0;
}
```

### 06번
```
#include <iostream>
using namespace std;

class ArrayUtility2{
public:
	static int* concat(int x[], int y[], int size) {
		int* tmp = new int[size];
		int count = 0;
		for (int i = 0; i < size / 2; i++) {
			tmp[count++] = x[i];
		}

		for (int i = 0; i < size / 2; i++) {
			tmp[count++] = y[i];
		}
		return tmp;
	}
	static int* remove(int x[], int y[], int size, int& retsize) {
		int* tmp = new int[size];
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (x[i] == y[j])
					break;
				if (j == size - 1)
					tmp[cnt++] = x[i];
			}
		}
		retsize = cnt;
		return tmp;
	}
};

int main() {
	int x[5], y[5], retSize;
	int* z, * w;

	cout << "정수를 5개 입력하라. 배열 x에 삽입한다>>";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	cout << "정수를 5개 입력하라. 배열 y에 삽입한다>>";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}
	z = ArrayUtility2::concat(x, y, 10);
	cout << "합친 배열 정수 배열을 출력한다\n";
	for (int i = 0; i < 10; i++)
		cout << z[i] << " ";
	cout << endl;

	w = ArrayUtility2::remove(x, y, 5, retSize);
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	for (int i = 0; i < retSize; i++) {
		cout << w[i] << " ";
	}
	return 0;
}
```

### 07번
```
#include <iostream>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();
};

int Random::nextInt(int min, int max) {
	return rand() % (max - min) + min;
}

char Random::nextAlphabet() {
	if (rand() % 2 == 0)
		return rand() % 26 + 'a';
	else
		return rand() % 26 + 'A';
}

double Random::nextDouble() {
	return (double)rand() / RAND_MAX;
}

int main() {
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt(1, 100) << ' ';
	}
	cout << endl;

	cout << "알파벳을 랜덤하게 10개 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() << ' ';
	}
	cout << endl;

	cout << "랜덤한 실수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << ' ';
	}
	cout << endl;
	return 0;
}
```

### 08번
```

```
