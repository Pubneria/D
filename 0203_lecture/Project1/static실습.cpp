#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class snack {
protected:
	int price;
	string name;
	string company;

public:
	virtual void flavorface() {

	}

};

class candy : public snack {
	string flavor;
public:
	candy(string flavor, int price, string name, string company) {
		this->flavor = flavor;
		this->name = name;
		this->price = price;
		this->company = company;
	}
	void flavorface() {
		cout << flavor << name;


	}
};

class chocolate : public snack {
	string face;
public:
	chocolate(string face, int price, string name, string company) {
		this->face = face;
		this->name = name;
		this->price = price;
		this->company = company;
	}
	void flavorface() {
		cout << face << name;


	}
};


int main() {
	int cri=4;
	string f;

	std::vector<snack*> snacks = {};
	while (cri != 0) {
		cout << "과자바구니에들어갈간식을고르시오(1:사탕 2:초콜릿 0:종료): ";
		cin >> cri;
		cout << endl;
		if (cri == 1) {
			cout << "맛을입력하세요: ";
			cin >> f;
			cout << endl;
			snacks.push_back(new candy(f,10,"사탕", "오리온"));
		}
		else if (cri==2){
			cout << "모양을입력하세요: ";
			cin >> f;
			cout << endl;
			snacks.push_back(new chocolate(f, 10, "초콜릿", "오리온"));
		}
		else {}

	}
	int size = snacks.size();
	
	cout << "과자바구니에담긴간식갯수는 " << size << "개입니다\n";

	cout << "과자바구니에 담긴 간식확인하기\n";
		
		
		for (int i = 0; i < size; i++) {
			snacks[i]->flavorface();
			cout << endl;
			
		}
	

	return 0;
}