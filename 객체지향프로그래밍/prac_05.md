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
#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; }
	Accumulator& add(int n) {
		this->value += n;
		return *this;
	}
	int get() { return value; }
};

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();

	return 0;
}
```

### 10번
```
#include <iostream>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void print() { cout << text << endl; }
};


Buffer& append(Buffer& buf, string text) {
	buf.add(text);
	return buf;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();

	return 0;
}
```

### 11번
(1), (3)
```
#define _CRT_SECURE_NO_WARINGS
#include <cstring>
#include <iostream>
using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	~Book();
	Book(const Book& book);
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const Book& book) {
	this->price = book.price;
	int size = strlen(book.title) + 1;
	this->title = new char[size];
	strcpy_s(this->title, size, book.title);
}

Book::Book(const char* title, int price) {
	this->price = price;
	int size = strlen(title) + 1;
	this->title = new char[size];
	strcpy_s(this->title, size, title);
}

void Book::set(const char* title, int price) {
	if (this->title != NULL)
		delete[] this->title;
	this->price = price;
	int size = strlen(title) + 1;
	this->title = new char[size];
	strcpy_s(this->title, size, title);
	
}

Book::~Book() {
	free(title);
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}
```

(2)

Book(cosnt Book& b) {
	this->price = b.price;
	this->title = b.title;
}

(4)

```
#define _CRT_SECURE_NO_WARINGS
#include <cstring>
#include <iostream>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price);
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(string title, int price) {
	this->title = title;
	this->price = price;
}

void Book::set(string title, int price) {
	this->title = title;
	this->price = price;
}


int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}
```

### 12번

(1), (2)

새로 생긴 클래스가 전의 클래서 scores 데이터 공간을 똑같이 가르키고 있어 소멸자 실행시 오류 발생.

```
#define _CRT_SECURE_NO_WARINGS
#include <cstring>
#include <iostream>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	Dept(const Dept& dept) {
		this->size = dept.size;
		scores = new int[size];
		for (int i = 0; i < this->size; i++) {
			this->scores[i] = dept.scores[i];
		}
	}

	~Dept() { delete[] scores; }
	int getSize() { return size; }
	void read() {
		cout << size << "개 점수 입력>> ";
		for (int i = 0; i < size; i++) 
			cin >> scores[i];
		
	}
	bool isOver60(int index) {
		return scores[index] > 60;
	}
};

int countPass(Dept dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i))
			count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";
}
```

(3)
```
#define _CRT_SECURE_NO_WARINGS
#include <cstring>
#include <iostream>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}

	~Dept() { delete[] scores; }
	int getSize() { return size; }
	void read() {
		cout << size << "개 점수 입력>> ";
		for (int i = 0; i < size; i++) 
			cin >> scores[i];
		
	}
	bool isOver60(int index) {
		return scores[index] > 60;
	}
};

int countPass(Dept& dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i))
			count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명";
}
```
