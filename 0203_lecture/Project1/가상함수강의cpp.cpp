#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Person {
protected:
	string name;
public:
	virtual ~Person() {
		cout << "사람의 소멸자입니다." << endl;
	}
	virtual void info() {
		cout << "사람입니다." << endl;
	}
};

class Student : public Person {
	string stu_id;
public:
	~Student() {
		cout << "학생의 소멸자입니다." << endl;
	}
	void info() {
		cout << "학생입니다." << endl;
	}
	void test() {
		cout << "학생의 test 함수" << endl;
	}
};

class Instructor : public Person {
public:
	~Instructor() {
		cout << "강사의 소멸자입니다." << endl;
	}
	void info() {
		cout << "강사입니다." << endl;
	}
};

int main() {
	// 업캐스팅
	Person s = Student(); // ~Person
	s.info(); // 정적 바인딩. 사람입니다. 출력

	Person* ss = new Student();
	ss->info(); // 동적 바인딩 .. 학생입니다. 출력
	// ss->test(); // 오류. Person에 없는 멤버에는 접근할 수 없음.
	delete ss;


	Student stu; // 정적 메모리
	Person* sss = &stu;
	sss->info();
	// delete sss; // delete 사용하게 되면 실행중에 오류 발생(런타임 에러)


	Person* per_arr[3] = { new Student(), new Instructor(), new Student() };
	for (int i = 0; i < 3; i++) {
		per_arr[i]->info();
	}

	for (int i = 0; i < 3; i++) {
		delete per_arr[i];
	}

	// Person persons[2] = { Student(), Student() };

	return 0;
}