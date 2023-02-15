#include <iostream>

struct Pos {
	int x;
	int y;
};

class Cat { // �⺻������ ��������
	std::string name;
	std::string jong;
	int age;

public:
	Cat(std::string name, std::string jong) {
		this->name = name;
		this->jong = jong;
	}

	void eat() {
		std::cout << "������ �Դ´�\n";
	}
	void mew() { // �޼ҵ�
		std::cout << "�߿�\n";
	}

	std::string get_name() {
		return name;
	}

	std::string get_jong() {
		return jong;
	}

	int get_age() {
		return age;
	}

	void set_name(std::string name) { // setName
		this->name = name;
	}

	void set_age(int age) {
		this->age = age;
	}

};

// Cat�� �ν��Ͻ� ����
// c�� ��ü
int main() {
	Pos p = { 2,6 };
	p.x = 5;

	Cat c("����", "�丣�þ�"); // c�� ��ü. �� ������ Cat�� ������ �����.

	//Cat c = Cat("����"); // c�� ��ü. �� ������ Cat�� ������ �����.

	//c.age = 5;
	c.set_age(5);
	c.set_name("�ٵ���");

	//std::string name = c.name
	std::string name = c.get_name();

	//std::cout << c.name << " " << c.jong << std::endl;
	std::cout << c.get_name() << " " << c.get_jong() << " " << c.get_age() << std::endl;

	c.mew();
	c.eat();

	return 0;
}