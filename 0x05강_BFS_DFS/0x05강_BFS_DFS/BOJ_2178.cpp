#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, i, j, d[101][101];
char a[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main() {
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) cin >> a[i][j];
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	d[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (a[nx][ny] == '1' && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << d[n - 1][m - 1];
}