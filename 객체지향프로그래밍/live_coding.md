## 라이브코딩 연습

### 
```
※ 이번 실습은 2장과 3장에 대한 라이브 코딩 연습이다.

※ 아래 문제는 생성자, 위임생성자, 소멸자, set() 함수 등을 생성할 수 있는지 
  그리고 입력 및 출력 등을 할 수 있는지
  또는 C 문자열과 string 문자열을 비교 및 복사 할 수 있는지를 확인하는 문제임.

3. 아래 코드는 Person 클래스의 세 객체 p1, p2, p3을 선언하고 사용자로부터 인적정보를 입력 받아
   객체 p3의 각 멤버 값을 설정하여 변경한 후 이 객체를 출력하는 프로그램이다.
   아래 [프로그램 실행 결과]를 참고하여 Person 클래스를 작성하고 main() 함수 내의 코드를 완성하라.
//-----------------------------------------------------------------------------

int main() {
    Person p1;
    Person p2("p2"); // name
    Person p3("p3", 3, "Dong-gu Gwangju"); // (name, id, address)
    cout << endl;
/*
    int id;
    char name[40];
    string address;

    while (true) {

        TODO: "name and id? " 를 출력한 후 두 정보를 입력 받아 name과 id에 저장
              이름은 하나의 단어로 입력해야 함

        // 주의: 위 이름과 id를 입력할 때 엔터를 치는데 이 엔터(\n)는 이름과 id를 받은 후에도 
               입력 버퍼에 여전히 남이 있음; 아래 주소 입력 받기 전에 이 엔터를 먼저 읽어 들여 제거해야 함

        TODO: "address? " 를 출력한 후 주소를 입력 받아 address에 저장
              주소는 여러 단어로 지정할 수 있음

    	if (address[address.size()-1] == '\r') // Windows의 경우 줄 끝의 '\r' 문자 삭제
    		address.erase(address.size()-1, 1);

        p3.setName(name);
        p3.setId(id);
        p3.setAddress(address);
        p3.println();
        cout << endl;

        TODO: name이 "end"이고 address가 "quit exit"이면 
              while-loop를 빠져 나간다.
    }
*/
}

//-----------------------------------------------------------------------------
위 코드의 실행한 화면은 아래와 같다.

[프로그램 실행 결과]
//-----------------------------------------------------------------------------

Person::Person(...):n:p1, i:1, a:Seoul Jongno-gu
Person::Person(...):n:p2, i:1, a:Seoul Jongno-gu
Person::Person(...):n:p3, i:3, a:Dong-gu Gwangju

name and id? shim 12                // 사용자 입력
address? Seoul jongno gu            // 사용자 입력
n:shim, i:12, a:Seoul jongno gu

name and id? KIM 5                  // 사용자 입력
address? Daejeon susung gu          // 사용자 입력
n:KIM, i:5, a:Daejeon susung gu

name and id? end 4                  // 사용자 입력: 종료 조건
address? quit exit                  // 사용자 입력: 종료 조건
n:end, i:4, a:quit exit

Person::~Person():n:end, i:4, a:quit exit
Person::~Person():n:p2, i:1, a:Seoul Jongno-gu
Person::~Person():n:p1, i:1, a:Seoul Jongno-gu

//-----------------------------------------------------------------------------

1) Person 클래스를 생성하고 아래 세 개의 멤버 변수들을 포함시켜라. 
   그런 후 멤버 함수 Person::println()를 구현하라. 이 함수 구현 시
    "n:이름, i:id, a:주소" 순서로 멤버 값들을 출력하면 된다.
//-----------------------------------------------------------------------------
    char   name[20];    // 이름
    int    id;          // Identifier
    string address;     // 주소
//-----------------------------------------------------------------------------

2) 다음은 세 개의 생성자 함수를 구현하되, 
   Person p3("p3", 3, "Dong-gu Gwangju")를 위한 생성자 함수를 먼저 구현하라. 
   이 생성자는 각각의 매개변수 값을 이용하여 상응하는 멤버 변수를 초기화한다. 그런 후 아래를 출력한다.
   cout << "Person::Person(...):"; println();

   나머지 두 생성자 즉 p1, p2를 위한 생성자는 위임 생성자로 구현하라.
   p1용 생성자는 p2용 생성자를 호출하여 초기화하고, p2용 생성자는 p3용 생성자를 호출하여 초기화하라.
   즉, p1용 생성자는 위임 생성자이며 이것의 타겟 생성자는 p2용 생성자이다. 
      p2용 생성자 역시 위임 생성자이며 이것의 타겟 생성자는 p3용 생성자이다.

3) Person 클래스의 소멸자를 구현하라. 출력문장은 생성자를 참고하여 적절히 변형하라.
   여기까지 구현하고 프로그램을 실행하여 정상으로 실행하는지 확인하라.
   생성자 소멸자가 잘 구현되었으면 다음 단계로 넘어가라.

4) 이제 main() 함수 내의 /* */ 주석을 풀고 TODO를 구현하라. 

5) Person::setName(...), Person::setId(...), Person::setAddress(...)를 구현하라.
   이 함수들은 각각 하나의 매개변수를 가지는데 함수 호출 시 전달되는 함수 인자를 보고 매개변수의 타입을 유추하라.
   각 함수 구현 시 매개변수 값을 상응하는 멤버변수에 저장(또는 복사)하면 된다.

6) main() 함수 내의 while-loop를 빠져 나오기 위한 조건문을 완성하라.
   이름은 char name[20] 배열이므로 C-문자열 비교 함수를 호출해야 하고
   주소는 string address이므로 단순 비교 연산자를 이용하여 비교하면 된다.
```

