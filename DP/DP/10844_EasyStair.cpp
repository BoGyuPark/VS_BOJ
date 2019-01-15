//BOJ_10844_EasyStair
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000000
long long d[101][10];
int main() {
	int n; cin >> n;
	d[1][0] = 0;
	d[1][1] = d[1][2] = d[1][3] = d[1][4] = d[1][5] = d[1][6] = d[1][7] = d[1][8] = d[1][9] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				d[i][j] = d[i - 1][1];
			else if (j == 9)
				d[i][j] = d[i - 1][8];
			else 
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];	
			d[i][j] %= mod;
		}
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += d[n][i];
		sum %= mod;
	}
	cout << sum;
	return 0;
}