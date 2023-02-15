#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//private > protected > public
class Shape {
protected:
	int num;
	double length;

public:
	Shape () {

	}
	void printinfo () {
		cout << "���ǰ���: " << num << "\n" << "�غ�����: " << length <<"\n" ;
	}
	~Shape() {
		cout << "�Ҹ���";
	}
};

class Rectangle : public Shape { // �⺻�� private
	double height;
public:
	Rectangle(double height,int num, double length) : Shape() {
		this->height = height;
		this->num = num;
		this->length = length;
	}
	
	double area() {
		return height* length;
     }
	~Rectangle() {
		cout << "�Ҹ���";
	}
};

class Triangle : public Shape { // �⺻�� private
	double height;
public:
	Triangle(double height, int num, double length) : Shape() {
		this->height = height;
		this->num = num;
		this->length = length;
	}

	double area() {
		return height * length*0.5;
	}
	~Triangle() {
		cout << "�Ҹ���";
	}
};

int main() {

	Rectangle R(8, 4, 5);
	R.printinfo ();
	cout << "����: "<<R.area() << "\n";
	Triangle T(4, 3, 5);
	T.printinfo();
	cout << "����: " << T.area() << "\n";
	

	return 0;
}