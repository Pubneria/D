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
	cout << "���α��̸� �Է��ϼ���: ";
	cin >> r.width;
	cout << "���α��̸� �Է��ϼ���: ";
	cin >> r.height;
	cout << "�簢�����̴�: " << r.width*r.height;
}