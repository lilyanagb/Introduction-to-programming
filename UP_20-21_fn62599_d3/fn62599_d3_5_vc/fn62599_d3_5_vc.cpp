/**
*
* Solution to homework assignment 3
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
#include <fstream>
using namespace std;

int length(char str[]) {
	int i = 0;
	for (; str[i] != '\0'; ++i) {}
	return i;
}

bool validateStr(char str[]) {
	for (int i = 0; i < length(str); ++i) {
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')) {
			return false;
		}
	}
	return true;
}

void sortWord(char arr[]) {
	int n = length(arr);
	int swapElement;
	for (int i = 0; n > i; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j - 1] > arr[j])
			{
				swapElement = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = swapElement;
			}
		}
	}
}

void fillStr(char arr[]) {
	int counter = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		arr[counter] = i;
		counter++;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		arr[counter] = i;
		counter++;
	}
	arr[counter] = '\0';
}

void removeLetters(char arr[], char word[]) {
	sortWord(word);
	int i = 0;
	while (arr[i] != word[0]) {
		arr[i] = '1';
		i++;
	}
	i = 0;
	while (word[i] != '\0') {
		for (int j = 0; j < length(arr); j++) {
			if (word[i] == arr[j]) {
				arr[j] = '1';
				break;
			}
		}
		i++;
	}
}

char getLetter(char arr[]) {
	sortWord(arr);

	for (int counter = 0; counter < length(arr); counter++) {
		if (arr[counter] != '1') {
			return arr[counter];
		}
	}
		return '.';
}

int main() {
	ifstream readToFile;
	readToFile.open("message.txt");

	char alphabetStr[53];
	char newWord[1001];
	int counter = 0;

	if (!readToFile.is_open()) {
		cout << "cannot be open";
		return -1;
	}

	while (readToFile.good()) {
		char str1[1025] = { '\0', };
		fillStr(alphabetStr);
		readToFile >> str1;

		if (str1[151] != '\0') {
			str1[151] = '\0';
		}
		if (!validateStr(str1)) {
			cout << "-1";
			return -1;
		}
		
		removeLetters(alphabetStr, str1);
		newWord[counter] = getLetter(alphabetStr);
		counter++;

	}
	newWord[counter] = '\0';
	cout << newWord;

	readToFile.close();
	return 0;
}