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

### 5-1번
```
#include <iostream>
#include <string>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) {
		red = r;	green = g;	blue = b;

	}
	void show() {
		cout << red << ' ' << green << ' ' << blue << endl;
	}

	Color operator+ (Color c2) {
		Color tmp;
		tmp.red = red + c2.red;
		tmp.blue = blue + c2.blue;
		tmp.green = green + c2.green;
		return tmp;
	}

	bool operator== (Color c2) {
		if ((red == c2.red) && (blue == c2.blue) && (green == c2.green))
			return true;
		else
			return false;
	}
};


int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}
```

### 5-2번
```
#include <iostream>
#include <string>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) {
		red = r;	green = g;	blue = b;

	}
	void show() {
		cout << red << ' ' << green << ' ' << blue << endl;
	}

	friend Color operator+ (Color c1, Color c2);
	friend bool operator== (Color c1, Color c2);
};

Color operator+ (Color c1, Color c2) {
	Color tmp;
	tmp.red = c1.red + c2.red;
	tmp.blue = c1.blue + c2.blue;
	tmp.green = c1.green + c2.green;
	return tmp;
}

bool operator== (Color c1, Color c2) {
	if ((c1.red == c2.red) && (c1.blue == c2.blue) && (c1.green == c2.green))
		return true;
	else
		return false;
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}
```

### 6-1번
```
#include <iostream>
#include <string>
using namespace std;

class Matrix {
	int m[2][2];
public:
	Matrix() : Matrix(0, 0, 0, 0) {}
	Matrix(int m1, int m2, int m3, int m4) {
		m[0][0] = m1;	m[0][1] = m2;
		m[1][0] = m3;	m[1][1] = m4;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				cout << m[i][j] << ' ';
		cout << "}" << endl;
	}

	Matrix operator+ (Matrix m);
	Matrix& operator+= (Matrix m);
	bool operator== (Matrix m);
};

Matrix Matrix::operator+ (Matrix m) {
	Matrix tmp;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			tmp.m[i][j] = this->m[i][j] + m.m[i][j];
	return tmp;
}

Matrix& Matrix::operator+= (Matrix m) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			this->m[i][j] += m.m[i][j];
	return *this;
}

bool Matrix::operator== (Matrix m) {
	bool check = true;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (this->m[i][j] != m.m[i][j])
				check = false;
	return check;
}

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
}
```

### 6-2번
```
#include <iostream>
#include <string>
using namespace std;

class Matrix {
	int m[2][2];
public:
	Matrix() : Matrix(0, 0, 0, 0) {}
	Matrix(int m1, int m2, int m3, int m4) {
		m[0][0] = m1;	m[0][1] = m2;
		m[1][0] = m3;	m[1][1] = m4;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				cout << m[i][j] << ' ';
		cout << "}" << endl;
	}

	friend Matrix operator+ (Matrix m1, Matrix m2);
	friend Matrix& operator+= (Matrix& m1, Matrix m2);
	friend bool operator== (Matrix m1, Matrix m2);
};

Matrix operator+ (Matrix m1, Matrix m2) {
	Matrix tmp;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			tmp.m[i][j] = m1.m[i][j] + m2.m[i][j];
	return tmp;
}

Matrix& operator+= (Matrix& m1, Matrix m2) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			m1.m[i][j] += m2.m[i][j];
	return m1;
}

bool operator== (Matrix m1, Matrix m2) {
	bool check = true;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (m1.m[i][j] != m2.m[i][j])
				check = false;
	return check;
}

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
}
```
