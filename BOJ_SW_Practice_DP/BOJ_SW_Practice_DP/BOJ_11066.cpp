#include<iostream>
#include<cstring>
using namespace std;
int t, n,a[501], d[501][501];
int go(int i, int j) {
	if (i == j) return 0;
	if (d[i][j] >= 0) return d[i][j];
	int ij = 0;
	for (int x = i; x <= j; x++) ij += a[x];
	for (int k = i; k < j; k++) {
		int temp = go(i, k) + go(k + 1, j) + ij;
		if (d[i][j] == -1 || d[i][j] > temp)
			d[i][j] = temp;
	}
	return d[i][j];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		memset(d, -1, sizeof(d));
		cout << go(0, n - 1) << '\n';
	}
}