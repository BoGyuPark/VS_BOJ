#include<iostream>
#define mod 1000000007
using namespace std;
long long t, L, d[5001];
int main() {
	cin >> t;
	d[0] = 1; d[1] = 0; d[2] = 1;
	for (int i = 3; i <= 5000; i++) {
		for (int j = 2; j <= i; j++) {
			d[i] += (d[j - 2] * d[i - j]) % mod;
			d[i] %= mod;
		}
	}
	while (t--) {
		cin >> L;
		cout << d[L] << '\n';
	}
}