#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int a[1001][1001], d[11][1001][1001], n, m, k;
typedef struct info {
	int ix, iy, ir;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
	}
	queue<info> q;
	q.push({ 0,0,0 });
	d[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().ix, y = q.front().iy, cnt = q.front().ir;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			//맵이 빈칸이고 벽을한번도 안부신 경우
			if (a[nx][ny] == 0 && d[cnt][nx][ny] == 0) {
				d[cnt][nx][ny] = d[cnt][x][y] + 1;
				q.push({ nx,ny,cnt });
			}
			//벽을부순횟수가 0이고 맵이 벽이고 이전에 벽을 부순적이 없고 
			if (cnt < k && a[nx][ny] == 1 && d[cnt + 1][nx][ny] == 0) {
				q.push({ nx,ny,cnt + 1 });
				d[cnt + 1][nx][ny] = d[cnt][x][y] + 1;
			}
		}
	}
	int ans = 2147483647;
	for (int i = 0; i <= k; i++) {
		if (d[i][n - 1][m - 1] != 0) {
			if (ans > d[i][n - 1][m - 1]) ans = d[i][n - 1][m - 1];
		}
	}
	if (ans == 2147483647) cout << -1;
	else cout << ans;
}