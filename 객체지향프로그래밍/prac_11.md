## 실습문제 11장

### 1번
```
#include <iostream>
using namespace std;

int main() {
	int ch, count = 0;

	while ((ch = cin.get()) != EOF) {
		if (ch == 'a')
			count++;
		if (ch == '\n')
			break;
	}
	cout << "a의 갯수는 " << count << endl;
}
```

### 2번
```
#include <iostream>
using namespace std;

int main() {
	int count = 0;
	char ch;

	while (true) {
		cin.get(ch);
		if (cin.eof())
			break;
	
		if (ch == '\n')
			break;

		if (ch == ' ')
			count++;
	}
	cout << " ' '의 갯수는 " << count << endl;
}
```

### 3번
```
#include <iostream>
using namespace std;

int main() {
	int ch;

	cin.ignore(100, ';');
	while ((ch = cin.get()) != EOF) {
		cout.put(ch);
		if (ch == '\n')
			cin.ignore(100, ';');
	}
}
```

### 4번
```
#include <iostream>
using namespace std;

int main() {
	int ch;

	while ((ch = cin.get()) != EOF) {
		if (ch == ';') {
			cout.put('\n');
			cin.ignore(100, '\n');
		}
		else
			cout.put(ch);
	}
}
```

### 5번
```
#include <iostream>
#include <string>
using namespace std;

int main() {
	string cmd;
	while (true) {
		cout << "종료할려면 exit을 입력하세요 >> ";
		getline(cin, cmd);
		if (cmd == "exit") {
			cout << "프로그램을 종료합니다....";
			return 0;
		}
	}
}
```

### 6번
```
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void showNumber(const double& num) {
	cout << setw(15) << setfill('_') << num;
}

void showSqrt(const double& num) {
	cout << setprecision(3) << setw(15) << setfill('_') << sqrt(num) << endl;
}

int main() {
	cout.setf(ios::left);
	cout << setw(15) << "Number";
	cout << setw(15) << "Square";
	cout << setw(15) << "Square Root" << endl;
	for (int i = 0; i <= 45; i = i + 5) {
		cout.precision(4);
		cout << setw(15) << setfill('_') << i;
		cout << setw(15) << setfill('_') << i*i;
		cout << setprecision(3) << setw(15) << setfill('_') << sqrt(i) << endl;
	}
}
```

### 7번
```

```

### 8번
```
#include <iostream>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius; this->name = name;
	}
	friend istream& operator>> (istream& ins, Circle& a);
	friend ostream& operator<< (ostream& stream, Circle a);
};

istream& operator>> (istream& ins, Circle& a) {
	cout << "반지름 >> ";
	ins >> a.radius;
	cout << "이름 >> ";
	ins >> a.name;
	return ins;
}

ostream& operator<< (ostream& stream, Circle a) {
	stream << "(반지름" << a.radius << "인 " << a.name << ")";
	return stream;
}

int main() {
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}
```

### 9번
```

```
