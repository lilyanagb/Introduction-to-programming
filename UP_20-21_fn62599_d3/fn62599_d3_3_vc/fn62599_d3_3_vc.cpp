/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 3
* @compiler VC
*
*/
#include <iostream>
using namespace std;

double matrix[1000][1000];

bool magicSquare(double matrix[][1000], int sizeOfMatrix) {
	double firstDiagonalSum = 0;
	double secondDiagonalSum = 0;
	for (int i = 0; i < sizeOfMatrix; ++i) {
		for (int j = 0; j < sizeOfMatrix; ++j) {
			if (i == j) {
				firstDiagonalSum += matrix[i][j];
			}
			if ((i + j) == (sizeOfMatrix - 1)) {
				secondDiagonalSum += matrix[i][j];
			}
		}
	}
	if (firstDiagonalSum != secondDiagonalSum) {
		return false;
	}

	double rowSum = 0;
	double columnSum = 0;
	for (int i = 0; i < sizeOfMatrix; ++i) {
		for (int j = 0; j < sizeOfMatrix; ++j) {
			rowSum += matrix[i][j];
			columnSum += matrix[j][i];
		}
		if (rowSum != firstDiagonalSum || columnSum != firstDiagonalSum) {
			return false;
		}
		rowSum = 0;
		columnSum = 0;
	}
	return true;
}

int main() {
	int sizeOfMatrix;
	cin >> sizeOfMatrix;
	if (sizeOfMatrix >= 1 && sizeOfMatrix <= 1000) {
		for (int i = 0; i < sizeOfMatrix; ++i) {
			for (int j = 0; j < sizeOfMatrix; ++j) {
				do {
					cin >> matrix[i][j];
				} while (matrix[i][j] < 0 || matrix[i][j] > 100);
			}
		}
	}
	if (magicSquare(matrix, sizeOfMatrix)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}