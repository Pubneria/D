#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int lastnum = 0;
	int num, randnum;
	srand(time(NULL));

	while (1) {
		cout << "�������Է��ϼ���: ";
		cin >> num;
		while (num < 0 || num > 3) {
			cout << "1~3�����Ǽ����Է��ϼ���.";
			cin >> num;
		}
		lastnum += num;
	
		
	    cout << "����ڰ��θ�����!\n";
	    if (num == 1) 
		{
		cout << lastnum <<"\n";
		}
		else if (num == 2) {
		cout << lastnum - 1 << "\n" << lastnum << "\n";
		}
		else {
		cout << lastnum - 2 << "\n" << lastnum - 1 << "\n" << lastnum << "\n";
		}

		if (lastnum>= 31) {
			cout << "���� ����! ��ǻ���� �¸��Դϴ�.";
			break;
		}


		cout << "��ǻ�Ͱ� �θ� ����!\n";
		randnum = rand() % 3 + 1;
		lastnum += randnum;
		if (randnum == 1) {
			cout << lastnum << endl;
		}
		else if (randnum == 2) {
			cout << lastnum - 1 << endl << lastnum << endl;
		}
		else {
			cout << lastnum - 2 << endl << lastnum - 1 << endl << lastnum << endl;
		}
		if (lastnum >= 31) {
			cout << "���� ����! ������� �¸��Դϴ�.";
			break;
		}
	}
}