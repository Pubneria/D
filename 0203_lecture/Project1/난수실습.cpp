#include <iostream>
#include <cstdlib>
using std::cout;
int main() {
	srand(time(NULL));

	int random[6];

	int temp;
	int j;


	for (int i = 0; i < 6; i++) {

		while (1) {
			random[i] = rand() % 45 + 1;
			temp = 0;
			for (int j = 0; j < i - 1; j++) {
			
				if (random[i]== random[j]) {
					temp = 1;
					break;
			  }
			}

			if (temp == 0){}
				break;


		}
	
		
	}
	for (int i = 0; i < 6; i++) {
		cout << random[i] <<"\n";

	}
	return 0;
}