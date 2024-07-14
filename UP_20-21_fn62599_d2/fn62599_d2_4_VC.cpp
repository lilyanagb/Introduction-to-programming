/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Georgieva Belcheva 
* @idnumber 62599
* @task 4
* @compiler VC
*
*/
#include <iostream>
using namespace std;
int main() {
	int countOfUniqueElements;
	cin >> countOfUniqueElements;

	while (countOfUniqueElements < 3 || countOfUniqueElements > 100) {
		cin >> countOfUniqueElements;
	}
		int newArr[100];
		int counter = 0;
		int elements;
		while (counter < countOfUniqueElements) {
			cin >> elements;
			bool isUniqueElement = true;

			for (int i = 0; i < counter; i++) {
				if (newArr[i] == elements) {
					isUniqueElement = false;
				}
			}
			if (isUniqueElement) {
				newArr[counter] = elements;
				counter++;
			}
		}
	
		int sum = 0;
		bool found = true;
		for (int i = 0; i < counter; i++){
			for (int j = i + 1; j < counter; j++){
				for (int k = j + 1; k < counter; k++){
					if (newArr[i] + newArr[j] + newArr[k] == 0){
						found = true;
						sum++;
					}
				}
			}
		}

		if (found) {
			cout << sum << endl;
		}
	return 0;
}