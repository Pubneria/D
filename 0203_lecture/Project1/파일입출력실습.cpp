#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
// input file stream -> ifstream
// ouput file stream -> ofstream

bool checkFileOpen(std::ifstream& file) {
	if (file.fail()) {
		cout << "파일 없음" << endl;
		return false;
	}
	else return true;
}

int main() {
	/*
	std::string name [3];
	std::string password [3];

	cout << "3명회원에 대한 이름 비밀번호를 순차적으로 입력하세요" << endl;
	cout << "1번째회원: ";
	cin  >> name[0];
	cin >> password[0];
	cout << endl;
	cout << "2번째회원: ";
	cin >> name[1];
	cin >> password[1];
	cout << endl;
	cout << "3번째회원: ";
	cin >> name[2];
	cin >> password[2];
	cout << endl;
	cout << "-----회원명부파일읽기-------" << endl;

	std::ofstream file("member.txt");
	if (file.fail()) {
		cout << "파일 없음" << endl;
		return -1;
	}
	file << name[0] <<" " << password[0] << endl;
	file << name[1] << " " << password[1] << endl;
	file << name[2] << " " << password[2] << endl;

	std::ifstream file_r("member.txt");
	if (!checkFileOpen(file_r)) return -1;

	std::string line, file_content = "";
	while (std::getline(file_r, line)) {
		// file_content = file_content + line + "\n";
		file_content += line + "\n";
	}
	cout << file_content;



	file.close();
	*/


	std::string name, password,telnum;
	int record = 0;
	cout << "이름을입력하세요: " << endl;
	cin >> name;
	cout << "비밀번호를입력하세요: " << endl;
	cin >> password;

	std::string log;
	log = name + " " + password;

	std::ifstream file_r("member.txt");
	if (!checkFileOpen(file_r)) {
		return -1;
	}

	std::string line,str,str2, file_content = "";
	int position;
	while (std::getline(file_r, line)) {


		if (line == log) {
			cout << "로그인 성공" << endl;
			cout << "전화번호를입력해주세요: " << endl;
			cin >> telnum;

		    //중복이름있는지 검사
			std::ifstream file1("member_tel.txt");
			if (!checkFileOpen(file1)) {
				return -1;
			}
			int i = 0;
		
			while (file1 >> str >> str2) {

				cout << str << " " << str2;
				if (str == name)
				{
					record = 1;
					position = i;
				}
				else {
					record = 0;
				}
				i++;
			}
			
			std::ofstream file;
			file.open("member_tel.txt", std::ios::app);
			if (file.fail()) {
				cout << "파일 없음" << endl;
				return -1;
			}
			if (record == 0) {
               file << name << " " << telnum << endl;
			}
			else {


			}

			break;
		}
	}
	
	
	
	if (line != log) {
		cout << "로그인 실패" << endl;
	}
	

	
	return 0;
}
	