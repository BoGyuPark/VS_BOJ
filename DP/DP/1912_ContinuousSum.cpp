//BOJ_1912_ContinuousSum
#include<bits/stdc++.h>
using namespace std;
int d[100001];
int a[100001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	d[1] = a[1];
	for (int i = 1; i <= n; i++) {
		d[i] = max(d[i - 1] + a[i], a[i]);
	}
	long long ans = d[1];
	for (int i = 2; i <= n; i++) {
		if (ans < d[i])
			ans = d[i];
	}
	cout << ans;
	return 0;
}