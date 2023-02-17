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
		for (int i = num-1; i >=0; i--)
		{
			cout << lastnum-i << "\n";
		}

		if (lastnum>= 31) {
			cout << "게임 종료! 컴퓨터의 승리입니다.";
			break;
		}

		cout << "컴퓨터가 부른 숫자!\n";
		randnum = rand() % 3 + 1;
		lastnum += randnum;

		for (int i = randnum - 1; i >= 0; i--)
		{
			cout << lastnum - i << "\n";
		}
		
		if (lastnum >= 31) {
			cout << "게임 종료! 사용자의 승리입니다.";
			break;
		}
	}
}