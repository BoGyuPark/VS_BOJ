#include<iostream>
#include<algorithm>
using namespace std;
int n, m, d[1002][1002], a[1002][1002], i, j;
int main() {
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) cin >> a[i][j];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)	d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i][j];
	cout << d[n][m];
}