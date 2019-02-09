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
			//위에서 오는 경우
			for (int z = 0; z < i; z++) {
				if (a[z][j] == i - z) {
					d[i][j] += d[z][j];
				}
			}
			//왼쪽에서 오는 경우
			for (int z = 0; z < j; z++) {
				if (a[i][z] == j - z) {
					d[i][j] += d[i][z];
				}
			}
		}
	}
	cout << d[n - 1][n - 1];
}