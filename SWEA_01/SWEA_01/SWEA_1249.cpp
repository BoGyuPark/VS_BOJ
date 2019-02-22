#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int t, n, d[102][102], map[102][102];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a;
int main() {
	cin >> t;
	memset(d, 0, sizeof(d));
	memset(map, 0, sizeof(map));
	for (int s = 1; s <= t; s++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				cin >> a;
				map[i][j] = a - '0';
				d[i][j] = 999;
			}
		d[1][1] = 0;
		queue<pair<int, int>> q;
		q.push({ 1,1 });
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
					if (d[nx][ny] > d[x][y] + map[nx][ny]) {
						q.push({ nx,ny });
						d[nx][ny] = d[x][y] + map[nx][ny];
					}
				}
			}
		}
		cout <<'#'<<s<<' '<< d[n][n] << '\n';
	}
}