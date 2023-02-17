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
		
		

		cout << "다음 단어를 입력하세요: ";
		cin >> nextword;
		clock_t endTime = clock();

		if (((endTime - startTime) / CLOCKS_PER_SEC) >= 30) {
			cout << "타임 오버!\n게임 종료!\n총 입력한 단어 개수 : " << num;
			break;
		}

		else if (pastword[pastword.size() - 1] != nextword[0]) {
			cout << "잘못된 입력입니다\n";
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