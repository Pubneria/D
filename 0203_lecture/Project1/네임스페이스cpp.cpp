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
	std::cout << "������ȣ�Է�: ";
	std::cin >> seoul::regionnum;
	std::cout << "���帶ũ: ";
	std::cin >> seoul::landmark;

	using busan::regionnum;
	using busan::landmark;
	std::cout << "������ȣ�Է�: ";
	std::cin >> busan::regionnum;
	std::cout << "���帶ũ: ";
	std::cin >> busan::landmark;


	return 0;

}
