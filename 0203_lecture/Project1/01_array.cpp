
#include <iostream>
#include <string>
int main()
{
	int i,j;
	int n1=0, n2=0;
	int sum = 0;
	/*
	std::cout << "x�Է�: ";
    std::cin >> n1;
	std::cout << "y�Է�: ";
	std::cin >> n2;
	
	if (n1 <= 0 || n2 <= 0)
	{
		std::cout << "x�� y��� ����Է����ּ��� ";
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

	std::cout << "���: ";
	std::cin >> n1;
    int* grade = new int[n1];

	for (i = 0; i < n1; i++)
	{

		std::cout << i << "���л��� ������ �Է��ϼ���: ";
		std::cin >> grade[i];
		sum = sum + grade[i];

	}
	std::cout << "�������: " << (double)sum / (double)n1;

	delete grade;


	/*
	std::string city [5];

	city[0] = "�ѱ�";
	city[1] = "�Ϻ�";
	city[2] = "�߱�";
	city[3] = "�̱�";
	city[4] = "����ũ";

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

		std::cout << i << "���л��� ������ �Է��ϼ���: ";
		std::cin >> grade[i];
		sum = sum + grade[i];
	}
	std::cout << "�������: " << sum/5;
	*/

	return 0;

}

