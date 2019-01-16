//BOJ_11054_LongestBitonicSeq
#include<bits/stdc++.h>
using namespace std;
int d[1001];
int d2[1001];
int a[1001];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = 1;
		d2[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	for (int i = n; i > 0; i--) {
		for (int j = i; j <= n; j++) {
			if (a[j] < a[i] && d2[i] < d2[j] + 1)
				d2[i] = d2[j] + 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i] + d2[i] - 1)
			ans = d[i] + d2[i] - 1;
	}
	cout << ans;
	
	return 0;
}