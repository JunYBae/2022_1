## 실습문제 풀이

### 01번
```
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() :Circle(1) {}
	Circle(int r) { this->radius = r; }
	void show() { cout << "반지름 : " << radius << endl; }
};

void swap(Circle& a, Circle& b) {
	Circle tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	Circle a(1), b(2);
	a.show();
	b.show();

	swap(a, b);
	a.show();
	b.show();
	return 0;
}
```

### 02번
```
#include <iostream>
using namespace std;

void half(double& n) {
	n /= 2;
}

int main() {
	double n = 20;
	half(n);
	cout << n;
}
```

### 03번
```
#include <iostream>
using namespace std;

void combine(string text1, string text2, string& text3) {
	text3 = text1 + " " + text2;
}
int main() {
	string text1("I love you"), text2("very much");
	string text3;
	combine(text1, text2, text3);
	cout << text3;
	return 0;
}

```

### 04번
```
#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b)
		return true;
	else {
		if (a > b)
			big = a;
		else
			big = b;
	}
	return false;
}

int main() {
	int a, b, big;

	a = 5; b = 5;
	if (bigger(a, b, big)) {
		cout << "두 수는 같습니다" << endl;
	}
	else {
		cout << a << "와 " << b << "중 큰 수는 " << big << "입니다." << endl;
	}

	a = 5; b = 10;
	if (bigger(a, b, big)) {
		cout << "두 수는 같습니다" << endl;
	}
	else {
		cout << a << "와 " << b << "중 큰 수는 " << big << "입니다." << endl;
	}

	return 0;
```

### 05번
```
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이" << radius << "인 원" << endl; }
};

void increaseBy(Circle& a, Circle b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y);
	x.show();
}
```

### 06번
```
#include <iostream>
using namespace std;

char& find(char a[], char c, bool& success) {
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
	success = false;
}


int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);

	if (b == false) {
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
}
```

### 07번
```
#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];
	int tos;
public:
	MyIntStack();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack::MyIntStack() {
	tos = -1;
}

bool MyIntStack::push(int n) {
	if (tos == 9) 
		return false;
	else {
		p[++tos] = n;
		return true;
	}
}

bool MyIntStack::pop(int& n) {
	if (tos == -1)
		return false;
	else {
		n = p[tos--];
		return true;
	}
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;

	return 0;
}
```

### 08번
```
#include <iostream>
using namespace std;

class MyIntStack {
	int *p;
	int size;
	int tos;
public:
	MyIntStack() { tos = -1; }
	MyIntStack(int size) { p = new int[size]; tos = -1; this->size = size; }
	MyIntStack(MyIntStack& s) {
		this->size = s.size;
		this->tos = s.tos;
		p = new int[size];
		
		for (int i = 0; i < size; i++)
			p[i] = s.p[i];
	}
	~MyIntStack() { delete[] p; }
	bool push(int n);
	bool pop(int& n);
};


bool MyIntStack::push(int n) {
	if (tos == size - 1) 
		return false;
	else {
		p[++tos] = n;
		return true;
	}
}

bool MyIntStack::pop(int& n) {
	if (tos == -1)
		return false;
	else {
		n = p[tos--];
		return true;
	}
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;

	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;

	return 0;
}
```

### 09번
```

```

