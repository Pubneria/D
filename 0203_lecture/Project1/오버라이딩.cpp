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
		cout << "�������н� \n";
	}
};

class Kim : public Student { // �⺻�� private
	
public:
	Kim (string name, string uni, int age, int num) : Student () {
		this->name = name;
		this->uni = uni;
		this->age = age;
		this->num = num;
	}

	void lunch() {
		cout << "�������谡�ױ�� \n";
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
		cout << "���������������� \n";
	}
};

int main() {

	string name;
	string uni;
	int age;
	int num;
	
	cout << "name : ";
	cin >> name;
	cout << "�б� : ";
	cin >> uni;
	cout << "���� : ";
	cin >> age;
	cout << "�й� : ";
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