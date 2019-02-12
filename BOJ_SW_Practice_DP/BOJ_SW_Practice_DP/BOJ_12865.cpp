#include<iostream>
#include<algorithm>
using namespace std;
int n, k, w[105], v[105], d[105][100001];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			d[i][j] = d[i - 1][j];
			if (j - w[i] >= 0) {
				if (d[i][j] < d[i - 1][j - w[i]] + v[i])
					d[i][j] = d[i - 1][j - w[i]] + v[i];
			}
		}
	}
	cout << d[n][k];
}