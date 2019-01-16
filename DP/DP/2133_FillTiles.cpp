//BOJ_2133_FillTiles
#include<bits/stdc++.h>
using namespace std;
int d[31];
int main() {
	int n; cin >> n;
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 2] * 3;
		int minusTemp = -4;
		while (i + minusTemp >= 0) {
			d[i] += 2 * d[i + minusTemp];
			minusTemp -= 2;
		}
	}
	cout << d[n];
	return 0;
}