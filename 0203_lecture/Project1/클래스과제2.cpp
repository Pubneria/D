#include <iostream>

using namespace std;

class Character {
	
	string name;
	int level;
	int itemnum;

public:
	Character (string name) {
		this->name = name;
		level = 0;
		itemnum = 0;
	}

	void namechange() {
		cin >> name;	
		return;
	}

	void levelup() {
		level = level + 1;
		return;
	}
	void itemup() {
		itemnum = itemnum + 1;
		return;
	}
	void itemdown() {
		itemnum = itemnum -1;
		return;
	}
	void print() {
		cout << "이름: " << name<<"\n";
		cout << "레벨: " << level << "\n";
		cout << "아이템수: " << itemnum<<"\n";
		return;
	}

};

int main() {
	string name;
	int control = -1;
	std::cout << "캐릭터이름입력: ";
	std::cin >> name;
	Character c(name);

	while (control!=0) {

		std::cout << "조작변수입력: ";
		std::cin >> control;
		if (control == 0)
		{
			break;
		}
		else if (control == 1)
		{
			cout << "변경할이름을 입력 :";
			c.namechange();
		}
		else if (control == 2)
		{
			cout << "레벨업\n";
			c.levelup();
		}
		else if (control == 3)
		{
			cout << "줍줍\n";
			c.itemup();
		}
		else if (control == 4)
		{
			cout << "아이템사용\n";
			c.itemdown();
		
		}
		else if (control == 5)
		{
			cout << "출력:\n";
			c.print();

		}

	}
		return 0;
	
}