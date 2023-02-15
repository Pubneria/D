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
		cout << "º¯ÀÇ°³¼ö: " << num << "\n" << "¹Øº¯±æÀÌ: " << length <<"\n" ;
	}
	~Shape() {
		cout << "¼Ò¸êÀÚ";
	}
};

class Rectangle : public Shape { // ±âº»°ª private
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
		cout << "¼Ò¸êÀÚ";
	}
};

class Triangle : public Shape { // ±âº»°ª private
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
		cout << "¼Ò¸êÀÚ";
	}
};

int main() {

	Rectangle R(8, 4, 5);
	R.printinfo ();
	cout << "³ÐÀÌ: "<<R.area() << "\n";
	Triangle T(4, 3, 5);
	T.printinfo();
	cout << "³ÐÀÌ: " << T.area() << "\n";
	

	return 0;
}