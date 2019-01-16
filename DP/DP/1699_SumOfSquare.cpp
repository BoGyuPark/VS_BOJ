//BOJ_1699_SumOfSquare
#include<bits/stdc++.h>
using namespace std;
int d[100001];
int main() {
	int n; cin >> n;
	d[0] = 0; d[1] = 1;
	for (int i = 2; i <= n; i++) {
		int mini = d[i - 1];
		for (int j = 2; j*j <= i; j++) {
			if (mini > d[i - j * j])
				mini = d[i - j * j];
		}
		d[i] = mini + 1;
	}
	cout << d[n];
	return 0;
}