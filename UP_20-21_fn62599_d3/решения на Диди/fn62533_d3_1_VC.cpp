/**
*
* Solution to homework assignment 3
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

const int MAX_SIZE = 150;

int getDifference(char Str1[], int uniqueness, int maxRep, int length) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		int repetition = 1;
		for (int j = 0; j < length; j++) {
			if (Str1[i] == Str1[j] && i != j) {
				repetition++;
			}
		}
		if(maxRep != repetition) {
			counter++;
		}
	}
	int maxRepeatedChar = (length - counter) / maxRep;
	if (counter <= 1) {
		return 0;
	}
	else if (maxRep * maxRepeatedChar - 1 == counter / (uniqueness - maxRepeatedChar)) {
		return 0;
	}
	return 2;
}

int getUniqueness(char Array[], int length) {
	int uniqueness = length;
	for (int i = 0; i <length; i++) {
		for (int j = i+1; j < length; j++) {
			if (Array[j] == Array[i]) {
				uniqueness--;
				break;
			}
		}
	}
	return uniqueness;
}

int getLength(char Arr[]) {
	int i = 0;
	for (; Arr[i] != '\0'; i++) {}
	return i;
}

int getMaxRepetition(char Str3[], int arrayLength) {
	int max = 0;
	for (int i = 0; i < arrayLength; i++) {
		int repetition = 1;
		for (int j = 0; j < arrayLength; j++) {
			if (Str3[i] == Str3[j] && i != j) {
				repetition++;
			}
		}
		if (max < repetition) {
			max = repetition;
		}
	}
	return max;
}

bool isRight(char First[]) {
	int lengthOfArray = getLength(First);
	int maxRep = getMaxRepetition(First, lengthOfArray);
	int uniq = getUniqueness(First, lengthOfArray);
	int diff = getDifference(First, uniq, maxRep, lengthOfArray);
	if (diff == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	char myChar[MAX_SIZE];
	cin.getline(myChar,MAX_SIZE);
	cout<<isRight(myChar)<<endl;
	return 0;
}