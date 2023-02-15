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

	snack* snackbasket[4] = { new candy("µþ±â¸À", 30, "Äµµð","¿À¸®¿Â"), new candy("»ç°ú¸À", 20, "Äµµð","³ó½É"), new chocolate("ÇÏÆ®¸ð¾ç", 10, "ÂÉ²¿","Æä·¹·Î"), new chocolate("ÇØ¸¶¸ð¾ç", 50, "ÃÊÄÚ","·Î½¦") };
	for (int i = 0; i < 4; i++) {
	snackbasket[i]->flavorface();
	cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		delete snackbasket[i];
	}
	return 0;
}