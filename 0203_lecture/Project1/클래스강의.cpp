#include <iostream>

struct Pos {
	int x;
	int y;
};

class Cat { // 기본적으로 정보은닉
	std::string name;
	std::string jong;
	int age;

public:
	Cat(std::string name, std::string jong) {
		this->name = name;
		this->jong = jong;
	}

	void eat() {
		std::cout << "생선을 먹는다\n";
	}
	void mew() { // 메소드
		std::cout << "야옹\n";
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

// Cat의 인스턴스 만듦
// c은 객체
int main() {
	Pos p = { 2,6 };
	p.x = 5;

	Cat c("나비", "페르시안"); // c는 객체. 이 순간에 Cat의 생성자 실행됨.

	//Cat c = Cat("나비"); // c는 객체. 이 순간에 Cat의 생성자 실행됨.

	//c.age = 5;
	c.set_age(5);
	c.set_name("바둑이");

	//std::string name = c.name
	std::string name = c.get_name();

	//std::cout << c.name << " " << c.jong << std::endl;
	std::cout << c.get_name() << " " << c.get_jong() << " " << c.get_age() << std::endl;

	c.mew();
	c.eat();

	return 0;
}