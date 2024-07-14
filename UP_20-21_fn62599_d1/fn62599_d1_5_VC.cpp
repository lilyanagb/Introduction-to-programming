/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 5
* @compiler VC
*
*/

#include <iostream>
using namespace std;


int main() {
	int numerator = 1;
	int denominator;
	int counter = 0;

	do {
		cin >> denominator;
	} while (denominator < 2 || denominator > 1000000000);

	while (counter < 10000000) {
		if (numerator / denominator == 0) {
			numerator *= 10;
			counter++;
			if (numerator % denominator == 0) {
				break;
			}
			else {
				numerator = numerator % denominator;
			}
		}
	}

	if (counter < 10000000) {
		cout << counter << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}