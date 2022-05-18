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
