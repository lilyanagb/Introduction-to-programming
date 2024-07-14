/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Georgieva Belcheva
* @idnumber 62599
* @task 2
* @compiler VC
*
*/

#include <iostream>
using namespace std;
int main() {
	int numberOfDays;
	cin >> numberOfDays;
	double arr[365];
	while (numberOfDays < 3 || numberOfDays > 365) {
		cin >> numberOfDays;
	}

	for (int i = 0; i < numberOfDays; i++) {
		while (arr[i] < 0.1 || arr[i] > 100) {
			cin >> arr[i];
		}
	}

	double profit = 0;
	double maxElement = arr[0];
	double minElement = arr[0];

	for (int i = 1; i < numberOfDays; i++) {
		if (maxElement < arr[i]) {
			maxElement = arr[i];
		}
		else if (maxElement > arr[i]) {
			if (maxElement > minElement) {
				profit += (maxElement - minElement);
			}
			maxElement = arr[i]; 
			minElement = arr[i];
		}
	}

	if (maxElement > minElement) {
		profit += (maxElement - minElement);
	}

	cout << profit;
	return 0;
}