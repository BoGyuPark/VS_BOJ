#include<iostream>
using namespace std;
long long n, v[101], d[101][22];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	int result = v[n - 1];
	d[0][v[0]] = 1;
	for (int i = 1; i <n-1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - v[i] >= 0)	d[i][j] += d[i - 1][j - v[i]];
			if (j + v[i] <= 20)		d[i][j] += d[i - 1][j + v[i]];
		}
	}
	cout << d[n-2][result];
}