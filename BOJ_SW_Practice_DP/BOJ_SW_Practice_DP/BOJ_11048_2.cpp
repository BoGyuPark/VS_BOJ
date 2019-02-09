#include<iostream>
#include<algorithm>
using namespace std;
int n, m, d[1002][1002], a[1002][1002], i, j;
int main() {
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)	cin >> a[i][j];
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			if (d[i + 1][j + 1] < d[i][j] + a[i + 1][j + 1])
				d[i + 1][j + 1] = d[i][j] + a[i + 1][j + 1];
			if (d[i + 1][j] < d[i][j] + a[i + 1][j])
				d[i + 1][j] = d[i][j] + a[i + 1][j];
			if (d[i][j + 1] < d[i][j] + a[i][j + 1])
				d[i][j + 1] = d[i][j] + a[i][j + 1];
		}
	}
	cout << d[n][m];
}