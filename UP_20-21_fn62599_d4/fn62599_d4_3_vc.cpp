/**
*
* Solution to homework assignment 4
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

void reduceFraction(int* arr) {
	int newDenominator = 0, newNumerator = 0;
	newNumerator = arr[0];
	newDenominator = arr[1];

	if (newNumerator < 0) {
		for (int i = -1*newDenominator * newNumerator; i > 1; i--) {
			if ((newDenominator % i == 0) && (newNumerator % i == 0)) {
				newDenominator /= i;
				newNumerator /= i;
			}
		}
	}
	else {
		for (int i = newDenominator * newNumerator; i > 1; i--) {
			if ((newDenominator % i == 0) && (newNumerator % i == 0)) {
				newDenominator /= i;
				newNumerator /= i;
			}
		}
	}
	if (newNumerator == 0) {
		newDenominator = 1;
	}
	arr[0] = newNumerator;
	arr[1] = newDenominator;
}

int* arithmeticOperation(int numeratorFirstNum, int denominatorFirstNum, int numeratorSecondNum, int denominatorSecondNum, char operation) {
	int* newFraction = new(nothrow) int[2];

	if (newFraction == nullptr) {
		return nullptr;
	}

	int newNumerator = 0, newDenominator = 0;
	if (operation == '+') {
		newNumerator = (numeratorFirstNum * denominatorSecondNum) + (numeratorSecondNum * denominatorFirstNum);
		newDenominator = denominatorFirstNum * denominatorSecondNum;
		newFraction[0] = newNumerator;
		newFraction[1] = newDenominator;
		reduceFraction(newFraction);
		return newFraction;
	}

	if (operation == '-') {
		newNumerator = (numeratorFirstNum * denominatorSecondNum) - (numeratorSecondNum * denominatorFirstNum);
		newDenominator = denominatorFirstNum * denominatorSecondNum;
		newFraction[0] = newNumerator;
		newFraction[1] = newDenominator;
		reduceFraction(newFraction);
		return newFraction;
	}

	if (operation == '*') {
		newNumerator = numeratorFirstNum * numeratorSecondNum;
		newDenominator = denominatorFirstNum * denominatorSecondNum;
		newFraction[0] = newNumerator;
		newFraction[1] = newDenominator;
		reduceFraction(newFraction);
		return newFraction;
	}

	if (operation == '/') {
		newNumerator = numeratorFirstNum * denominatorSecondNum;
		newDenominator = numeratorSecondNum * denominatorFirstNum;
		if (newDenominator == 0) {
			return nullptr;
		}

		newFraction[0] = newNumerator;
		newFraction[1] = newDenominator;
		reduceFraction(newFraction);
		return newFraction;
	}
	delete[] newFraction;
	return nullptr;
}

int main() {
	int numeratorFirstNum, denominatorFirstNum;
	char operation;
	int numeratorSecondNum, denominatorSecondNum;
	cin >> numeratorFirstNum >> denominatorFirstNum >> operation >> numeratorSecondNum >> denominatorSecondNum;

	if (denominatorFirstNum == 0 || denominatorSecondNum == 0) {
		cout << -1;
		return 0;
	}
	
	int* arr = arithmeticOperation(numeratorFirstNum, denominatorFirstNum, numeratorSecondNum, denominatorSecondNum, operation);

	if (arr == nullptr) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < 2; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;

	return 0;
}