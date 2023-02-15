#include <iostream>
#include <string>


namespace seoul
{
	int regionnum;
	std::string landmark;
}

namespace busan
{
	int regionnum;
	std::string landmark;
}


int main()
{
	using namespace seoul;
	std::cout << "지역번호입력: ";
	std::cin >> seoul::regionnum;
	std::cout << "랜드마크: ";
	std::cin >> seoul::landmark;

	using busan::regionnum;
	using busan::landmark;
	std::cout << "지역번호입력: ";
	std::cin >> busan::regionnum;
	std::cout << "랜드마크: ";
	std::cin >> busan::landmark;


	return 0;

}
