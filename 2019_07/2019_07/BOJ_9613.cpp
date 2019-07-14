/*BOJ 9613 GCD гу*/
#include<iostream>
using namespace std;
int T, n, arr[101];
int gcd(int a, int b) {
	int n = -1;
	while (n != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		long long ans = 0;
		for (int j = 0; j < n; j++) cin >> arr[j];
		for (int j = 0; j < n; j++) {
			for (int z = j + 1; z < n; z++) {
				ans += gcd(arr[j], arr[z]);
			}
		}
		cout << ans << '\n';
	}
}