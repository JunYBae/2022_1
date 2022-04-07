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

### 10번
```
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person() {}
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name;  }
};

class Family {
	Person* p;
	string Fm;
	int size;

public:
	Family(string name, int size);
	void show();
	~Family();
	void setName(int num, string name) {
		p[num].setName(name);
	}
};

Family::Family(string name, int size) {
	this->size = size;
	this->Fm = name;
	p = new Person[size];
}

void Family::show() {
	cout << Fm << "가족은 다음과 같이 " << size << "명 입니다." << endl;
	for (int i = 0; i < size; i++)
		cout << p[i].getName() <<'\t';
	cout << endl;
}

Family::~Family() {
	delete[] p;
}

int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr.Simpson");
	simpson->setName(1, "Mrs.Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
	return 0;
}
```

### 11번
```
#include <iostream>
#include <string>
using namespace std;

class CoffeeVendingMachine {
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
public:
	void run();
};

void CoffeeVendingMachine::fill() {
	tong[0].fill(); tong[1].fill(); tong[2].fill();
}

void CoffeeVendingMachine::selectEspresso() {
	tong[0].consume(); 
	tong[1].consume();
}

void CoffeeVendingMachine::selectAmericano() {
	tong[0].consume();
	tong[1].consume(); tong[1].consume();
}

void CoffeeVendingMachine::selectSugarCoffee() {
	tong[0].consume();
	tong[1].consume(); tong[1].consume();
	tong[2].cousume();
}

void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize()
		<< ", 설탕 " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	while (1) {
		int count;
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
		cin >> count;
		switch (count) {
		case 1: 
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
			
		}
	}
}

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; }
	void consume() { size -= 1; }
	int getSize() { return size; }
};

int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr.Simpson");
	simpson->setName(1, "Mrs.Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
	return 0;
}
```
