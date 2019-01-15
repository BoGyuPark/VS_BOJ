//BOJ_9465_Sticker
#include<bits/stdc++.h>
using namespace std;
long long d[100001][3];
long long s[100001][2];

int main() {
	int T, n, temp; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j<= n; j++) {
				cin >> s[j][i];
			}
		}
		d[0][0] = d[0][1]= d[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + s[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + s[i][1];
		}	
		cout << max(max(d[n][0], d[n][1]), d[n][2]) << "\n";	
	}
	return 0;
}