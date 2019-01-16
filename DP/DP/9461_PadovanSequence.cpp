//BOJ_9461_PadovanSequence
#include<bits/stdc++.h>
using namespace std;
long long d[101];
int main() {
	int T, n; cin >> T;
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;
	while (T--) {
		cin >> n;
		for (int i = 6; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 5];
		}
		cout << d[n] << '\n';
	}
	
	return 0;
}