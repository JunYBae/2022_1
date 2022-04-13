## 라이브코딩 연습

### 연습문제 3장장
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

### 연습문제 5장
```
※ 이번 실습은 5장에 대한 라이브 코딩 연습이다.
※ 아래 문제는 생성자 및 소멸자 함수 생성, 동적 메모리 생성 및 반납, 복사 생성자 생성 등을 할 수 있는지 확인함.

5. 아래 코드는 Person과 School 클래스를 활용하는 프로그램의 윤곽이다.

//-----------------------------------------------------------------------------
// (코드 추가 1) 아래 코드를 소스 파일에 추가하라.
//-----------------------------------------------------------------------------

class Person {
    string name; // 사람 이름
    int id;      // 사람 id
public:
    Person();                             // name은 빈 문자열, id는 0을 설정
    Person(const string& name, int id);   // 매개변수 값들을 상응하는 멤버 변수에 저장
    void set(const string& name, int id); // 객체의 이름과 id를 각각 상응하는 매개변수 값으로 변경함
    void get(string& name, int& id);      // 객체의 이름과 id를 상응하는 매개변수를 통해 전달 받음
    string& getName();                    // 멤버 변수 name의 참조를 리턴
    void println(); 
};

void Person::println() { // "name: SHIM, id: 100" 양식으로 출력;
    cout << "name: " << name << ", id: " << id << endl;
}

// 여기에 Person 클래스 멤버 함수들을 구현할 것

class School {
    Person* persons;  // Person 객체를 저장할 배열(동적으로 할당함)
    int capacity;     // 할당 받은 persons 배열의 전체 크기
    int count;        // 현재 persons[]에 삽입된 객체들의 개수
public:
    void display();
    School(int capacity); 
    School(const School& sc);
    ~School();
    void copy_array(Person arr[], int arr_len);
    int find_person(const string& name);
    Person& get_person(int index);
};

void School::display() { // persons[]에 현재 저장된 모든 Person 객체의 인적 정보를 출력
    cout << "display(): count " << count << endl;
    for (int i=0; i < count; ++i)
        persons[i].println();
    cout << endl;
}

// 여기에 School 클래스 멤버 함수들을 구현할 것

int main()
{
    Person students[3] = { Person("st1", 1), Person("st2", 2), };
    for (int i = 0; i < 3; ++i)
        students[i].println();
    //string name("st2");
    //int id;
    //cout << "student name and id? ";
    //cin >> name >> id;
    //students[2].set(name, id);
    //students[2].println();
}

//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

name: st1, id: 1
name: st2, id: 2
name: , id: 0

//-----------------------------------------------------------------------------
// 1) 위와 같은 실행 결과가 나오도록 Person 클래스의 생성자들을 구현하라. 
//    지금 모두 다 구현할 필요는 없고 필요한 함수만 구현해도 실행된다. 
//    구현 시 클래스 내의 함수선언 옆의 주석을 참고하라.
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// (코드 추가 2) 기존 main() 함수의 맨 뒤 (//students[2].println(); 문장 뒤) 에 아래 내용을 새로 추가하라.
//-----------------------------------------------------------------------------

    cout << "--------------------------------" << endl;
    School sc(10);
    sc.display();

//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------
name: st1, id: 1
name: st2, id: 2
name: , id: 0
--------------------------------
School::School(capacity): persons[10] allocated
display(): count 0

School::~School(): persons[] deleted
//-----------------------------------------------------------------------------
// 2) 위와 같은 실행 결과가 나오도록 School 클래스의 생성자와 소멸자를 구현하라. 
//    School 클래스의 생성자: 
         멤버 capacity, count 값 설정; 
//       capacity 개수의 원소를 저장할 수 있는 Person 배열 메모리를 할당한 후 persons 포인터에 저장
//       그런 후 아래 문장 출력; 
    cout << "School::School(capacity): persons[" << capacity << "] allocated" << endl;

//    소멸자: 동적으로 할당 받은 persons 배열 메모리 반납한 후 아래 문장 출력
    cout << "School::~School(): persons[] deleted" << endl;
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// (코드 추가 3) 기존 main() 함수의 맨 뒤에 아래 내용을 새로 추가하라.
//-----------------------------------------------------------------------------

    cout << "--------------------------------" << endl;
    sc.copy_array(students, 3);
    sc.display();

//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

... // 기존과 동일
--------------------------------
display(): count 3
name: st1, id: 1
name: st2, id: 2
name: , id: 0

School::~School(): persons[] deleted

//-----------------------------------------------------------------------------
// 3) 위와 같은 실행 결과가 나오도록 School::copy_array() 를 구현하라. 
//    이 함수는 arr[i] 배열의 arr_len개의 원소 모두를 persons[i]에 저장한다.
//    그런 후 count 값 설정(실행 결과 참고)
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// (코드 추가 4) 기존 main() 함수 앞에 아래 함수를 새로 추가하라.
//   주의: 아래 함수의 매개변수 sc는 call by value로 호출되었으며 call by reference가 아님.
//-----------------------------------------------------------------------------
void search_and_update(School sc, const string& name) {
    sc.display();
}
    
//-----------------------------------------------------------------------------
// (코드 추가 4-1) 기존 main() 함수의 맨 마지막에 아래 내용을 새로 추가하고,
//               main() 함수 내의 //string name("st2"); 문장의 주석을 풀어라.
//-----------------------------------------------------------------------------

    cout << "--------------------------------" << endl;
    search_and_update(sc, name);
    cout << "--------------------------------" << endl;

//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

... // 기존과 동일
--------------------------------
School::School(const School& sc)
persons[10] allocated, 3 person(s) copied
display(): count 3
name: st1, id: 1
name: st2, id: 2
name: , id: 0

School::~School(): persons[] deleted
--------------------------------
School::~School(): persons[] deleted

//-----------------------------------------------------------------------------
// 4) 위와 같은 실행 결과가 나오도록 School의 복사생성자를 구현하라. 
//    복사생성자의 마지막에 아래 출력 문장을 추가하라.
    cout << "School::School(const School& sc)" << endl;
    cout << "persons[" << capacity << "] allocated, "
         << count << " person(s) copied" << endl;
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// (코드 추가 5) 기존 search_and_update() 함수 내의 맨 뒤에 아래 코드를 새로 추가하라.
//-----------------------------------------------------------------------------

    cout << "--------------------------------" << endl;
    int index = sc.find_person(name);
    if (index < 0) return;
    cout << "find_person: " << index << endl;
    
//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

... // 기존과 동일
--------------------------------
find_person: 1
School::~School(): persons[] deleted
--------------------------------
School::~School(): persons[] deleted

//-----------------------------------------------------------------------------
// 5) 위와 같은 실행 결과가 나오도록 School::find_person()을 구현하라. 
//    이 함수는 persons[] 내의 삽입된 객체들 중 매개변수 name과 동일한 이름을 가진 객체를 찾아서
//    그 객체의 persons[] 배열 인덱스를 반환한다. 못 찾으면 -1을 리턴하라.
//    또한 Person::getName()도 구현하라. 이 함수는 Person의 멤버 변수 name의 참조를 리턴한다.
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// (코드 추가 6) 기존 search_and_update() 함수 내의 맨 뒤에 아래 코드를 새로 추가하라.
//-----------------------------------------------------------------------------

    Person& s = sc.get_person(index);
    cout << "s: "; s.println();
    
//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

... // 기존과 동일
--------------------------------
find_person: 1
s: name: st2, id: 2
... // 기존과 동일

//-----------------------------------------------------------------------------
// 6) 위와 같은 실행 결과가 나오도록 School::get_person()을 구현하라. 
//    이 함수는 persons 배열의 index 위치의 객체에 대한 참조를 반환한다.
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// (코드 추가 7) 기존 search_and_update() 함수 내의 맨 뒤에 아래 코드를 새로 추가하라.
//-----------------------------------------------------------------------------

    s.set("p3", 13);
    Person& p = sc.get_person(sc.find_person("p3"));
    cout << "p: "; p.println();
    cout << endl;
    sc.display();
    
//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

... // 기존과 동일
--------------------------------
find_person: 1
s: name: st2, id: 2
p: name: p3, id: 13     // 이름과 id가 변경되었음

display(): count 3
name: st1, id: 1
name: p3, id: 13        // 이름과 id가 변경되었음
name: , id: 0

... // 기존과 동일

//-----------------------------------------------------------------------------
// 7) 위와 같은 실행 결과가 나오도록 Person::set()을 구현하라. 
//    이 함수는 매개변수 name과 id의 값으로 상응하는 Person의 멤버변수 값을 변경한다.
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// (코드 추가 8) 기존 main() 함수 내의 맨 뒤에 아래 코드를 새로 추가하라.
//-----------------------------------------------------------------------------
    sc.display(); 
    cout << "--------------------------------" << endl;
    int index = sc.find_person("p3");
    if (index < 0)
        cout << "p3 NOT found" << endl;
    else
        cout << "oh! NO! ERROR" << endl;
    Person& s = sc.get_person(sc.find_person(name));
    cout << "s: "; s.println();
    cout << "--------------------------------" << endl;
   
//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

... // 기존과 동일

School::~School(): persons[] deleted
--------------------------------
display(): count 3
name: st1, id: 1
name: st2, id: 2   // 이름과 id가 변경되지 않고 원래 값을 가지고 있음
name: , id: 0

--------------------------------
p3 NOT found
s: name: st2, id: 2
--------------------------------
School::~School(): persons[] deleted




//-----------------------------------------------------------------------------
// (코드 추가 9) 기존 main() 함수 내의 맨 뒤에 아래 코드를 새로 추가하라.
//            그리고 main() 함수 내의 //int id; 문장의 주석을 풀어라.
//-----------------------------------------------------------------------------

    s.get(name, id);
    cout << "name: " << name << ", id: " << id << endl;
    cout << "--------------------------------" << endl;
   
//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

... // 기존과 동일
--------------------------------
name: st2, id: 2
--------------------------------
School::~School(): persons[] deleted

//-----------------------------------------------------------------------------
// 9) 위와 같은 실행 결과가 나오도록 Person::get()을 구현하라. 
//    이 함수는 Person의 멤버변수 name과 id의 값를 상응하는 매개변수를 통해 얻어 온다.
//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
// (코드 추가 10) 기존 main() 함수 내의 아래 코들의 주석을 모두 해제하라.
//-----------------------------------------------------------------------------

    cout << "student name and id? ";
    cin >> name >> id;
    students[2].set(name, id);
    students[2].println();
   
//-----------------------------------------------------------------------------
// 위 프로그램의 실행 결과는 아래와 같다.
//-----------------------------------------------------------------------------

name: st1, id: 1
name: st2, id: 2
name: , id: 0
student name and id? HONG 111
name: HONG, id: 111
--------------------------------
School::School(capacity): persons[10] allocated
display(): count 0

--------------------------------
display(): count 3
name: st1, id: 1
name: st2, id: 2
name: HONG, id: 111

--------------------------------
School::School(const School& sc)
persons[10] allocated, 3 person(s) copied
display(): count 3
name: st1, id: 1
name: st2, id: 2
name: HONG, id: 111

--------------------------------
find_person: 2
s: name: HONG, id: 111
p: name: p3, id: 13

display(): count 3
name: st1, id: 1
name: st2, id: 2
name: p3, id: 13

School::~School(): persons[] deleted
--------------------------------
display(): count 3
name: st1, id: 1
name: st2, id: 2
name: HONG, id: 111

--------------------------------
p3 NOT found
s: name: HONG, id: 111
--------------------------------
name: HONG, id: 111
--------------------------------
School::~School(): persons[] deleted

//-----------------------------------------------------------------------------
// 끝. 수고하셨어요.
//-----------------------------------------------------------------------------


```

