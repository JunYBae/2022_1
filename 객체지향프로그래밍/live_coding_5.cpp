#include <iostream>
#include <string>
using namespace std;
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

string& Person::getName() {
    return name;
}

void Person::println() { // "name: SHIM, id: 100" 양식으로 출력;
    cout << "name: " << name << ", id: " << id << endl;
}

Person::Person() {
    string name = "";
    id = 0;
}

Person::Person(const string& name, int id) {
    this->name = name;
    this->id = id;
}

void Person::set(const string& name, int id) {
    this->name = name;
    this->id = id;
}

void Person::get(string& name, int& id) {
    name = this->name;
    id = this->id;
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
    for (int i = 0; i < count; ++i)
        persons[i].println();
    cout << endl;
}

School::School(int capacity) {
    this->capacity = capacity;
    this->count = 0;
    persons = new Person[capacity];
    cout << "School::School(capacity): persons[" << capacity << "] allocated" << endl;
}

School::~School() {
    delete[] persons;
    cout << "School::~School(): persons[] deleted" << endl;
}

void School::copy_array(Person students[], int count) {
    this->count = count;
    for (int i = 0; i < count; i++) {
        persons[i] = students[i];
    }
}

Person& School::get_person(int index) {
    return this->persons[index];
}


School::School(const School& sc) {
    this->capacity = sc.capacity;
    this->count = sc.count;
    this->persons = new Person[capacity];
    for (int i = 0; i < count; i++)
        persons[i] = sc.persons[i];
    cout << "School::School(const School& sc)" << endl;
    cout << "persons[" << capacity << "] allocated, "
        << count << " person(s) copied" << endl;
}



int School::find_person(const string& name) {
    int i = 0;
    for (i = 0; i < count; i++) {
        if (persons[i].getName().compare(name) == 0) {
            return i;
        }
    }
    return -1;
}




// 여기에 School 클래스 멤버 함수들을 구현할 것
void search_and_update(School sc, const string& name) {
    sc.display();
    cout << "--------------------------------" << endl;
    int index = sc.find_person(name);
    if (index < 0) return;
    cout << "find_person: " << index << endl;
    Person& s = sc.get_person(index);
    cout << "s: "; s.println();
    s.set("p3", 13);
    Person& p = sc.get_person(sc.find_person("p3"));
    cout << "p: "; p.println();
    cout << endl;
    sc.display();
}



int main()
{
    Person students[3] = { Person("st1", 1), Person("st2", 2), };
    for (int i = 0; i < 3; ++i)
        students[i].println();
    string name("st2");
    int id;
    cout << "student name and id? ";
    cin >> name >> id;
    students[2].set(name, id);
    students[2].println();
    cout << "--------------------------------" << endl;
    School sc(10);
    sc.display();
    cout << "--------------------------------" << endl;
    sc.copy_array(students, 3);
    sc.display();
    cout << "--------------------------------" << endl;
    search_and_update(sc, name);
    cout << "--------------------------------" << endl;

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

    s.get(name, id);
    cout << "name: " << name << ", id: " << id << endl;
    cout << "--------------------------------" << endl;
}
