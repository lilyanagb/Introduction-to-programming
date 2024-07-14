/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Georgieva Belcheva
* @idnumber 62599
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int countOfNumbers = 0;
	cin >> countOfNumbers;

	while (countOfNumbers < 3 || countOfNumbers > 100) {
		cin >> countOfNumbers;
	}

	bool isTrue = true;
	int arr[100];

	for (int i = 0; i < countOfNumbers; ++i) {
		cin >> arr[i];
	}

	int startElement = 0;
	int endElement = 0;

	if (countOfNumbers % 2 == 0) {
		for (int i = 0; i < countOfNumbers / 2 - 1; i++) {
			startElement = abs(arr[i] - arr[i + 1]);
			endElement = abs(arr[countOfNumbers - i - 1] - arr[countOfNumbers - i - 2]);

			if (startElement == endElement) {
				isTrue = true;
			}
			else {
				isTrue = false;
			}
		}
	}
	if (countOfNumbers % 2 != 0) {
		for (int i = 0; i < countOfNumbers / 2; ++i) {
			startElement = abs(arr[i] - arr[i + 1]);
			endElement = abs(arr[countOfNumbers - i - 1] - arr[countOfNumbers - i - 2]);

			if (startElement == endElement) {
				isTrue = true;
			}
			else {
				isTrue = false;
			}
		}
	}

	if (isTrue) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}
