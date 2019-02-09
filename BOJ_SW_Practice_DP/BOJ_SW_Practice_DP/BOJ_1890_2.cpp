#include<iostream>
using namespace std;
int n, a[101][101];
long long d[101][101];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> a[i][j];
	d[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) break;
			d[i][j + a[i][j]] += d[i][j];
			d[i + a[i][j]][j] += d[i][j];
		}
	}
	cout << d[n - 1][n - 1];
}