#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int m, n, H, a[101][101][101], d[101][101][101];
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> H;
	int tomacnt = 0;
	queue<tuple<int, int, int>> q;
	memset(d, -1, sizeof(d));
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[h][i][j];
				if (a[h][i][j] == 0) tomacnt++;
				else if (a[h][i][j] == 1) {
					q.push(make_tuple(h,i,j));
					d[h][i][j] = 0;
				}
			}
		}
	}
	if (tomacnt == 0) cout << 0;
	else {
		while (!q.empty()) {
			int x, y, z; tie(z,x, y) = q.front(); q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < H) {
					if (a[nz][nx][ny] == 0 && d[nz][nx][ny] == -1) {
						d[nz][nx][ny] = d[z][x][y] + 1;
						q.push(make_tuple(nz, nx, ny));
					}
				}
			}
		}
		int ans = 0, flag = false;
		for (int h = 0; h < H; h++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (a[h][i][j] == 0 && d[h][i][j] == -1) {
						cout << -1; i = n; h = H; flag = true; break;
					}
					if (ans < d[h][i][j]) ans = d[h][i][j];
				}
			}
		}
		if (flag == false) cout << ans;
	}
}