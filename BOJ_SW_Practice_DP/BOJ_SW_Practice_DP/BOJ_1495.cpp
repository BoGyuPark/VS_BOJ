#include<iostream>
#include<cstring>
using namespace std;
int n, s, m, v[101], d[101][1001];
int main() {
	cin >> n >> s >> m;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) cin >> v[i];
	d[0][s] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m ; j++) {
			if (d[i][j] != -1) {
				if (j - v[i] >= 0)	d[i + 1][j - v[i]] = 1;
				if (j + v[i] <= m )	d[i + 1][j + v[i]] = 1;
			}
		}
	}
	int flag = false;
	for (int i = m; i >= 0; i--) {
		if (d[n][i] != -1) {
			cout << i;
			flag = true;
			break;
		}		
	}
	if (flag == false) cout << -1;
}