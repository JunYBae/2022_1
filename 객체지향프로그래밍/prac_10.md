## 실습문제 10장

### 1번
```
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
int biggest(T x[], int size) {
	T tmp = x[0];
	for (int i = 1; i < size; i++) {
		if (tmp < x[i])
			tmp = x[i];
	}
	return tmp;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	cout << biggest(x, 5) << endl;
}
```

### 2번
```
#include <iostream>
using namespace std;

template <class T>
bool equalArray(T x[], T y[], int size) {
	bool success = true;
	for (int i = 0; i < size; i++) {
		if (x[i] != y[i])
			success = false;
	}
	return success;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	int y[] = { 1, 10, 100, 5, 4 };
	if (equalArray(x, y, 5)) cout << "같다";
	else cout << "다르다";
}
```

### 3번
```
#include <iostream>
using namespace std;

template <class T>
void reverseArray(T x[ ], int size) {
	for (int i = 0; i < size / 2; i++) {
		T tmp = x[i];
		x[i] = x[size - 1 - i];
		x[size - 1 - i] = tmp;
	}
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++)
		cout << x[i] << ' ';
}
```

### 4번
```
#include <iostream>
using namespace std;

template <class T>
bool search(T find, T x[], int size) {
	for (int i = 0; i < size; i++) {
		if (x[i] == find) return true;
	}
	return false;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	if (search(100, x, 5)) cout << "100이 배열 x에 포함되어 있다";
	else cout << "100이 배열 x에 포함되어 있지 않다.";
}
```

### 5번
```
#include <iostream>
using namespace std;

template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
	T* tmp = new T[sizea + sizeb];
	int count = 0;
	for (int i = 0; i < sizea; i++)
		tmp[count++] = a[i];
	for (int i = 0; i < sizeb; i++)
		tmp[count++] = b[i];
	return tmp;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	int y[] = { 7, 6, 10, 9 };
	int* a = concat(x, 5, y, 4);
	int aSize = sizeof(x) / sizeof(x[0]) + sizeof(y) / sizeof(y[0]); // a에 들어있는 원소의 개수 

	for (int i = 0; i < aSize; i++)
		cout << a[i] << ' ';
}
```

### 6번
```
#include <iostream>
using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	T count[100] = { 0 };
	retSize = 0;
	
	for (int i = 0; i < sizeSrc; i++) {
		bool success = true;
		for (int k = 0; k < sizeMinus; k++) {
			if (src[i] == minus[k])
				success = false;
		}
		if (success)
			count[retSize++] = src[i];
	}
	T* tmp = new T[retSize];
	for (int i = 0; i < retSize; i++)
		tmp[i] = count[i];
	return tmp;
}

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[] = { 5,6,7,8,9 };
	int size = 0;
	int* p = remove(a, 10, b, 5, size);
	for (int i = 0; i < size; ++i)
		cout << p[i] << ' ';
	cout << endl;
	delete[] p;
	size = 0;
	char c[] = { 'a','b','i','m','c','d','e', };
	char d[] = { 'k','i','m','n','u' };
	char* q = remove(c, 7, d, 5, size);
	for (int i = 0; i < size; ++i)
		cout << q[i] << ' ';
	cout << endl;
	delete[] q;
}
```

### 7번
```
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}

Circle bigger(Circle& a, Circle& b) {
	if (a.getRadius() < b.getRadius())
		return b;
	else
		return a;
}


int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza중 큰 것의 반지름은 " << y.getRadius() << endl;
}
```

### 8번
```
#include <iostream>
using namespace std;

class Comparable {
public:
	virtual bool operator > (Comparable& op2) = 0;
	virtual bool operator < (Comparable& op2) = 0;
	virtual bool operator == (Comparable& op2) = 0;
};

class Circle : public Comparable{
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	virtual bool operator > (Comparable& op2);
	virtual bool operator < (Comparable& op2);
	virtual bool operator == (Comparable& op2);
};

bool Circle::operator > (Comparable& op2) {
	Circle* tmp = (Circle*)&op2;
	if (radius > tmp->getRadius())
		return true;
	else
		return false;
}

bool Circle::operator < (Comparable& op2) {
	Circle* tmp = (Circle*)&op2;
	if (radius < tmp->getRadius())
		return true;
	else
		return false;
}

bool Circle::operator == (Comparable& op2) {
	Circle* tmp = (Circle*)&op2;
	if (radius == tmp->getRadius())
		return true;
	else
		return false;
}

template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza중 큰 것의 반지름은 " << y.getRadius() << endl;
}
```

### 9번
```
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v; 
	int tmp = 0;
	double avg = 0.0;
	while (1) {
		cout << "정수를 입력하세요(0을 입력하면 종료) >> ";
		cin >> tmp;
		if (tmp == 0) break;
		v.push_back(tmp);
		avg += tmp;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		cout << "평균 = " << (double)avg / (double)v.size() << endl;
	}
}
```

### 10번
```
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string n, string c) { nation = n; c = capital; }
	string getNation() { return nation; }
	string getCaptial() { return capital; }
	bool nationCompare(string n) {
		if (nation == n)
			return true;
		else
			return false;
	}
};

int main() {
    vector<Nation> v;
    v.push_back(Nation("대한민국", "서울"));
    v.push_back(Nation("중국", "베이징"));
    v.push_back(Nation("북한", "평양"));
    v.push_back(Nation("미국", "와싱턴"));
    v.push_back(Nation("대만", "타이베이"));
    v.push_back(Nation("캐나다", "오타와"));
    v.push_back(Nation("스위스", "제네바"));
    v.push_back(Nation("프랑스", "파리"));
    v.push_back(Nation("이집트", "카이로"));

    cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****\n";

    while (true) {
        int num;
        cout << "정보 입력: 1, 퀴즈: 2, 종료 3 >> ";
        cin >> num;
        switch (num) {
        case 1:
            cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다.\n";
            cout << "나라와 수도를 입력하세요(no no 이면 입력끝)\n";
            for (int i = v.size() + 1;; i++) {
                string n, c;
                bool b;
                cout << i << ">>";
                cin >> n >> c;
                if (n == "no" && c == "no")
                    break;
                for (int j = 0; j < v.size(); j++)
                    if (b = v.at(j).nationCompare(n)) {
                        cout << "already exists !!\n";
                        i--;
                        break;
                    }
                if (b)
                    continue;
                v.push_back(Nation(n, c)); // 정상적인 입력 값이면 vector v에 입력 
            }
            break;

        case 2:
            int random;
            while (true) {
                string c;
                random = rand() % v.size(); // v에 들어있는 원소의 개수보다 작은 숫자를 얻음
                cout << v.at(random).getNation() << "의 수도는?";
                cin >> c;
                if (c == "exit")
                    break;
                else if (v.at(random).getCapital() == c) // 입력받은 수도가 맞으면 Correct 출력 
                    cout << "Correct !!\n";
                else
                    cout << "No !!\n";
            }
            break;

        case 3:
            return 0;
        }
    }
```
