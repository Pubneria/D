#include <iostream>


class Rectangle { 

	double width;
	double height;
public:
	Rectangle (double width, double height) {
		this->width = width;
		this->height = height;
	}

	 double area() {
		
		return width * height;
	}

};

int main() {
	double width = 0, height = 0;
	std::cout << "width, height �Է�: ";
	std::cin >> width >> height;
	Rectangle A(width, height);
	std::cout << "����: " << A.area();

	return 0;
}