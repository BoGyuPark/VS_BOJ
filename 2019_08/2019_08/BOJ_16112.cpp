/*BOJ 16112 5Â÷ ÀüÁ÷*/
#include<iostream>
#include<algorithm>
using namespace std;
long long n, k, arr[300'001];
long long sum = 0;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < k; i++) 
		sum += (arr[i] * i);
	for (int i = k; i < n; i++) 
		sum += (arr[i] * k);
	cout << sum;
	return 0;
}