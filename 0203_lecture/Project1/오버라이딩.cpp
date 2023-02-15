#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//private > protected > public
class Student {
protected:
	string name;
	string uni;
	int age;
	int num;
public:
	Student() {

	}
	void lunch() {
		cout << "점심은학식 \n";
	}
};

class Kim : public Student { // 기본값 private
	
public:
	Kim (string name, string uni, int age, int num) : Student () {
		this->name = name;
		this->uni = uni;
		this->age = age;
		this->num = num;
	}

	void lunch() {
		cout << "점심은김가네김밥 \n";
	}
};

class Baek : public Student { //
	
public:
	Baek (string name, string uni, int age, int num) : Student() {
		this->name = name;
		this->uni = uni;
		this->age = age;
		this->num = num;
	}

	void lunch() {
		cout << "점심은백종원피자 \n";
	}
};

int main() {

	string name;
	string uni;
	int age;
	int num;
	
	cout << "name : ";
	cin >> name;
	cout << "학교 : ";
	cin >> uni;
	cout << "나이 : ";
	cin >> age;
	cout << "학번 : ";
	cin >> num;
	Kim a(name, uni, age, num);
	cout << "Kim";
	a.lunch();
	Baek b(name, uni, age, num);
	cout << "Baek";
	b.lunch();
	return 0;

	return 0;
}