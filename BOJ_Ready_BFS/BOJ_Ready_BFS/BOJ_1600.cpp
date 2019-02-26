#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, a[201][201], k,d[31][201][201];
int dx[] = { 0,0,1,-1,-1,-2,-2,-1,1,2,2,1 };
int dy[] = { 1,-1,0,0,-2,-1,1,2,2,1,-1,-2 };
typedef struct info {
	int ix, iy, ic;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k >> m >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	memset(d, -1, sizeof(d));
	d[0][0][0] = 0;
	queue<info> q;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		int x = q.front().ix, y = q.front().iy, cnt = q.front().ic;
		q.pop();
		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (a[nx][ny] == 0 && cnt <= k) {
				//인접한 네방향으로 움직인 경우
				if (i < 4) {
					if (d[cnt][nx][ny] == -1) {
						d[cnt][nx][ny] = d[cnt][x][y] + 1;
						q.push({ nx,ny,cnt });
					}
				}
				//말의 움직임으로 움직인 경우
				else {
					if (d[cnt + 1][nx][ny] == -1) {
						d[cnt + 1][nx][ny] = d[cnt][x][y] + 1;
						q.push({ nx,ny,cnt + 1 });
					}
				}
			}
		}
	}
	int ans = 2147483647;
	for (int i = 0; i <= k; i++) {
		if (d[i][n - 1][m - 1] != -1) {
			if (ans > d[i][n - 1][m - 1]) ans = d[i][n - 1][m - 1];
		}
	}
	cout << (ans == 2147483647 ? -1 : ans);
}