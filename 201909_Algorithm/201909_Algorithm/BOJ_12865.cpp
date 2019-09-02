/* BOJ 12865 평범한 배낭*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, k, w[101], v[101], d[101][100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	//보석 종류
	for (int i = 1; i <= n; i++) {
		//가방 무게
		for (int j = 1; j <= k; j++) {
			if (j - w[i] < 0) d[i][j] = d[i - 1][j];
			else {
				d[i][j] = max(d[i - 1][j - w[i]] + v[i], d[i - 1][j]);
			}
		}
	}
	cout << d[n][k];
}