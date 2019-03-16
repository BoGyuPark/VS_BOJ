#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, l, r, a[51][51], d[51][51], ans = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void bfs() {
	int c[51][51] = { 0, }, sum, cnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] == true) continue;
			if (d[i][j] == 0) continue;
			queue<pair<int, int>> q, team;
			q.push({ i,j });
			team.push({ i,j });
			c[i][j] = true;
			sum = a[i][j];
			cnt = 1;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					if (d[x][y] & (1 << z)) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (c[nx][ny] == true) continue;
						c[nx][ny] = true;
						q.push({ nx,ny });
						team.push({ nx,ny });
						sum += a[nx][ny];
						cnt++;
					}
				}
			}

			while (!team.empty()) {
				a[team.front().first][team.front().second] = sum / cnt;
				team.pop();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	while (true) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z], ny = j + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					int t = abs(a[nx][ny] - a[i][j]);
					if (t >= l && t <= r) {
						d[i][j] += (1 << z);
						flag++;
					}
				}
			}
		}
		bfs();
		memset(d, 0, sizeof(d));
		if (flag == 0) break;
		ans++;
	}
	cout << ans;
}