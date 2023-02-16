#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int lastnum = 0;
	int num, randnum;
	srand(time(NULL));

	while (1) {
		cout << "개수를입력하세요: ";
		cin >> num;
		while (num < 0 || num > 3) {
			cout << "1~3사이의수를입력하세요.";
			cin >> num;
		}
		lastnum += num;
	
		
	    cout << "사용자가부른숫자!\n";
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
			cout << "게임 종료! 컴퓨터의 승리입니다.";
			break;
		}


		cout << "컴퓨터가 부른 숫자!\n";
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
			cout << "게임 종료! 사용자의 승리입니다.";
			break;
		}
	}
}