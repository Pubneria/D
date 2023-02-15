#include <iostream>
#include <string>


struct rectangle {
	double width;
	double height;
};


using std::cout;
using std::cin;
using std::endl;
int main() {
	rectangle r;
	r.width;
	r.height;
	cout << "가로길이를 입력하세요: ";
	cin >> r.width;
	cout << "세로길이를 입력하세요: ";
	cin >> r.height;
	cout << "사각형넓이는: " << r.width*r.height;
}