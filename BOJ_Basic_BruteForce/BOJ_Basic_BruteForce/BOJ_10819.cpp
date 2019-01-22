#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int arr[10], n, i, j, sum = 0, temp = 0;
int main() {
	cin >> n;	for (i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n); 
	do {
		temp = 0;
		for (j = 0; j < n - 1; j++)
			temp += abs(arr[j] - arr[j + 1]);
		if (sum < temp)
			sum = temp;
	} while (next_permutation(arr, arr + n));
	cout << sum;
	return 0;
}