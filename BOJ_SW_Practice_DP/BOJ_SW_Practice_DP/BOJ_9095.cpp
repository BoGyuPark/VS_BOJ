#include<iostream>
using namespace std;
int t, n;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int d[12] = { 0, };
		d[0] = 1; d[1] = 1; d[2] = 2;
		for (int i = 3; i <= n; i++)
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		cout << d[n] << '\n';
	}
}