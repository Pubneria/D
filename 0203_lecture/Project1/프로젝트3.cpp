#include <iostream>
#include <cstdlib>
#include<iomanip>
using namespace std;
int main() {
	srand(time(NULL));

	int random[6];
	int user[6];
	int temp;
	int t = 0;


	for (int i = 0; i < 6; i++) {
		random[i]= rand() % 25 + 1;
		for (int j = 0; j < i; j++) {
			if (random[j] == random[i]) {
				i--;
			}
		}
	}

	cout << "���ڴ�1-25������ �Է°����մϴ�\n";

	for (int i = 0; i < 6; i++) {
		
			cout << i+1<<"��°�����Է��ϼ���\n";
			cin>> user[i];
			temp = 0;
			if (user[i] > 25 || user[i] < 1)
			{
				cout << "��������� �����Դϴ�. �ٽ��Է����ּ���\n";
				temp = 1;
			}
			else
			{
				
				for (int j = 0; j < i; j++) {

					if (user[i] == user[j]) {
						cout << "�ߺ��ȼ����Դϴ�. �ٽ��Է����ּ���\n";
						i--;
					
					}
				}
				//cout << temp<<"\n";
				
			}
			
		
	}


	cout << "��÷��ȣ ����!\n";

	for (int i = 0; i < 6; i++) {
		cout << random[i] << setw(5);
	}
	cout << "\n";
	cout << "1-7����� ����� ���ü� �ֽ��ϴ�\n";

	for (int i = 0; i < 6; i++) {
		auto it = find(begin(random), end(random), user[i]);
		if (it != end(random)) {
			t++;
		}
	}

	cout << "���: " << 7 - t << "���Դϴ�!";




	return 0;
}