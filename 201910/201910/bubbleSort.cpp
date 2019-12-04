#include<iostream>
using namespace std;
int arr[] = { 1,10,5,8,7,6,4,3,2,9 };
void printArr() {
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}
int n;
int main() {
	n = 10;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}		
	}
	printArr();
}