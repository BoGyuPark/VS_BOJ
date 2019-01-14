//BOJ_9095_Add_OneTwoThree
#include<bits/stdc++.h>
using namespace std;
int main() {
	int T, n; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int *d = new int[n + 1];
		d[1] = 1; d[2] = 2; d[3] = 4;
		for (int j = 4; j <= n; j++)
			d[j] = d[j - 1] + d[j - 2] + d[j - 3];
		cout << d[n] << "\n";
		delete[] d;
	}
	return 0;
}