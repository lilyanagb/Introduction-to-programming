/**
*
* Solution to homework assignment 3
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

int strlength(char str[]) {
	int i = 0;
	for (; str[i] != '\0'; ++i) {}
	return i;
}

bool validateStr(char str[]) {
	for (int i = 0; i < strlength(str); ++i) {
		if (str[i] < 'a' || str[i] > 'z') {
			return false;
		}
	}
	return true;
}

bool compareStr(char first[], char second[]) {
	int length = strlength(first);
	bool isHere = true;

	for (int i = 0; i < length; i++) {
		if (first[i] != second[i]) {
			isHere = false;
		}
	}
	if (isHere) {
		return true;
	}
	return false;
}

void sortElements(char first[]) {
	int swapElement;
	int length = strlength(first);
	for (int i = 0; i < length; i++) {
		for (int j = length - 1; j > i; j--) {
			if (first[j - 1] > first[j]) {
				swapElement = first[j - 1];
				first[j - 1] = first[j];
				first[j] = swapElement;
			}
		}
	}
}

void newStr(int start, int stop, char newStr[], char str3[]) {
	int element = 0;
	for (int j = start; j < stop; j++) {
		newStr[element] = str3[j];
		element++;
	}
	newStr[element] = '\0';
}

int main() {
	char str1[150];
	char str2[150];
	char str3[150];

	cin >> str1 >> str2 >> str3;
	if (!(validateStr(str1) && validateStr(str2) && validateStr(str3))) {
		cout << "-1";
		return 0;
	}

	int length1 = strlength(str1);
	int length2 = strlength(str2);
	int length3 = strlength(str3);

	char str4[150];
	char str5[150];
	char str6[150];
	char str7[150];
	newStr(length1, length3, str4, str3);
	newStr(length2, length3, str5, str3);
	newStr(0, length1, str6, str3);
	newStr(0, length2, str7, str3);

	sortElements(str1);
	sortElements(str2);
	sortElements(str4);
	sortElements(str5);
	sortElements(str6);
	sortElements(str7);

	if (compareStr(str1, str6) && compareStr(str2, str4)) {
		cout << "1";
	}
	else if (compareStr(str1, str5) && compareStr(str2, str7)) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}