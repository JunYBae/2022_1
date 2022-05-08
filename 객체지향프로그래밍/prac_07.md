## 실습문제 7장

### 1-1번
```
#include <iostream>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() 
	{
		return title; 
	}
	Book& operator += (int p) {
		this->price += p;
		return *this;
	}
	Book& operator -= (int p) {
		this->price -= p;
		return *this;
	}
};


int main() {
	Book a("청준", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}
```

### 1-2번
```
#include <iostream>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() 
	{
		return title; 
	}

	friend Book& operator += (Book& b, int p);
	friend Book& operator -= (Book& b, int p);
	
};

Book& operator += (Book& b, int p) {
	b.price += p;
	return b;
}

Book& operator -= (Book& b, int p) {
	b.price -= p;
	return b;
}

int main() {
	Book a("청준", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}
```

### 2-1번
```
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() 
	{
		return title; 
	}

	bool operator== (int p) {
		if (this->price == p) return true;
		else return false;
	}

	bool operator== (string p) {
		if (this->title == p) return true;
		else return false;
	}

	bool operator== (Book p) {
		if ((title == p.title) && (price == p.price) && (pages == p.pages))
			return true;
		else
			return false;
	}
};


int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl;
	if (a == b) cout << "두 책이 같은 책입니다." << endl;
}
```

### 2-2번
```
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() 
	{
		return title; 
	}

	friend bool operator== (Book b, int p);
	friend bool operator== (Book b, string p);
	friend bool operator== (Book b, Book p);
};

bool operator== (Book b, int p) {
	if (b.price == p) return true;
	else return false;
}

bool operator== (Book b, string p) {
	if (b.title == p) return true;
	else return false;
}

bool operator== (Book b, Book p) {
	if ((b.title == p.title) && (b.price == p.price) && (b.pages == p.pages))
		return true;
	else
		return false;
}


int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl;
	if (a == b) cout << "두 책이 같은 책입니다." << endl;
}
```

### 3번
```
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() 
	{
		return title; 
	}
	
	bool operator!() {
		if (this->price == 0) return true;
		else return false;
	}

};


int main() {
	Book book("벼룩시장", 0, 50);
	if (!book) cout << "공짜다." << endl;
}
```

### 4번
```
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() 
	{
		return title; 
	}
	
	friend bool operator< (string str, Book b);
};

bool operator< (string str, Book b) {
	if (str.compare(b.title) < 0) return true;
	else return false;
}


int main() {
	Book a("청춘", 20000, 300);
	string b;
	cout << "책 이름을 입력하세요>>";
	getline(cin, b);
	if (b < a)
		cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
}
```

### 05번
```

```
