#include<iostream>
#include<ctime>
#include<string>
using namespace std;

int main() {
	clock_t startTime = clock();
	string pastword, nextword, line;
	int num = 0;
	pastword = "airplane";
	line = "airplane";
	cout << "airplane\n";
	
	while (1) {
		
		

		cout << "���� �ܾ �Է��ϼ���: ";
		cin >> nextword;
		clock_t endTime = clock();

		if (((endTime - startTime) / CLOCKS_PER_SEC) >= 30) {
			cout << "Ÿ�� ����!\n���� ����!\n�� �Է��� �ܾ� ���� : " << num;
			break;
		}

		else if (pastword[pastword.size() - 1] != nextword[0]) {
			cout << "�߸��� �Է��Դϴ�\n";
		}
		else {
			line = line + "->" + nextword;
			cout << line<<"\n";
			pastword = nextword;
			num++;
		}
		cout << "\n";
	}


}