/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 3
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int main() {
	int firstNumber, secondNumber, thirdNumber;
	cin >> firstNumber >> secondNumber >> thirdNumber;

	int maxNum = 0, middleNum = 0, minNum = 0;

	if (firstNumber > secondNumber && firstNumber > thirdNumber) {
		maxNum = firstNumber;

		if (secondNumber > thirdNumber) {
			middleNum = secondNumber;
			minNum = thirdNumber;
		}
		else if (thirdNumber > secondNumber) {
			middleNum = thirdNumber;
			minNum = secondNumber;
		}
	}
	else if (secondNumber > firstNumber && secondNumber > thirdNumber) {
		maxNum = secondNumber;

		if (firstNumber > thirdNumber) {
			middleNum = firstNumber;
			minNum = thirdNumber;
		}
		else if (thirdNumber > firstNumber) {
			middleNum = thirdNumber;
			minNum = firstNumber;
		}
	}
	else if (thirdNumber > firstNumber && thirdNumber > secondNumber) {
		maxNum = thirdNumber;

		if (secondNumber > firstNumber) {
			middleNum = secondNumber;
			minNum = firstNumber;
		}
		else if (firstNumber > secondNumber) {
			middleNum = firstNumber;
			minNum = secondNumber;
		}
	}

	if (firstNumber == 0 && secondNumber == 0 && thirdNumber == 0) {
		cout << firstNumber;
	}
	else if (firstNumber == 0 && secondNumber == 0) {
		cout << thirdNumber << firstNumber << firstNumber << thirdNumber;
	}
	else if (firstNumber == 0 && thirdNumber == 0) {
		cout << secondNumber << firstNumber << firstNumber << secondNumber;
	}
	else if (secondNumber == 0 && thirdNumber == 0) {
		cout << firstNumber << secondNumber << secondNumber << firstNumber;
	}
	else if (firstNumber > secondNumber && thirdNumber == 0) {
		cout << secondNumber << thirdNumber << firstNumber << thirdNumber << secondNumber;
	}
	else if (firstNumber > thirdNumber && secondNumber == 0) {
		cout << thirdNumber << secondNumber << firstNumber << secondNumber << thirdNumber;
	}
	else if (secondNumber > thirdNumber && firstNumber == 0) {
		cout << thirdNumber << firstNumber << secondNumber << firstNumber << thirdNumber;
	}
	else if (secondNumber > firstNumber && thirdNumber == 0) {
		cout << firstNumber << thirdNumber << secondNumber << thirdNumber << firstNumber;
	}
	else if (thirdNumber > secondNumber && firstNumber == 0) {
		cout << secondNumber << firstNumber << thirdNumber << firstNumber << secondNumber;
	}
	else if (thirdNumber > firstNumber && secondNumber == 0) {
		cout << firstNumber << secondNumber << thirdNumber << secondNumber << firstNumber;
	}
	else if (firstNumber == secondNumber && secondNumber == thirdNumber) {
		cout << firstNumber << secondNumber << thirdNumber;
	}
	else if (firstNumber == secondNumber) {
		cout << firstNumber << thirdNumber << secondNumber;
	}
	else if (firstNumber == thirdNumber) {
		cout << firstNumber << secondNumber << thirdNumber;
	}
	else if (secondNumber == thirdNumber) {
		cout << secondNumber << firstNumber << thirdNumber;
	}
	else {
		cout << minNum << middleNum << maxNum << middleNum << minNum;
	}

	return 0;
}