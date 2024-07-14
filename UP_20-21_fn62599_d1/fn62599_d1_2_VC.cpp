/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 2
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int main() {
	int number;
	int counter = 0;
	int largestNumber = -1;
	int secondLargestNumber = -1;

	do {
		cin >> number;
		counter++;

		if (number > largestNumber) {
			secondLargestNumber = largestNumber;
			largestNumber = number;
		}
		else if (number > secondLargestNumber)
		{
			secondLargestNumber = number;
		}
	} while (number > 0);

	if (counter < 2) {
		cout << "error";
	}
	else {
		cout << secondLargestNumber;
	}

	return 0;
}