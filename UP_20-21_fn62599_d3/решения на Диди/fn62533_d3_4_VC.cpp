/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Delyana Raykova
* @idnumber 62533
* @task 4
* @compiler VC
*
*/
#include <iostream>
using namespace std;

const int ONE = 1;
const int HUNDRED = 100;

int getLength(char myString[]) {
	int i = 0;
	for (; myString[i] != '\0'; i++) {}
	return i;
}

unsigned long getUniqueness(char String[], int len) {
	int counterUnique = 1;
	for (int i = 0; i < len-1; i++) {
		for (int j = i+1; j < len; j++) {
			if (String[i] != String[j]) {
				counterUnique++;
				if (j == len - 1) {
					cout << counterUnique << endl;
					return counterUnique;
				}
				break;
			}
		}
	}
	cout << counterUnique << endl;
	return counterUnique;
}

unsigned long getNumber(int mynumber1, int mynumber2) {
	unsigned long factorial = 1;
	int counter = 0;
	for (int i = mynumber1; counter< mynumber2; i--) {
		factorial *= i;
		counter++;
	}
	return factorial;
}

unsigned long getFactorial(int number) {
	if (number == 0) {
		return 1;
	}
	else {
		return number * getFactorial(number - 1);
	}
}

unsigned long getCombinations(int len, int case1) {
	unsigned long divident = getNumber(len, case1);
	unsigned long divisor = getFactorial(case1);
	unsigned long combination = divident / divisor;
	return combination;
}

unsigned long getNumberOfStrings(char MainString[], int capacity, int unique, int omitCounter) {
	unsigned long lostPoss = 0;
	if (omitCounter == 0) {
		return lostPoss;
	}
	else {

		return lostPoss;
	}
}

unsigned long getPossibleString(char Str[]) {
	int length = getLength(Str);
	int uniqueness = getUniqueness(Str, length);
	unsigned long possibilities = 0;
	for (int i = 1; i <= length; i++) {
		possibilities += getCombinations(length, i);
	}
	if (uniqueness == length) {
		return possibilities;
	}
	else if(uniqueness==ONE){
		return length;
	}
	else {
		unsigned long allLostCombinations = 0;
		for (int i = 0; i < length; i++) {
			allLostCombinations+=getNumberOfStrings(Str, length, uniqueness,i);
			cout << allLostCombinations;
		}
		return possibilities - allLostCombinations;
	}
}

int main() {
	char String[HUNDRED];
	cin >> String;
	cout << getPossibleString(String) << endl;
	return 0;
}