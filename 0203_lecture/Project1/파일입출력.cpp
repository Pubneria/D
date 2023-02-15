#include <iostream>
#include <string>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
int main()
{
	ifstream file;
	file.open("test.txt");

	// file.fail() // 파일 여는 것에 실패하면 true. 성공하면 
	if (file.fail()) {
		cout << "파일 없음" << endl;
		return -1;
	}

	cout << "아무글자";

	std::string str, str2, line;
	// file >> str >> str2; // 파일 안 내용을 str에 저장. 공백(띄어쓰기, 엔터) 전까지 읽어옴.

	
	while (file >> str>>str2) {
		cout << str << " "<<str2;
		cout << std::endl;
	}
	

	// std::getline(file, line); // file의 내용을 한 줄씩 읽어서 line에 저장 (\n 기준)
	/*int i = 1;
	while (std::getline(file, line)) {
		if (i == 2) cout << line << endl;
		i++;
	}
	*/
	file.close(); // file 닫기


	


	return 0;

}
