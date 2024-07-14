#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//multiply digits of number
//int recursion(int sum,int& counter){
//
//	if (sum < 10) return sum;
//	counter++;
//	int digit = 0;
//	int product = 1;
//
//	while (sum != 0) {
//    digit = sum % 10;
//	product *= digit;
//	sum /= 10;
//	}
//
//	return recursion(product,counter);
//}
//
//int main() {
//	int countOfNumbers;
//	int numbers;
//	int counter = 0;
//	cin >> countOfNumbers;
//	int sum = 0;
//	for (int i = 0; i < countOfNumbers; i++) {
//		cin >> numbers;
//
//		if (numbers < 0) {
//			numbers *= -1;
//		}
//		sum += numbers;
//	}
//	cout << recursion(sum,counter)<< " ";
//	cout << counter;
//	return 0;
//}

//dali ima 3 posledovatelni cifri
//bool isCorrectOrder(int number) {
//	int counter = 0;
//	int numberAgain = number;
//
//	while (number != 0) {
//		number /= 10;
//		counter++;
//	}
//	
//	int arr[300];
//	int i = 0;
//	arr[i] = numberAgain % 10;
//	while(numberAgain != 0){
//		numberAgain /= 10;
//		arr[i+1] = numberAgain % 10;
//		i++;
//	}
//
//	bool flag = false;
//	for (int i = 0; i < counter-2; i++) {
//		if ((arr[i] - 1 == arr[i + 1]) && (arr[i + 1] - 1 == arr[i + 2])) {
//			flag=true;
//		}
//		else if ((arr[i] + 1 == arr[i + 1]) && (arr[i + 1] + 1 == arr[i + 2])) {
//			flag = true;
//		}
//	}
//	if (flag) {
//		return true;
//	}
//	return false;
//}
//int main() {
//	int number;
//	cin >> number;
//	
//	if (isCorrectOrder(number)) {
//		cout << "1";
//	}
//	else {
//		cout << "0";
//	}
//}

//sborut na cifrite da dava poslednite 2 
//int main() {
//	int number;
//	cin >> number;
//	int numberAgain = number;
//	int digit = 0;
//	int sum = 0;
//	while (number != 0) {
//		digit = number % 10;
//		sum += digit;
//		number /= 10;
//	}
//
//	int lastTwoDigits = numberAgain % 10 + ((numberAgain / 10) % 10) * 10;
//	if (lastTwoDigits == sum) {
//		cout << "yes";
//	}
//	else {
//		cout << "no";
//	}
//	return 0;
//}

//rekursiya da obrushta cifrite ot oboznachen start i krai
//vector<int> swapArr(vector<int> array, int start, int end) {
//	if (start > end) return array;
//	
//	if (start == end) return array;
//
//	int swapElement = 0;
//	swapElement = array[start];
//	array[start] = array[end];
//	array[end] = swapElement;
//	
//	return swapArr(array, start + 1, end - 1);
//}
//
//int main() {
//	int countOfNumber;
//	cin >> countOfNumber;
//
//	vector<int> arr(countOfNumber);
//	int element;
//
//	for (int i = 0; i < countOfNumber; i++) {
//		cin >> element;
//		arr[i] = element;
//	}
//
//	int start = 0,end = 0;
//	cin >> start >> end;
//
//	if ((start >= end) || (end >= countOfNumber) || (start < 0) || (end < 0)) {
//		cout << -1;
//		return 0;
//	}
//
//	vector<int> newArr = swapArr(arr, start, end);
//    for (int i = 0; i < countOfNumber; i++) {
//		cout << arr[i] << " ";
//	}
//
//	cout << endl;
//
//	for (int i = 0; i < countOfNumber; i++) {
//		cout << newArr[i] << " ";
//	}
//	return 0;
//}

//sushtata no s masiv
//int* swapArr(int array[], int start, int end) {
//	if (start > end) return array;
//
//	if (start == end) return array;
//
//	int swapElement = 0;
//	swapElement = array[start];
//	array[start] = array[end];
//	array[end] = swapElement;
//
//	return swapArr(array, start + 1, end - 1);
//}
//
//int main() {
//	int countOfNumber;
//	cin >> countOfNumber;
//	int arr[300];
//	
//	for (int i = 0; i < countOfNumber; i++) {
//		cin >> arr[i];
//	}
//
//	int start = 0, end = 0;
//	cin >> start >> end;
//
//	if ((start >= end) || (end >= countOfNumber) || (start < 0) || (end < 0)) {
//		cout << -1;
//		return 0;
//	}
//
//	for (int i = 0; i < countOfNumber; i++) {
//		cout << arr[i] << " ";
//	}
//
//	cout << endl;
//
//	int* newArr = swapArr(arr, start, end);
//	for (int i = 0; i < countOfNumber; i++) {
//		cout << newArr[i] << " ";
//	}
//	return 0;
//}


//proverka za povtaryashti se elementi
//int main() {
//	int num;
//	cin >> num;
//	int element = 0,counter = 0;
//	int arr[300];
//	while (num != 0) {
//		arr[element] = num % 10;
//		element++;
//		num /= 10;
//	}
//
//	for (int i = 0; i < element; i++) {
//		for (int j = 1; j < element; j++) {
//			if (arr[i] == arr[j]) {
//				counter++;
//			}
//		}
//	}
//	if (counter >= 2) {
//		cout << "1";
//	}
//	else {
//		cout << "0";
//	}
//	return 0;
//}

//sortirane i izvajdane dokato ne se poluchi const Q

int main() {
	int num;
	cin >> num;
	int n = 0;
	int a[300];

	while (num != 0) {
		arr[n] = num % 10;
		n++;
		num /= 10;
	}
	int buf;
	for (int i = 0; n > i; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j])
			{
				buf = a[j - 1];
				a[j - 1] = a[j];
				a[j] = buf;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	
	return 0;
}