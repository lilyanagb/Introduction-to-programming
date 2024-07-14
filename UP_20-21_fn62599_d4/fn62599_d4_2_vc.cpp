/**
*
* Solution to homework assignment 4
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

int xCoordOfBoard, yCoordOfBoard;
int xCoordOfHorse, yCoordOfHorse;
int newX, newY;

bool isValid(int** chessBoard, int x, int y) {
	if (x < 0 || y < 0 || x >= xCoordOfBoard || y >= yCoordOfBoard) {
		return false;
	}
	return true;
}

bool possibleMove(int nextX, int nextY, int move, int** position) {
	bool flag = false;
	int row[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int col[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	if (position[newY][newX] == 1) {
		return true;
	}

	int tempX = nextX, tempY = nextY;
	for (int k = 0; k < 8; k++) {
		nextX = tempX + row[k];
		nextY = tempY + col[k];

		if (isValid(position, nextX, nextY) && move > 0) {
			position[nextY][nextX] = 1;
			flag = possibleMove(nextX, nextY, move - 1, position);

			if (flag) {
				break;
			}
		}
	}
	return flag;
}

int main() {
	int moves;
	cin >> yCoordOfBoard;
	if (yCoordOfBoard <= 3 || yCoordOfBoard > 200) {
		cout << -1;
		return 0;
	}

	cin >> xCoordOfBoard;
	if (xCoordOfBoard <= 3 || xCoordOfBoard > 200) {
		cout << -1;
		return 0;
	}

	cin >> yCoordOfHorse;
	if (yCoordOfHorse < 0 || yCoordOfHorse > yCoordOfBoard) {
		cout << -1;
		return 0;
	}


	cin >> xCoordOfHorse;
	if (xCoordOfHorse < 0 || xCoordOfHorse > xCoordOfBoard) {
		cout << -1;
		return 0;
	}

	cin >> newY;
	if (newY < 0 || newY > yCoordOfBoard) {
		cout << -1;
		return 0;
	}

	cin >> newX;
	if (newX < 0 || newX > xCoordOfBoard) {
		cout << -1;
		return 0;
	}

	cin >> moves;
	if (moves <= 0 || moves > 30) {
		cout << -1;
		return 0;
	}

	int** position = new(nothrow) int* [yCoordOfBoard];
	if (position == nullptr) {
		return 0;
	}

	for (int i = 0; i < yCoordOfBoard; i++) {
		position[i] = new(nothrow) int[xCoordOfBoard];
	}

	for (int i = 0; i < yCoordOfBoard; i++) {
		for (int j = 0; j < xCoordOfBoard; j++) {
			position[i][j] = 0;
		}
	}

	position[yCoordOfHorse][xCoordOfHorse] = 1;

	if (possibleMove(xCoordOfHorse, yCoordOfHorse, moves, position)) {
		cout << "True";
	}
	else {
		cout << "False";
	}

	for (int i = 0; i < yCoordOfBoard; i++) {
		delete[] position[i];
	}

	delete[] position;
	return 0;
}