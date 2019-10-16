/*BOJ 16931 ∞—≥–¿Ã ±∏«œ±‚*/
#include<iostream>
using namespace std;
int n, m, height, maxi, ans, map[102][102][102];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> height;
			if (maxi < height) maxi = height;
			for (int z = 0; z < height; z++) map[z][i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int z = 0; z < maxi; z++) {
				if (map[z][i][j] == 1) {
					int cnt = 0;
					for (int d = 0; d < 6; d++) {
						int nx = i + dx[d], ny = j + dy[d], nz = z + dz[d];
						if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= maxi) continue;
						if (map[nz][nx][ny] == 1) cnt++;
					}
					ans += 6 - cnt;
				}
			}
		}
	}
	cout << ans;
}