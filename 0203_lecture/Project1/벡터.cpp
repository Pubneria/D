#include <iostream>
#include <string>
#include <vector>

int main()
{
	int i, j;
	int n1 = 0, n2 = 0;
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

	std::vector<std::vector<int>> v2;
	v2.assign(n1, std::vector<int>(n2, 1)); //3x2행렬(1로초기화)

	for (int i = 0; i < v2.size(); i++) {
		for (int j = 0; j < v2.at(i).size(); j++)
		{
			sum = sum + 1;
			v2.at(i).at(j) = sum;
			std::cout << v2.at(i).at(j)<< " ";
			//std::cout << v2[i][j]; << " ";
		}

		std::cout << "\n";
	}
	*/

	
	std::vector<int> v;
	int dummy = 1;
	while(dummy!=0)	{
		
		std::cout << "숫자를입력하세요: ";
		std::cin >> dummy;
		v.insert(v.begin() +n1, dummy);
		n1 += 1;
		sum += dummy;
	}

	std::cout << "합: " << sum;




	return 0;

}