### 연습문제 6장
```
※ 이번 실습은 6장에 대한 라이브 코딩 연습이다.

6. 이 문제는 생성자, 소멸자, 중복함수, 디폴트 매개변수, static 멤버를 생성할 수 있는 능력을 확인한다.

//-----------------------------------------------------------------------------
// (코드추가 1) 아래 코드를 소스파일에 추가하라.
        이 코드는 Cal 클래스의 객체 c1을 선언하고 이 객체의 세 멤버 함수를 호출한다.
//      Cal::add(), Cal::add(x), Cal::add(x, y)
//      아래 코드에서 주석은 풀지 마라.
//-----------------------------------------------------------------------------

int x = 10, y = 20;

void function_overload()
{
    Cal c1(100, 200);
    cout << "c1.add(): " << c1.add() << endl << endl;

    //cout << "x value to add? ";
    //cin >> x;
    cout << "c1.add(" << x << "): " << c1.add(x) << endl << endl;

    //cout << "x, y values to add? ";
    //cin >> x >> y;
    cout << "c1.add(" << x << "," << y << "): " << c1.add(x, y) << endl << endl;
}

int main() {
    function_overload();
}

//-----------------------------------------------------------------------------
// 실행 결과 1: 위 코드의 실행결과는 아래와 같다.
//-----------------------------------------------------------------------------

Cal::Cal(100, 200)
c1.add(): 300

c1.add(10): 210

c1.add(10,20): 30

Cal::~Cal(): x=100, y=200

//-----------------------------------------------------------------------------
// 1) 위 [프로그램 실행 결과]를 참고하여 Cal 클래스를 작성하라.
//    이 클래스는 정수형 두 멤버 변수 x, y와 생성자, 소멸자, 그리고
//    세 개의 add() 멤버 함수(중복 함수)를 가지고 있다.
//    생성자: 두 매개변수 값을 각각 Cal의 멤버 변수 x, y에 저장 후 [실행 결과]처럼 출력
//    소멸자: [실행 결과]처럼 출력
//    add(): 두 멤버 변수 x, y의 덧셈 결과를 리턴 
//    add(10): 인자인 10과 y 멤버 변수의 덧셈 결과를 리턴 
//    add(10, 20): 두 인자인 10과 20의 덧셈 결과를 리턴
//-----------------------------------------------------------------------------
   
   
//-----------------------------------------------------------------------------
// (코드추가 2) 아래 코드를 기존 main() 함수 위에 추가하고 main()도 수정하라.
//           아래 코드는 Cal 클래스의 객체 c1, c2, c3 세 객체를 각각 동적으로 할당 받은 후
//           add() 멤버 함수를 호출한다.
//-----------------------------------------------------------------------------
void default_parameter()
{
    Cal *c1 = new Cal();
    cout << "c1->add(): " << c1->add() << endl << endl;

    Cal *c2 = new Cal(x);
    cout << "c2->add(): " << c2->add() << endl << endl;

    Cal *c3 = new Cal(x, y);
    cout << "c3->add(): " << c3->add() << endl << endl;

    //Cal::print_count();
    //Cal *cal = TODO: 원소 5개를 가진 Cal 배열을 동적으로 할당하라.
    //Cal::print_count();

    TODO: 실행결과를 보고 여기에 필요한 코드를 더 추가하라.
}

int main() {
    //function_overload();
    default_parameter();
}

//-----------------------------------------------------------------------------
// 실행 결과 2 
//-----------------------------------------------------------------------------

Cal::Cal(100, 200)
c1->add(): 300

Cal::Cal(10, 200)
c2->add(): 210

Cal::Cal(10, 20)
c3->add(): 30

Cal::~Cal(): x=10, y=200
Cal::~Cal(): x=10, y=20
Cal::~Cal(): x=100, y=200

//-----------------------------------------------------------------------------
// 2) 위 [실행 결과 2]를 참고하여 Cal 클래스의 생성자를 수정하라. 하나의 생성자만으로 구현해야 함.
//    주의: 새로운 생성자를 추가하지 말고 기존의 생성자를 수정하여 동일한 결과가 나오게 해야 함
//    실행결과를 보고 default_parameter() 내의 TODO 부분을 완성하라.
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// (코드추가 3) 기존 default_parameter() 함수 내의 주석을 해제하라.
//           이 함수 내의 마지막에 아래 코드를 추가하라.
//-----------------------------------------------------------------------------

    Cal::print_count();
    TODO: 동적으로 할당 받은 배열 cal의 메모리 반납하라.
    Cal::print_count();

//-----------------------------------------------------------------------------
// 실행 결과 3
//-----------------------------------------------------------------------------
Cal::Cal(100, 200)
c1->add(): 300

Cal::Cal(10, 200)
c2->add(): 210

Cal::Cal(10, 20)
c3->add(): 30


total count: 3

Cal::Cal(100, 200)
Cal::Cal(100, 200)
Cal::Cal(100, 200)
Cal::Cal(100, 200)
Cal::Cal(100, 200)

total count: 8

Cal::~Cal(): x=10, y=200
Cal::~Cal(): x=10, y=20
Cal::~Cal(): x=100, y=200

total count: 5

Cal::~Cal(): x=100, y=200
Cal::~Cal(): x=100, y=200
Cal::~Cal(): x=100, y=200
Cal::~Cal(): x=100, y=200
Cal::~Cal(): x=100, y=200

total count: 0

//-----------------------------------------------------------------------------
// 3) 위 [프로그램 실행 결과]를 참고하여 Cal 클래스 내부에 static 멤버 변수와 static 멤버 함수를 
//    추가하고 구현하라.
//    이 클래스 내부에 정수형 static 멤버 변수 count를 선언하고 
//    적절한 곳에서 이 멤버 변수를 0으로 초기화하라.
//    생성자 함수: count 값을 1 증가 
//    소멸자 함수: count 값을 1 감소
//    print_count(): 실행결과처럼 출력
//    실행결과를 보고 default_parameter() 내의 TODO 부분을 완성하라.
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// (코드추가 4) main() 함수 내의 주석을 풀어라. 
//           그리고 function_overload() 내의 주석도 풀어서 키보드에서 x, y 값을 읽도록 하라.
//           아래는 프로그램 실행결과이다.
//-----------------------------------------------------------------------------

Cal::Cal(100, 200)
c1.add(): 300

x value to add? 1000           // 사용자 입력
c1.add(1000): 1200

x, y values to add? 1000 2000  // 사용자 입력
c1.add(1000,2000): 3000

Cal::~Cal(): x=100, y=200
Cal::Cal(100, 200)
c1->add(): 300

Cal::Cal(1000, 200)
c2->add(): 1200

Cal::Cal(1000, 2000)
c3->add(): 3000


total count: 3

Cal::Cal(100, 200)
Cal::Cal(100, 200)
Cal::Cal(100, 200)
Cal::Cal(100, 200)
Cal::Cal(100, 200)

total count: 8

Cal::~Cal(): x=1000, y=200
Cal::~Cal(): x=1000, y=2000
Cal::~Cal(): x=100, y=200

total count: 5

Cal::~Cal(): x=100, y=200
Cal::~Cal(): x=100, y=200
Cal::~Cal(): x=100, y=200
Cal::~Cal(): x=100, y=200
Cal::~Cal(): x=100, y=200

total count: 0

```
