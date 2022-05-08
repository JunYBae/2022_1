## 실습문제 8장
### 1번
```
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string str;
public:
	NamedCircle(int radius, string str) : Circle(radius) {
		this->str = str;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << str << endl;
	}
};

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
}
```

### 2번
```
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string str;
public:
	NamedCircle(int radius = 0, string str = "") : Circle(radius) {
		this->str = str;
	}
	void setName(string str) { this->str = str; }
	string getName() { return str; }
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << str << endl;
	}
};

int main() {
	NamedCircle pizza[5];

	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;

	int count;
	string str;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">> ";
		cin >> count >> str;
		pizza[i].setRadius(count);
		pizza[i].setName(str);
	}

	int max = 0;
	string max_str;

	for (int i = 0; i < 5; i++) {
		if (max < pizza[i].getRadius()) {
			max = pizza[i].getRadius();
			max_str = pizza[i].getName();
		}
	}

	cout << "가장 면적이 큰 피자는 " << max_str <<  "입니다." << endl;
}
```

### 3번
```

```
