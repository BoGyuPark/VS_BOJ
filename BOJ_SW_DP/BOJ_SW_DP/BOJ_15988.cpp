#include<iostream>
#include<cstring>
#define mod 1000000009
using namespace std;
int t, n;
long long d[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	d[0] = 1; d[1] = 1; d[2] = 2;
	for (int i = 3; i <= 1000000; i++) {
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % mod;
	}
	while (t--) {
		cin >> n;
		cout << d[n] << "\n";
	}
	return 0;
}