#include<iostream>
using namespace std;
int arr[] = { 1,10,5,8,7,6,4,3,2,9 };
void printArr() {
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}
int main() {
	for (int i = 0; i < 10; i++) {
		int mini = 2147483647, index = -1;
		for (int j = i; j < 10; j++) {
			if (mini > arr[j]) {
				mini = arr[j];
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	printArr();
}