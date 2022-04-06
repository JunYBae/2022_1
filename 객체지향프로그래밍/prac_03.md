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

```
