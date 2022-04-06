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
