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

### 13번
```
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	int a, b;

	cout << "***** 승리장에 오신 것을 환영합니다. *****\n";

	while (true)
	{
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>";
		cin >> a;

		if (a < 0 || a > 4)
		{
			cout << "다시 주문하세요!!\n";
			continue;
		}
		if (a == 4)
		{
			cout << "오늘 영업은 끝났습니다.\n";
			break;
		}

		cout << "몇인분?";
		cin >> b;

		switch (a)
		{
		case 1:
			cout << "짬뽕 " << b << "인분 나왔습니다\n";
			break;
		case 2:
			cout << "짜장 " << b << "인분 나왔습니다\n";
			break;
		case 3:
			cout << "군만두 " << b << "인분 나왔습니다\n";
			break;
		default:
			break;
		}
	}

	return 0;
}
```

### 14번
```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char sic[100];
	char* symbol;
	int front, rear;

	while (1) {
		cout << "? ";
		cin.getline(sic, 100);
		front = atoi(strtok(sic, " "));
		symbol = strtok(NULL, " ");
		rear = atoi(strtok(NULL, " "));

        if (*symbol == '+') {
            cout << front << " + " << rear << " = " << front + rear << endl;
        }
        else if (*symbol == '-') {
            cout << front << " - " << rear << " = " << front - rear << endl;
        }
        else if (*symbol == '*') {
            cout << front << " * " << rear << " = " << front * rear << endl;
        }
        else if (*symbol == '/') {
            cout << front << " / " << rear << " = " << front / rear << endl;
        }
        else if (*symbol == '%') {
            cout << front << " % " << rear << " = " << front % rear << endl;
        }
    }
}
```
### 15번
```
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
 
int main(){
    
    char sic[100];
    char *symbol;
    
    int front,rear;
    
    while(true){
        cout << "? ";
        cin.getline(sic,100);
        front = atoi(strtok(sic, " "));
        symbol = strtok(NULL, " ");
        rear = atoi(strtok(NULL, " "));
        
        if(*symbol == '+'){
            cout << front << " + " << rear << " = " << front+rear << endl;
        }
        else if(*symbol == '-'){
            cout << front << " - " << rear << " = " << front-rear << endl;
        }
        else if(*symbol == '*'){
            cout << front << " * " << rear << " = " << front*rear << endl;
        }
        else if(*symbol == '/'){
            cout << front << " / " << rear << " = " << front/rear << endl;
        }
        else if(*symbol == '%'){
            cout << front << " % " << rear << " = " << front%rear << endl;
        }
    } 
    return 0; 
}
```

### 16번
```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[10000];
	int alphabet[27] = { 0 };
	int tot = 0;

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다. 텍스트의 끝은 ;입니다. 10000개까지 가능합니다.\n";
	cin.getline(str, 10000, ';');
	
	for (int i = 0; i < strlen(str); i++) {
		if (isalpha(str[i])) {
			if (str[i] >= 'A' && str[i] <= 'Z') 
				str[i] = tolower(str[i]);
			tot++;
			alphabet[str[i] - 'a']++;
		}
	}

	cout << "총 알파벳 수 " << tot << endl << endl;
	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 'a') << "(" << alphabet[i] << ")";
		cout << "\t: ";
		for (int j = 1; j <= alphabet[i]; j++)
			cout << '*';
		cout << endl;
	}
	
}
```
