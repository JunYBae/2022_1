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

```
