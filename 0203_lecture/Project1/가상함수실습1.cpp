#include <iostream>

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
		cout << face<< name;


	}
};


int main() {

	snack* snackbasket[4] = { new candy("�����", 30, "ĵ��","������"), new candy("�����", 20, "ĵ��","���"), new chocolate("��Ʈ���", 10, "�ɲ�","�䷹��"), new chocolate("�ظ����", 50, "����","�ν�") };
	for (int i = 0; i < 4; i++) {
	snackbasket[i]->flavorface();
	cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		delete snackbasket[i];
	}
	return 0;
}