#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//-----------------------------------------------------------------------------

class Container {
    string title;  // 컨테이너 타이틀
    char* author; // 컨테이너 작성자 이름 (동적 할당)
    int    size;   // 컨테이너에 저장된 정수 배열 크기
    int* arr;    // 정수를 저장하는 배열 (동적 할당)
public:
    void display();
    Container(string title, char* author, int size, int arr[]);
    ~Container();
    void replace_subtitle(string from, string to);
    void replace_first_last();
};

// 여기에 Container 클래스 멤버 함수들을 구현할 것
void Container::display() {
    cout << "title:" << title << ", author:" << author << ", size:" << size << endl;
    cout << "arr[] = ";
    for (int i = 0; i < size - 1; i++)
        cout << arr[i] << ",";
    cout << arr[size - 1] << endl << endl;
}

Container::Container(string title, char* author, int size, int arr[]) {
    this->title = title;
    this->author = new char[(strlen(author) + 1)];
    strcpy(this->author, author);
    this->size = size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++)
        this->arr[i] = arr[i];
    cout << "Container::Container(title, author, size, arr[])" << endl;
    display();
}

Container::~Container() {
    cout << "Container::~Container()" << endl;
    display();
    delete [] author;
    delete [] arr;
}

void Container::replace_subtitle(string from, string to) {
    for (int tmp = 0; (tmp = title.find(from)) != -1;) {
        title.replace(tmp, from.size(), to);
    }
    display();
}

void Container::replace_first_last() {
    int i = title.find(' ');
    if (i != -1) {
        string first = title.substr(0, i);
        i = title.rfind(' ');
        string last = title.substr(i + 1);
        title.replace(i + 1, last.size(), first);
        title.replace(0, first.size(), last);
    }
}


int main() {
    string title;
    char author[] = "Chosun Universty";
    int arr[5] = { 1, 2, 3, 4, 5 };

    while (true) {
        cout << "title? ";
        getline(cin, title);
        if (title[title.size() - 1] == '\r')   // Windows의 경우 줄 끝의 '\r' 문자 삭제
            title.erase(title.size() - 1, 1);
        if (title == "exit") break;          // "exit" 입력할 때까지 반복 수행

        Container c(title, author, 5, arr);
       
        cout << "Replace \"title\" with \"name\" in the title." << endl;
        c.replace_subtitle("title", "name");

        cout << "Swap the first word and the last word in the title." << endl;
        c.replace_first_last();
    }
}
