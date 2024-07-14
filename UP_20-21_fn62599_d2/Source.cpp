#include <iostream>
#include <vector>
using namespace std;

int main() {
	int countOfNumbers;
	cin >> countOfNumbers;
	int arr[100];
	int newArr[100];
	for (int i = 0; i < countOfNumbers; i++) {
		cin >> arr[i];
	}
	int swapElement;
	for (int i = 0; i < countOfNumbers; i++) {
		for (int j = countOfNumbers - 1; j > i; j--) {
			if (arr[j - 1] > arr[j])
			{
				swapElement = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = swapElement;
			}
		}
	}
	int counter = 0;
	for (int i =0; i < countOfNumbers-1; i++)
	{
			if (arr[i] != arr[i+1]) {
				newArr[counter] = arr[i];
				counter++;
			}
		}
	
	newArr[counter] = arr[countOfNumbers - 1];
	counter++;
	
	int sum = 0;
	bool found = true;
	for (int i = 0; i < counter; i++)
	{
		for (int j = i + 1; j < counter; j++)
		{
			for (int k = j + 1; k < counter; k++)
			{
				if (newArr[i] + newArr[j] + newArr[k] == 0)
				{
					found = true;
					sum++;
					
				}
			}
		}
	}

	if (found){
		cout << sum << endl;
}
   
	return 0;
}