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

### 4번
```

```
