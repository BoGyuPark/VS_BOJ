/*BOJ 10972 다음 순열*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[10001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int num = next_permutation(arr, arr + n);
	if (num == 0) cout << -1;
	else {
		for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	}
}