#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Shape {
protected:
public:
	virtual void draw() = 0;
	
};

class Circle : public Shape {

public:
	void draw() {
		cout << "Circle\n";

	}
};
class Rect : public Shape {

public:
	void draw() {
		cout << "Rectangle\n";

	}
};
class Tria : public Shape {

public:
	void draw() {
		cout << "Triangle\n";

	}
};


int main() {
	
	Circle c;
	Rect r;
	Tria t;
	c.draw();
	r.draw();
	t.draw();
	return 0;
}