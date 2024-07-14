/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Delyana Raykova
* @idnumber 62533
* @task 3
* @compiler VC
*
*/
#include <iostream>
#include <vector>
using namespace std;

const double EPSILON = 0.000001;
const int ZERO = 0;
const int ONE = 1;
const int HUNDRED = 100;
const int THOUSAND = 1000;

double getDiagonalSum(vector<vector<double>>matrix1, int size) {
	double sum1 = 0;
	for (int i = 0; i < size; i++) {
		sum1 += matrix1[i][i];
	}
	return sum1;
}

double getOtherDiagonalSum(vector<vector<double>> matrix2, int size) {
	double sum2 = 0;
	for (int i = 0; i < size; i++) {
		sum2 += matrix2[i][size - i -1];
	}
	return sum2;
}

double getRowSum(vector<vector<double>>matrix3, int size, int row) {
	double sum3 = 0;
	for (int i = 0; i < size; i++) {
		sum3 += matrix3[row][i];
	}
	return sum3;
}

double getColumnSum(vector<vector<double>>matrix4, int size, int column) {
	double sum4 = 0;
	for (int i = 0; i < size; i++) {
		sum4 += matrix4[i][column];
	}
	return sum4;
}

bool compareDoubles(double number1, double number2) {
	if (abs(number1 - number2) < EPSILON) {
		return true;
	}
	return false;
}

bool isMagicSquare(vector<vector<double>> matrix, int size) {
	double sumDiagonal = getDiagonalSum(matrix, size);
	double sumOtherDiagonal = getOtherDiagonalSum(matrix, size);
	if (!compareDoubles(sumDiagonal,sumOtherDiagonal)) {
		return false;
	}
	vector <double> rowSums(size);
	for (int i = 0; i < size; i++) {
		rowSums[i]=getRowSum(matrix, size, i);
	}
	for (int i = 0; i < size - 1; i++) {
		if (!compareDoubles(rowSums[i], rowSums[i + 1])) {
			return false;
		}
	}
	vector <double> columnsSums(size);
	for (int i = 0; i < size; i++) {
		columnsSums[i] = getColumnSum(matrix, size, i);
	}
	for (int i = 0; i < size-1; i++) {
		if (!compareDoubles(columnsSums[i], columnsSums[i + 1])) {
			return false;
		}
	}
	if (!compareDoubles(rowSums[ONE], columnsSums[ONE])) {
		return false;
	}
	else if (!compareDoubles(rowSums[ONE], sumDiagonal)) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int number = ONE;
	while (number <= ONE || number >= THOUSAND) {
		cin >> number;
	}
	vector <vector<double>> myVector1;

	double element = 0;
	for (int i = 0; i < number; i++) {
		vector<double> row;
		for (int j = 0; j < number; j++) {
			do {
				cin >> element;
			} 
			while (element < ZERO || element > HUNDRED);
			row.push_back(element);
		}
		myVector1.push_back(row);
	}

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << myVector1[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << isMagicSquare(myVector1,number) << endl;
	return 0;
}