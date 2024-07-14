/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Delyana Raykova
* @idnumber 62533
* @task 1
* @compiler VC
*
*/
#include <iostream>
using namespace std;

const int MAX_SIZE = 2000;

bool isIncreasing(int changes, int sizeOfArray, int Arr[]) {
	int counter = 0;
	for (int i = 0; i < sizeOfArray-1; i++) {
		if (Arr[i] <= Arr[i + 1]) {
			continue;
		}
		else {
			counter++;
		}
		if (counter > changes) {
			break;
		}
	}
	if (counter <= changes) {
		return true;
	}
	return false;
}

int main() {
	int changes = 0;
	int sizeOfArray = 0;
	int Array[MAX_SIZE];
	cin >> changes >> sizeOfArray;
	for (int i = 0; i < sizeOfArray; i++) {
		cin >> Array[i];
	}
	if (isIncreasing(changes, sizeOfArray,Array)) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}