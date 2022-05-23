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

```
