#include<iostream>
#include<algorithm>
using namespace std;
int arr[10], i,j, n;
int main() {
	cin >> n;
	for (i = 0; i < n; i++) arr[i] = i + 1;
	do {
		for (j = 0; j < n; j++) cout << arr[j] << ' ';
		cout << '\n';
	} while (next_permutation(arr , arr + n));
	return 0;
}