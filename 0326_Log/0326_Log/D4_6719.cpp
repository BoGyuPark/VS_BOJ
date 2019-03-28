#include<iostream>
#include<algorithm>
using namespace std;
int tc, T, n, k, wait[201];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	for (T = 1; T <= tc; T++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin>>wait[i];
		sort(wait, wait + n);
		double cal = 0;
		for (int j = n-k; j < n; j++) cal = (cal + wait[j]) / 2.0;
		cout << fixed;
		cout << '#' << T << ' ' << cal << '\n';
	}
}