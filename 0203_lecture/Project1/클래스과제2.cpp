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
		cout << "�̸�: " << name<<"\n";
		cout << "����: " << level << "\n";
		cout << "�����ۼ�: " << itemnum<<"\n";
		return;
	}

};

int main() {
	string name;
	int control = -1;
	std::cout << "ĳ�����̸��Է�: ";
	std::cin >> name;
	Character c(name);

	while (control!=0) {

		std::cout << "���ۺ����Է�: ";
		std::cin >> control;
		if (control == 0)
		{
			break;
		}
		else if (control == 1)
		{
			cout << "�������̸��� �Է� :";
			c.namechange();
		}
		else if (control == 2)
		{
			cout << "������\n";
			c.levelup();
		}
		else if (control == 3)
		{
			cout << "����\n";
			c.itemup();
		}
		else if (control == 4)
		{
			cout << "�����ۻ��\n";
			c.itemdown();
		
		}
		else if (control == 5)
		{
			cout << "���:\n";
			c.print();

		}

	}
		return 0;
	
}