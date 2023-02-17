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

	cout << "숫자는1-25까지만 입력가능합니다\n";

	for (int i = 0; i < 6; i++) {
		
			cout << i+1<<"번째숫자입력하세요\n";
			cin>> user[i];
			temp = 0;
			if (user[i] > 25 || user[i] < 1)
			{
				cout << "범위를벗어난 숫자입니다. 다시입력해주세요\n";
				temp = 1;
			}
			else
			{
				
				for (int j = 0; j < i; j++) {

					if (user[i] == user[j]) {
						cout << "중복된숫자입니다. 다시입력해주세요\n";
						i--;
					
					}
				}
				//cout << temp<<"\n";
				
			}
			
		
	}


	cout << "당첨번호 공개!\n";

	for (int i = 0; i < 6; i++) {
		cout << random[i] << setw(5);
	}
	cout << "\n";
	cout << "1-7등까지 결과가 나올수 있습니다\n";

	for (int i = 0; i < 6; i++) {
		auto it = find(begin(random), end(random), user[i]);
		if (it != end(random)) {
			t++;
		}
	}

	cout << "결과: " << 7 - t << "등입니다!";




	return 0;
}