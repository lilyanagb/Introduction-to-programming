/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Delyana Raykova
* @idnumber 62533
* @task 2
* @compiler VC
*
*/
#include <iostream>
using namespace std;

const int MAXSIZE = 150;
const int LOWER_A = 96;
const int LOWER_Z = 123;

int getLength(char Arr[]) {
	int i = 0;
	for (; Arr[i] != '\0'; i++) {}
	return i;
}

bool checkLowercaseLetters(char Array[], int length) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (int(Array[i]) > LOWER_A && int(Array[i]) < LOWER_Z) {
			continue;
		}
		else {
			counter++;
			break;
		}
	}
	if (counter == 0) {
		return true;
	}
	else {
		return false;
	}
}

int compareLength(char Array1[], char Array2[], char Array3[], int len1, int len2, int len3) {
	if (len1 + len2 != len3) {
		return 0;
	}
	else {
		return 1;
	}
}

int checkForSameLetters(char Str1[], char Str2[], char Str3[], int strLen1, int strLen2, int strLen3) {
	int counter = 0;
	for (int i = 0; i < strLen1; i++) {
		for (int j = 0; j < strLen1; j++) {
			if (Str1[i] == Str3[j]) {
				counter++;
				break;
			}
		}
	}
	if (counter != strLen1) {
		return 0;
	}
	for (int i = 0; i < strLen2; i++) {
		for (int j = strLen1; j < strLen3; j++) {
			if (Str2[i] == Str3[j]) {
				counter++;
				break;
			}
		}
	}
	if (counter == strLen3) {
		return 1;
	}
}

int checkThirdArray(char One[], char Two[], char Three[], int oneLength, int twoLength, int threeLength) {
	if (compareLength(One, Two, Three, oneLength, twoLength, threeLength) == 0) {
		return 0;
	}
	else {
		if ((checkForSameLetters(One, Two, Three, oneLength, twoLength, threeLength)==1) || 
			(checkForSameLetters(Two,One,Three,twoLength,oneLength,threeLength)==1)) {
			return 1;
		}
	}
}

int main() {
	char First[MAXSIZE], Second[MAXSIZE],Third[MAXSIZE];
	cin >> First>>Second>>Third;
	int length1 = getLength(First);
	int length2 = getLength(Second);
	int length3 = getLength(Third);
	if (checkLowercaseLetters(First,length1) == 0 || checkLowercaseLetters(Second,length2) == 0 || 
		checkLowercaseLetters(Third,length3) == 0) {
		cout<< - 1;
	}
	else {
		if (checkThirdArray(First, Second, Third, length1, length2, length3) == 1) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	return 0;
}