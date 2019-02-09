#include<iostream>
#include<algorithm>
using namespace std;
int a[1002][1002], d[1002][1002], n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)	d[i][j] = max(d[i - 1][j - 1], max(d[i - 1][j], d[i][j - 1])) + a[i][j];
	cout << d[n][m];
}