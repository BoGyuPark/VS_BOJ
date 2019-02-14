#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int a[201][201], d[31][201][201], k, n, m, cnt;
int dx[] = { 0,0,-1,1,-2,-2,-1,-1,1,1,2,2 };
int dy[] = { 1,-1,0,0,-1,1,-2,2,-2,2,-1,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k >> m >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,k });
	d[k][0][0] = 0;
	while (!q.empty()) {
		int x, y, re;
		tie(x, y, re) = q.front(); q.pop();
		cnt = (re <= 0 ? 4 : 12);
		for (int i = 0; i < cnt; i++) {
			int na = re;
			if (i >= 4) na -= 1;
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (a[nx][ny] == 0 && d[na][nx][ny] == -1) {
					d[na][nx][ny] = d[re][x][y] + 1;
					q.push({ nx,ny,na });
				}
			}
		}
	}
	int ans = 2147483647;
	for (int i = 0; i <= k; i++)
		if (d[i][n - 1][m - 1] != -1 && ans > d[i][n - 1][m - 1]) ans = d[i][n - 1][m - 1];
	std::cout << (ans == 2147483647 ? -1 : ans);
}