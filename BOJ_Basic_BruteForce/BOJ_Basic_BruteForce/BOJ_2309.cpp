//BOJ_BOJ_2309
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int arr[10];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = arr[j] = -1;
				i = 10;
				break;
			}
		}
	}
	sort(arr, arr + 9);
	for (int i = 2; i < 9; i++)
		cout << arr[i] << '\n';
	return 0;
}