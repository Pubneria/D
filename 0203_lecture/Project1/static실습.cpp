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
		cout << "���ڹٱ��Ͽ������������ÿ�(1:���� 2:���ݸ� 0:����): ";
		cin >> cri;
		cout << endl;
		if (cri == 1) {
			cout << "�����Է��ϼ���: ";
			cin >> f;
			cout << endl;
			snacks.push_back(new candy(f,10,"����", "������"));
		}
		else if (cri==2){
			cout << "������Է��ϼ���: ";
			cin >> f;
			cout << endl;
			snacks.push_back(new chocolate(f, 10, "���ݸ�", "������"));
		}
		else {}

	}
	int size = snacks.size();
	
	cout << "���ڹٱ��Ͽ���䰣�İ����� " << size << "���Դϴ�\n";

	cout << "���ڹٱ��Ͽ� ��� ����Ȯ���ϱ�\n";
		
		
		for (int i = 0; i < size; i++) {
			snacks[i]->flavorface();
			cout << endl;
			
		}
	

	return 0;
}