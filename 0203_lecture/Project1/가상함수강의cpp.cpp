#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Person {
protected:
	string name;
public:
	virtual ~Person() {
		cout << "����� �Ҹ����Դϴ�." << endl;
	}
	virtual void info() {
		cout << "����Դϴ�." << endl;
	}
};

class Student : public Person {
	string stu_id;
public:
	~Student() {
		cout << "�л��� �Ҹ����Դϴ�." << endl;
	}
	void info() {
		cout << "�л��Դϴ�." << endl;
	}
	void test() {
		cout << "�л��� test �Լ�" << endl;
	}
};

class Instructor : public Person {
public:
	~Instructor() {
		cout << "������ �Ҹ����Դϴ�." << endl;
	}
	void info() {
		cout << "�����Դϴ�." << endl;
	}
};

int main() {
	// ��ĳ����
	Person s = Student(); // ~Person
	s.info(); // ���� ���ε�. ����Դϴ�. ���

	Person* ss = new Student();
	ss->info(); // ���� ���ε� .. �л��Դϴ�. ���
	// ss->test(); // ����. Person�� ���� ������� ������ �� ����.
	delete ss;


	Student stu; // ���� �޸�
	Person* sss = &stu;
	sss->info();
	// delete sss; // delete ����ϰ� �Ǹ� �����߿� ���� �߻�(��Ÿ�� ����)


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