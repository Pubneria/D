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
		for (int i = num-1; i >=0; i--)
		{
			cout << lastnum-i << "\n";
		}

		if (lastnum>= 31) {
			cout << "���� ����! ��ǻ���� �¸��Դϴ�.";
			break;
		}

		cout << "��ǻ�Ͱ� �θ� ����!\n";
		randnum = rand() % 3 + 1;
		lastnum += randnum;

		for (int i = randnum - 1; i >= 0; i--)
		{
			cout << lastnum - i << "\n";
		}
		
		if (lastnum >= 31) {
			cout << "���� ����! ������� �¸��Դϴ�.";
			break;
		}
	}
}