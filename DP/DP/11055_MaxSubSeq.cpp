//BOJ_11055_MaxSubSeq
#include<bits/stdc++.h>
using namespace std;
long long d[1001];
int a[1001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + a[i]) {
				d[i] = d[j] + a[i];
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i])
			ans = d[i];
	}
	cout << ans;
	return 0;
}