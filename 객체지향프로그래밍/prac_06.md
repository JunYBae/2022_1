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

```

