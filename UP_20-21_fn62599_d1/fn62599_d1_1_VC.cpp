/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 1
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int main()
{
	int numberOfBirthdays;
	double laptopPrice, toyPrice;

	cin >> numberOfBirthdays >> laptopPrice >> toyPrice;

	double moneyForBirthday = 30;
	int numberOfToys = 0;
	double totalMoney = 0;

	for (int i = 1; i <= numberOfBirthdays; i++) {
		if (i % 2 == 0) {
			totalMoney = totalMoney + (moneyForBirthday - 5);
			moneyForBirthday += 30;
		}
		else {
			numberOfToys++;
		}
	}

	totalMoney = totalMoney + numberOfToys * toyPrice;

	if (totalMoney >= laptopPrice) {
		cout << "yes" << endl;
		cout << totalMoney - laptopPrice;
	}
	else {
		cout << "no" << endl;
		cout << laptopPrice - totalMoney;
	}

	return 0;
}

