#include <iostream>
#include <cstdlib>
#include<iomanip>
#include <vector>

using namespace std;


int main() {
	srand(time(NULL));
	const int length = 3;
	const int maxint = 9;
	const int minint = 1;
	int* random = new int[length];
	int* user = new int[length];
	int temp=0;
	int t = 0,s= 0,b= 0;


	for (int i = 0; i < length; i++) {
		random[i]= rand() % maxint + 1;
		for (int j = 0; j < i; j++) {
			if (random[j] == random[i]) {
				i--;
			}
		}
	}


	cout << "�߱�����\n";
	
	while (1) {
		t = 0;
		s = 0;
		b = 0;
		cout << "1-9������ ���� 3���� �Է��ϼ���(�̿��� ����: ����)\n";
		for (int i = 0; i < length; i++) {
			cin >> user[i];
			if (user[i] > maxint || user[i] < minint)
			{t = 1;
			}
			
			auto it = find(random, random + length, user[i]);
			if ((it - random) == i) {
				s++;
			}
			else if (it < random + length)
			{
				b++;
			}
			

		}

		if (t == 1)
		break;

		temp++;

		if (s < length) {
			cout << "Strike: " << s << setw(10) << "Ball: " << b << " \n";
		}
		else {
			cout << temp<<"������ ���� \n";
			break;
		}


	}



	return 0;
}