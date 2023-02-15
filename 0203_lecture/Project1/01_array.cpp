
#include <iostream>
#include <string>
int main()
{
	int i,j;
	int n1=0, n2=0;
	int sum = 0;
	/*
	std::cout << "x입력: ";
    std::cin >> n1;
	std::cout << "y입력: ";
	std::cin >> n2;
	
	if (n1 <= 0 || n2 <= 0)
	{
		std::cout << "x와 y모두 양수입력해주세요 ";
	}

	int** arr2 = new int* [n1];
	for (i = 0; i < n1; i++)
	{
		arr2[i] = new int[n2];

	}

	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			sum = sum + 1;
			arr2[i][j] = sum;
			std::cout << arr2[i][j];
			std::cout << " ";
		}
		std::cout << "\n";
	}

	for (i = 0; i < n1; i++)
	{
		delete[] arr2[i];
	}
	delete[] arr2;
	*/

	std::cout << "몇명: ";
	std::cin >> n1;
    int* grade = new int[n1];

	for (i = 0; i < n1; i++)
	{

		std::cout << i << "번학생의 성적을 입력하세요: ";
		std::cin >> grade[i];
		sum = sum + grade[i];

	}
	std::cout << "성적평균: " << (double)sum / (double)n1;

	delete grade;


	/*
	std::string city [5];

	city[0] = "한국";
	city[1] = "일본";
	city[2] = "중국";
	city[3] = "미국";
	city[4] = "덴마크";

	for (i = 0; i < 5; i++) 
	{
	
		std::cout << city[i]<<"\n";
	
	}
	for (std::string nat:city)
	{

		std::cout << nat << "\n";

	}


	double grade [5];
	double sum = 0;
	for (i = 0; i < 5; i++)
	{

		std::cout << i << "번학생의 성적을 입력하세요: ";
		std::cin >> grade[i];
		sum = sum + grade[i];
	}
	std::cout << "성적평균: " << sum/5;
	*/

	return 0;

}

