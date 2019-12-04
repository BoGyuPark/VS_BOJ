#include<iostream>
using namespace std;
int arr[] = { 10,1,5,8,7,6,4,3,2,9 };
void printArr() {
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}
int n;
void quickSort(int s, int e) {
	if (s >= e) return;
	int pivot = s;
	int i = s + 1, j = e;
	
	//엇갈릴 때 까지 반복
	while (i <= j) {
		while (arr[pivot] >= arr[i]) i++;
		while (arr[pivot] <= arr[j] && j > s) j--;

		//엇갈렷다면
		if (i > j) swap(arr[j], arr[pivot]);
		else swap(arr[i], arr[j]);
	}
	quickSort(s, j - 1);
	quickSort(j + 1, e);
}
int main() {
	n = 10;
	quickSort(0, n - 1);
	printArr();
}