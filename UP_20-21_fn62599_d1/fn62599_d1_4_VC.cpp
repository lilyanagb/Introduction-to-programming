/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 4
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int main() {
	unsigned int consoleNumber;

	do {
		cin >> consoleNumber;
	} while (consoleNumber < 1 || consoleNumber > 1000000000);

	int firstDivisor = 0, secondDivisor = 0, thirdDivisor = 0;
	int firstSum = 0, secondSum = -1;
	int newFirst = 0, newSecond = 0, newThird = 0;


	for (int i = 1; i <= consoleNumber; i++) {

		if (consoleNumber % i != 0) {
			continue;
		}
		for (int j = 1; j <= consoleNumber; j++) {

			if (consoleNumber % j != 0) {
				continue;
			}
			for (int k = 1; k <= consoleNumber; k++) {

				if (consoleNumber % k != 0) {
					continue;
				}

				if ((i * j * k) == consoleNumber) {
					firstDivisor = i;
					secondDivisor = j;
					thirdDivisor = k;

					firstSum = firstDivisor + secondDivisor + thirdDivisor;

					if (secondSum == -1) {
						secondSum = firstSum;
					}

					if (secondSum >= firstSum) {
						secondSum = firstSum;
						firstSum = 0;

						newFirst = thirdDivisor;
						newSecond = secondDivisor;
						newThird = firstDivisor;
					}
				}
			}
		}
	}
	cout << newFirst << " " << newSecond << " " << newThird << endl;

	return 0;
}