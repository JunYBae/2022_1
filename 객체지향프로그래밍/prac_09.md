## 실습문제 9장

### 1번
```
#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << " 로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
	string source, dest;
public:
	WonToDollar(double m) : Converter(m) {
		source = "원";
		dest = "달러";
	}
	virtual double convert(double src) { return src / ratio; }
	virtual string getSourceString() { return source; }
	virtual string getDestString() { return dest;  }
};


int main() {
	WonToDollar wd(1010);
	wd.run();
}
```

### 2번
```
#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << " 로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
};

class KmToMile : public Converter {
public:
	KmToMile(double ratio) : Converter(ratio) {}
	virtual string getSourceString() { return "KM"; }
	virtual string getDestString() { return "Mile"; }
	virtual double convert(double src) { return src / ratio; }
};


int main() {
	KmToMile toMile(1.609344);
	toMile.run();
}
```

### 3번
```
#include <iostream>
#include <string>
using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}

void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다. " << endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class ForLoopAdder : public LoopAdder {
public:
	ForLoopAdder(string name) : LoopAdder(name) { }
	virtual int calculate() {
		int tmp = 0;
		for (int i = getX(); i <= getY(); i++)
			tmp += i;
		return tmp;
	}
};

int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}
```

### 4번
```
#include <iostream>
#include <string>
using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}

void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다. " << endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class WhileLoopAdder : public LoopAdder {
public:
	WhileLoopAdder(string name) : LoopAdder(name) { }
	virtual int calculate() {
		int tmp = 0;
		int i = getX();
		while (i <= getY()) {
			tmp += i;
			i++;
		}
		return tmp;
	}
};

class DoWhileLoopAdder : public LoopAdder {
public:
	DoWhileLoopAdder(string name) : LoopAdder(name) { }
	virtual int calculate() {
		int tmp = 0;
		int i = getX();
		do {
			tmp += i;
			i++;
		} while (i <=getY());
		return tmp;
	}
};

int main() {
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do while Loop");

	whileLoop.run();
	doWhileLoop.run();
}
```

### 5번
```
#include <iostream>
#include <string>
using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	ANDGate() { }
	virtual bool operation() { 
		if (x && y) 
			return true; 
		else return false; }
};

class ORGate : public AbstractGate {
public:
	ORGate() { }
	virtual bool operation() {
		if (x || y)
			return true;
		else return false;
	}
};

class XORGate : public AbstractGate {
public:
	XORGate() { }
	virtual bool operation() {
		if (x != y)
			return true;
		else return false;
	}
};

int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}
```

### 6번
```
#include <iostream>
#include <string>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack {
	int stack[5] = { 0 };
	int tos = -1;
public:
	virtual bool push(int n) {
		if (size() == 5) {
			cout << "stack full " << endl;
			return false;
		}
		stack[++tos] = n;
		return true;
	}
	virtual bool pop(int& n) {
		if (size() == 0) {
			cout << "stack empty" << endl;
			return false;
		}
		n = stack[tos--];
		return true;
	}
	virtual int size() {
		return tos + 1;
	}
	void show() {
		cout << "| ";
		for (int i = 0; i <= tos; i++) {
			cout << stack[i] << ' ';
		}
		cout << "|" << endl;
	}
};

int main() {
	IntStack intStack;

	intStack.push(1);
	intStack.push(2);
	intStack.push(3);
	intStack.push(4);
	intStack.push(5);
	intStack.push(6);

	intStack.show();

	int n;
	intStack.pop(n);
	cout << n << " is popped" << endl;
	intStack.show();

	return 0;
}
```

### 7번
```

```
