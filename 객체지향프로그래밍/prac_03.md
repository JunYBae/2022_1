## 실습 문제 풀이

### 01번
```
#include <iostream>
using namespace std;

class Tower {
private:
	int height;
public:
	Tower();
	Tower(int height);
	int getHeight();
};

Tower::Tower() {
	this->height = 1;
}

Tower::Tower(int height) {
	this->height = height;
}

int Tower::getHeight() {
	return this->height;
}

int main() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}
```

### 02번
```
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Date {
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	Date(string s) {
		int ind = 0;

		this->year = stoi(s);
		ind = s.find("/");

		this->month = stoi(s.substr(ind + 1));
		ind = s.find("/", ind + 1);

		this->day = stoi(s.substr(ind + 1));

	}

	void show() {
		cout << year << "년" << month << "월" <<  day << "일" << endl;
	}
	
	int getYear();
	int getMonth();
	int getDay();

};

int Date::getYear()
{
	return year;
}
int Date::getMonth()
{
	return month;
}
int Date::getDay()
{
	return day;
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;

	return 0;
}
```

### 03번
```
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Account {
	string name;
	int id;
	int money;
public:
	Account(string n, int i, int m);
	void deposit(int add);
	int withdraw(int odd);
	string getOwner();
	int inquiry();
};

Account::Account(string n, int i, int m) :name(n), id(i), money(m) {
	
}

void Account::deposit(int add) {
	money += add;
}

int Account::withdraw(int odd) {
	money -= odd;
	return odd;
}

string Account::getOwner() {
	return name;
}

int Account::inquiry() {
	return money;
}

int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	return 0;
}
```

### 04번
```
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class CoffeeMachine {
	int coffee;
	int water;
	int sugar;
public:
	CoffeeMachine(int c, int w, int s) {
		coffee = c;
		water = w;
		sugar = s;
	}
	void drinkEspresso() {
		coffee -= 1;
		water -= 1;
	}
	void drinkAmericano() {
		coffee -= 1;
		water -= 2;
	}
	void drinkSugarCoffee() {
		coffee -= 1;
		water -= 2;
		sugar -= 1;
	}
	void fill() {
		coffee = water = sugar = 10;
	}
	void show() {
		cout << "커피 머신 상태, 커피:" << coffee << "		물:" << water
			<< "		설탕:" << sugar << endl;
	}
};

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
	return 0;
}
```

### 05번
```
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
	int seed = 0;
public:
	int next() {
		int n = rand();
		return n;
	}

	int nextInRange(int start, int end) {
		int n = (rand() % end - start + 1) + start;
		return n;
	}
};


int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 4까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
	return 0;
}
```

### 06, 07번
```
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SelectableRandom {
	int seed = 0;
public:
	int nextEven();
	int nextOdd();
	int nextEvenInRange(int start, int end);
	int nextOddInRange(int start, int end);
};

int SelectableRandom::nextEven() {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand();
	} while (n % 2 != 0);
	return n;
}
int SelectableRandom::nextOdd() {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand();
	} while (n % 2 != 1);
	return n;
}
int SelectableRandom::nextEvenInRange(int start, int end) {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand() % (end - start + 1) + start;
	} while (n % 2 != 0);
	return n;
}
int SelectableRandom::nextOddInRange(int start, int end) {
	//srand((unsigned int)time(0));
	int n;
	do {
		n = rand() % (end - start + 1) + start;
	} while (n % 2 != 1);
	return n;
}

int main() {
	SelectableRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextEven();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 9까지의 랜덤 홀수 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextOddInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;
	return 0;
}
```
