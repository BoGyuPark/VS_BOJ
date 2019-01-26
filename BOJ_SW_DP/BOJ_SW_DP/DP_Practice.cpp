#include<iostream>
#define mod 1000000000;
using namespace std;
int n, k, d[205][205],l,i,j;
int main() {
	cin >> n >> k;	d[0][0] = 1;
	for (i = 1; i <= k; i++) {
		for (j = 0; j <= n; j++) {
			for (l = 0; l <= j; l++) {
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= mod;
			}
		}
	}
	cout << d[k][n];
}