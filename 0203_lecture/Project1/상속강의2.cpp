#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Person {
protected:
	string name;
	string position;
public:
	void test() {
		cout << "Person의 테스트 함수입니다. \n";
	}
	string get_position() {
		return position;
	}
	//void get_position2() {
	//	cout << position;
	//}
};

class Student : public Person {
	string stu_id;
public:
	void aaa() { }
	Student(string position) {
		this->position = position;
	}
	void test() {
		cout << "Student의 테스트 함수입니다. \n";
	}
};

class Instructor : public Person {
public:
	Instructor(string position) {
		this->position = position;
	}
};

class Aaaaaa {
};

int main() {
	//Person p;
	//Person p = Person();
	//p.test();

	//Student stu = Student("홍길동");

	// Person p2 = Student();
	//p2.test();

	//Person *p3 = new Student();
	//p3->test(); //나중에배움



	Person p3[4] = { Instructor("강사"), Student("학생 1"), Student("학생 2"), Student("학생 3") };
	for (int i = 0; i < 4; i++) {
		cout << p3[i].get_position() << endl;
	}


	// p2.aaa();

	return 0;
}