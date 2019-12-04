#include<iostream>
using namespace std;
int arr[] = { 10,1,5,8,7,6,4,3,2,9 };
void printArr() {
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}
int n;
int main() {
	n = 10;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j-1] > arr[j]) {
			int temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
	printArr();
}