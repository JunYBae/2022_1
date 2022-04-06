## 실습문제 풀이

### 01번
```
#include <iostream>
#include <string>

using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);
	Color* p;
	p = &screenColor;
	p->show();
	Color colors[3];
	p = colors;


	p[0].setColor(255, 0, 0);
	p[1].setColor(0, 255, 0);
	p[2].setColor(0, 0, 255);

	p->show();
	(p + 1)->show();
	(p + 2)->show();
}
```

### 02번
```
#include <iostream>
#include <string>

using namespace std;

int main() {
	int* a;
	a = new int[5];

	cout << "정수 5개 입력>> ";

	double avg = 0;

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		avg += *(a + i);
	}

	avg /= 5;

	cout << "평균 " << avg << endl;

}
```

### 03번
(1)
```
#include <iostream>
#include <string>

using namespace std;

int main() {
	int count = 0;
	string tmp;
	cout << "문자열 입력>> ";
	
	getline(cin, tmp);

	for (int i = 0; i < tmp.length(); i++) {
		if (tmp.at(i) == 'a')
			count++;
	}

	cout << "문자 a는 " << count << "개 있습니다." << endl;
}
```
(2)
```
#include <iostream>
#include <string>

using namespace std;

int main() {
	int count = 0, ind = 0;
	string tmp;
	cout << "문자열 입력>> ";
	
	getline(cin, tmp);
	ind = tmp.find('a', ind);

	while (1) {
		if (ind == -1) break;
		else count++;
		ind = tmp.find('a', ind + 1);
	}

	cout << "문자 a는 " << count << "개 있습니다." << endl;
}
```

### 04번
```
#include <iostream>
#include <string>

using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i = 0; i < size; i++)
		cin >> p[i];
}

void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << p[i] << " ";
	cout << endl;
}

int Sample::big() {
	int big = 0;
	for (int i = 0; i < size; i++)
		if (big < p[i])
			big = p[i];
	return big;
}

Sample::~Sample() {
	delete[] p;
}


int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;

	return 0;
}
```

### 06번
```
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;



int main() {
	string str;
	cout << "아래에 한줄을 입력하세요.(exit를 입력하면 종료합니다)\n";

	while (true) {
		cout << ">>";
		getline(cin, str);
		if (str.compare("exit") == 0)
			break;

		srand((unsigned)time(0));
		int n = rand() % str.length();

		srand((unsigned)time(0));
		char c = 'a' + rand() % 26;

		str[n] = c;
		cout << str << endl;

	}
}
```

### 07번
```
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	Circle p[3];
	int tmp;
	for (int i = 0; i < 3; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> tmp;
		p[i].setRadius(tmp);
	}

	tmp = 0;

	for (int i = 0; i < 3; i++) {
		if (p[i].getArea() > 100)
			tmp++;
	}
	cout << "면적이 100보다 큰 원은 " << tmp << "개 입니다";
}
```

### 08번
```
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	int size;
	cout << "원의 개수 >> ";
	cin >> size;

	Circle* p = new Circle[size];

	int tmp;
	for (int i = 0; i < size; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> tmp;
		p[i].setRadius(tmp);
	}

	tmp = 0;

	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > 100)
			tmp++;
	}
	cout << "면적이 100보다 큰 원은 " << tmp << "개 입니다";
}
```

### 09번
```
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() { }
	string getName() { return name; }
	string getTel() { return tel;  }
	void set(string name, string tel);
};

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	cout << "이름과 전화 번호를 입력해 주세요 \n";

	string n, t;
	Person persons[3];

	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1 << ">> ";
		cin >> n >> t;
		persons[i].set(n, t);
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << persons[i].getName() << " ";
	}
	cout << endl;

	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	cin >> n;

	for (int i = 0; i < 3; i++) {
		if (persons[i].getName().compare(n) == 0) {
			cout << "전화 번호는 " << persons[i].getTel();
		}
	}
}
```