### 연습문제 4장
```
※ 이번 실습은 4장에 대한 라이브 코딩 연습이다.
※ 아래 문제는 생성자 및 소멸자 함수 생성, 동적 메모리 생성 및 반납,
   string 클래스의 멤버 함수 활용 등을 할 수 있는지 확인함.

1. 아래 코드는 Container 클래스를 활용하는 프로그램의 윤곽이다.

//-----------------------------------------------------------------------------

class Container {
    string title;  // 컨테이너 타이틀
    char  *author; // 컨테이너 작성자 이름 (동적 할당)
    int    size;   // 컨테이너에 저장된 정수 배열 크기
    int   *arr;    // 정수를 저장하는 배열 (동적 할당)
public:
    void display();
    Container(string title, char *author, int size, int *arr);
    ~Container();
};

// 여기에 Container 클래스 멤버 함수들을 구현할 것

int main() {
	string title;
	char author[] = "Chosun Universty";
	int arr[5] = { 1, 2, 3, 4, 5 };

    while (true) {
    	cout << "title? ";
    	getline(cin, title);
    	if (title[title.size()-1] == '\r')   // Windows의 경우 줄 끝의 '\r' 문자 삭제
    		title.erase(title.size()-1, 1);
        if (title == "exit") break;          // "exit" 입력할 때까지 반복 수행

    	Container c(title, author, 5, arr);
    }
}

//-----------------------------------------------------------------------------

위 코드의 실행한 화면은 아래와 같다.
[프로그램 실행 결과]

//-----------------------------------------------------------------------------

title? First Last                                        // 사용자 입력
Container::Container(title, author, size, arr[])
title:First Last, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Container::~Container()
title:First Last, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

title? First title                                      // 사용자 입력
Container::Container(title, author, size, arr[])
title:First title, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Container::~Container()
title:First title, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

title? exit                                             // 사용자 입력

//-----------------------------------------------------------------------------

Container 클래스의 각 멤버 함수의 기능은 다음과 같다.

void display();
    각 멤버를 [프로그램 실행결과]처럼 출력하라. 예),
    title:First title long title of title Last, author:Chosun Universty, size:5
    arr[] = 1,2,3,4,5

이 함수는 모든 멤버 함수에서 호출됨 (각 멤버함수의 마지막 단계에서 호출)
단, 소멸자 함수의 경우 멤버를 delete하기 전에 이 함수를 먼저 호출해야 함 

Container(string title, char *author, int size, int arr[]);
    매개변수로 주어진 값을 각각의 해당 클래스 멤버 변수에 복사함
    먼저, 멤버변수 author와 arr은 동적으로 메모리를 할당 받아 포인터를 멤버 변수에 저장한다. 
    멤버 author는 (매개변수 author 문자열의 길이+1)만큼만 할당 받으면 되고, 
    멤버 arr은 size 개수만큼 할당 받으면 됨. 
    메모리를 할당 받은 후 매개변수 author[]와 arr[]의 내용을 모두 
    해당 멤버변수 author[]와 arr[]로 복사할 것. 
    이때 author는 strcpy() 사용하고(교재 p.257의 생성자 참조), 
    arr[]는 for문 이용하여 각 원소 arr[i] 별로 반복 복사함.
    "Container::Container(title, author, size, arr[])" 출력 후 
    display()호출하여 각 멤버 출력한다.

~Container();
    "Container::~Container()" 출력하고 
    display() 호출한 후 
    동적으로 할당 받은 멤버들 메모리 반납

1) 위 [프로그램 실행 결과]를 참고하여 Container 클래스의 멤버 함수들을 작성하라.

2) 기존 main() 함수에 아래 내용을 새로 추가하라.

//-----------------------------------------------------------------------------

int main() {
    ...
    while (true) {
        ...
        Container c(title, author, 5, arr);
        // --- 여기까지 기존과 동일하고 아래부터 새로 추가된 것임 ---

    	cout << "Replace \"title\" with \"name\" in the title." << endl;
    	c.replace_subtitle("title", "name");

    	cout << "Swap the first word and the last word in the title." << endl;
    	c.replace_first_last();
    }
}

//-----------------------------------------------------------------------------

위 [프로그램의 실행결과]는 아래와 같다.

//-----------------------------------------------------------------------------

title? First title long title of title Last          // 사용자 입력
Container::Container(title, author, size, arr[])
title:First title long title of title Last, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Replace "title" with "name" in the title.
title:First name long name of name Last, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Swap the first word and the last word in the title.
title:Last name long name of name First, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Container::~Container()
title:Last name long name of name First, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

title? First Last                                  // 사용자 입력
Container::Container(title, author, size, arr[])
title:First Last, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Replace "title" with "name" in the title.
title:First Last, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Swap the first word and the last word in the title.
title:Last First, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Container::~Container()
title:Last First, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

title? First                                      // 사용자 입력
Container::Container(title, author, size, arr[])
title:First, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Replace "title" with "name" in the title.
title:First, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Swap the first word and the last word in the title.
title:First, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

Container::~Container()
title:First, author:Chosun Universty, size:5
arr[] = 1,2,3,4,5

title? exit                                      // 사용자 입력

//-----------------------------------------------------------------------------

위와 같은 결과가 나오도록 기존 Container 클래스에 아래의 두 멤버 함수를 구현하여라.
두 함수 구현하는데 많은 시간이 걸릴 것이다. 시간에 구애 받지 말고 끝까지 구현해 보라.
실제 시험에서는 아래처럼 상세한 구현 설명이 없을 것이다.

void replace_subtitle(string from, string to);
    title 문자열에서 from 단어를 찾아 모두 to 단어로 변경 후 display() 호출함
    for문을 이용하여 from을 찾지 못할 때까지 위 단계 반복
    (string 클래스의 find(), replace() 함수 사용)

void replace_first_last();
    title 문자열에서 첫 단어와 마지막 단어의 위치를 서로 바꾼 후 display() 호출함
    단어와 단어의 구분은 스페이스 문자 ' '임
    첫 단어는 문자열 처음부터 ' ' 를 찾아 서브 문자열 first 발췌
    마지막 단어는 문자열 끝부터 ' '를 찾아 서버 문자열 last 발췌
    title의 첫 단어를 마지막 단어 last로 교체하고 
    title의 마지막 단어를 다시 첫 단어 first로 교체
    string 클래스의 find(), rfind(), substr(), replace() 함수 사용
```
