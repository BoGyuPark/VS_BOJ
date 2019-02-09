#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, d[1002][1002], a[1002][1002];
int go(int i, int j) {
	if (i > n || j > m) return 0;
	if (d[i][j] >= 0) return d[i][j];
	d[i][j] = max(go(i + 1, j), go(i, j + 1)) + a[i][j];
	return d[i][j];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	memset(d, -1, sizeof(d));
	cout << go(1, 1);
}