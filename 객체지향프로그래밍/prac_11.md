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

```
