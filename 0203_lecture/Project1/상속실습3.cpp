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
	string get_name() {
		return name;
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
};


int main() {

	snack snackbasket[4] = { candy("�����", 30, "ĵ��","������"), candy("�����", 20, "ĳ�־ص�","���"), chocolate("��Ʈ", 10, "�ɲ�","�䷹��"), chocolate("�ظ�", 50, "����","�ν�") };
	for (int i = 0; i < 4; i++) {
		cout << snackbasket[i].get_name() << endl;
	}

	return 0;
}