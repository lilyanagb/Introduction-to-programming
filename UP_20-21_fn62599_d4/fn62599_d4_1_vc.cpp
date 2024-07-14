/**
*
* Solution to homework assignment 4
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

bool longestIncreasingSub(int arr[], int length, int changes) {
    int longestSubsequence = 0;
    int* arrayToFindMaxCount = new(nothrow) int[length];

    if (arrayToFindMaxCount == nullptr) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        arrayToFindMaxCount[i] = 1;
    }

    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] >= arr[j] && arrayToFindMaxCount[i] < arrayToFindMaxCount[j] + 1) {
                arrayToFindMaxCount[i] = arrayToFindMaxCount[j] + 1;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        if (longestSubsequence < arrayToFindMaxCount[i]) {
            longestSubsequence = arrayToFindMaxCount[i];
        }
    }

    int neededChanges = length - longestSubsequence;
    delete[] arrayToFindMaxCount;

    if (neededChanges <= changes) {
        return true;
    }
    return false;
}

int main() {
    int changes, length;
    cin >> changes >> length;
    int* array = new(nothrow) int[length];
    if (array == nullptr) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }

    if (longestIncreasingSub(array, length, changes)) {
        cout << "1";
    }
    else {
        cout << "0";
    }

    delete[] array;
    return 0;
}