#include <iostream>
#include <cstdlib>
#include<iomanip>
#include <vector>

using namespace std;




int main() {
	srand(time(NULL));
	int length = 3;
	int* random = new int[length];
	int* user = new int[length];
	int temp=0;
	int t = 0,s= 0,b= 0;


	for (int i = 0; i < length; i++) {
		random[i]= rand() % 9 + 1;
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
			if (user[i] > 9 || user[i] < 1)
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
			/*cout << "����!\n";

			for (int i = 0; i < length; i++) {
				cout << random[i] << setw(5);
			}
			cout << "\n";
			*/
			break;
		}


	}



	return 0;
}