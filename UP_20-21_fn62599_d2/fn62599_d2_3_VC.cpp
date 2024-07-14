/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Georgieva Belcheva
* @idnumber 62599
* @task 3
* @compiler VC
*
*/
#include <iostream>
using namespace std;
int main() {

	int countOfIntegers;
	cin >> countOfIntegers;
	int arr[1000];
	int counter = 0;
	while (countOfIntegers < 3 || countOfIntegers > 1000) {
		cin >> countOfIntegers;
	}

	for (int i = 0; i < countOfIntegers; i++) {
		cin >> arr[i];
	}
	int firstElement = 0;
	int lastElement = 0;
	bool isPalindrome = true;

	for (int i = 0; i < countOfIntegers; i++) {
		for (int j = countOfIntegers - 1; j >= i; j--) {
			if (arr[i] == arr[j]) {
				isPalindrome = true;
				firstElement = i;
				lastElement = j;
				for (int p = firstElement; p <= (firstElement + lastElement) / 2; p++) {
					for (int k = lastElement; k >= (firstElement + lastElement + 1) / 2; k--) {
						if (arr[p] != arr[k]) {
							isPalindrome = false;
							break;
						}
						p++;
					}
					if(isPalindrome == false) break;
				}
			}
			if (isPalindrome && (lastElement - firstElement + 1 >= 3)) {
				counter++;
				firstElement = 0;
				lastElement = 0;
			}
		}
	}
	if (counter==0) {
		cout << "-1";
	}
	else {
		cout << counter;
	}
	return 0;
}

