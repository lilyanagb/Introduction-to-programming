/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Delyana Raykova
* @idnumber 62533
* @task 5
* @compiler VC
*
*/
#include<iostream>
#include<fstream>
using namespace std;

const int MAX_SIZE = 151;

int getLength(char Str[]) {
	int i = 0;
	for (; Str[i] != '\0'; i++) {}
	return i;
}

bool checkLetters(char Array[]) {
	int len = getLength(Array);
	bool check=true;
	for (int i = 0; i < len; i++) {
		if ((Array[i] >= 'A' && Array[i] <= 'Z') || (Array[i] >= 'a' && Array[i] < 'z')) {
			continue;
		}
		else {
			check = false;
			break;
		}
	}
	return check;
}


char getCharacter(char String[]) {
	int length = getLength(String);
	char tempMin = String[0];
	for (int i = 1; i < length; i++) {
		if (tempMin < String[i]) {
			continue;
		}
		else {
			tempMin = String[i];
		}
	}
	char search = 0;
	if (tempMin == 'Z') {
		search = 'a';
	}
	else if (tempMin == 'z') {
		search = '.';
		return search;
	}
	else {
		search = tempMin + 1;
	}
	int i = 0;
	while(i < length) {
		if (search == String[i]) {
			if (search == 'Z') {
				search = 'a';
			}
			else if (search == 'z') {
				search = '.';
				break;
			}
			else {
				search++;
			}
			i = 0;
		}
		else {
			i++;
		}
	}
	return search;
}

int main() {
	ifstream myFile;
	myFile.open("message.txt", ios::app);
	if (!myFile.is_open()) {
		cout<<-2<<endl;
		return 0;
	}
	char Str[MAX_SIZE];
	while (!myFile.eof()) {
		myFile.getline(Str, MAX_SIZE);
		if (!checkLetters(Str)) {
			cout<<-1<<endl;
			return 0;
		}
		else {
			char result= getCharacter(Str);
			if ((result >= 'A' && result <= 'Z') || (result >= 'a' && result <= 'z') || result == '.') {
				cout << result;
			}
		}
	}
	return 0;
}