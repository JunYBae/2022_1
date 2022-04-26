## 실습문제 2번

### 01번
```
#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 100; i++) {
		cout << i << "\t";
		if (i % 10 == 0)
			cout << endl;
	}
}
```

### 02번
```
#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 9; i++) {
		for (int k = 1; k <= 9; k++) {
			cout << k << "x" << i << "=" << i * k << '\t';
		}
		cout << endl;
	}
}
```

### 03번
```
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout << ((a > b) ? a : b )<< endl;
}
```

### 04번
```
#include <iostream>
using namespace std;

int main() {
	double a[5];
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	double big = 0;
	for (int i = 0; i < 5; i++) {
		if (big < a[i])
			big = a[i];
	}
	cout << big;
}
```

### 05번
```
#include <iostream>
using namespace std;

int main() {
	char name[100];
	int count = 0;
	cin.getline(name, 100);

	for (int i = 0; name[i] != '\n'; i++) {
		if (name[i] == 'x')
			count++;
	}
	cout << count;
}
```

### 06번
```
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char a[100], b[100];
	cin >> a;
	cin >> b;
	if (strcmp(a, b) == 0)
		cout << "같다";
	else
		cout << "다르다";
}
```

### 07번
```
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char name[100];
	cout << "종료하고싶으면 yes >>";
	cin.getline(name, 100);
	while(strcmp(name, "yes") != 0) {
		cout << "종료하고싶으면 yes >>";
		cin.getline(name, 100);
	}
	cout << "종료";
}
```

### 08번
```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int max = 0;
	char name[100], str[100];
	for (int i = 0; i < 5; i++) {
		cin.getline(name, 100, ';');
		cout << i + 1 << " : " << name << endl;
		if (max < strlen(name)) {
			max = strlen(name);
			strcpy(str, name);
		}
	}
	cout << str;
}
```

### 09번
```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char name[100], address[100];
	int age;
	cout << "이름은?";
	cin.getline(name, 100);
	cout << "주소는?";
	cin.getline(address, 100);
	cout << "나이는?";
	cin >> age;

	cout << name << ", " << address << ", " << age << "세";
}
```

### 10번
```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char name[100];
	cin.getline(name, 100);
	for (int i = 0; i < strlen(name); i++) {
		for (int k = 0; k <= i; k++) {
			cout << name[k];
		}
		cout << endl;
	}
}
```

### 11번
```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int k, n = 0;
	int sum = 0;
	printf("끝수를 입력>>");
	scanf_s("%d", &n);
	for (int k = 1; k <= n; k++)
		sum += k;
	cout << sum;
}
```

### 12번
```

```
