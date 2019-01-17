//BOJ_9613_SumOfGCD
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int arr[101]; long long sum = 0;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}