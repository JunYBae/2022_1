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

```
