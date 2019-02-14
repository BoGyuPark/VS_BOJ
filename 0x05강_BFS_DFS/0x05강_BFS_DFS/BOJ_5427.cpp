#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int t, n, m, c[1005][1005], f[1005][1005], es[1005][1005], sx, sy;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[1005][1005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		memset(f, -1, sizeof(f));
		memset(es, -1, sizeof(es));
		memset(c, 0, sizeof(c));
		//n행 m열
		cin >> m >> n;
		//바깥 테두리를 위하여 1씩 증가
		m += 2; n += 2;
		//맵완성
		queue<pair<int, int>> fq, q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 || i == n - 1) a[i][j] = 'd';
				else if (j == 0 || j == m - 1) a[i][j] = 'd';
				else {
					cin >> a[i][j];
					if (a[i][j] == '*') {
						fq.push({ i,j });
						c[i][j] = true;
						f[i][j] = 0;
					}
					else if (a[i][j] == '@') {
						sx = i; sy = j;
					}
				}
			}
		}
		//불 bfs
		while (!fq.empty()) {
			int x = fq.front().first, y = fq.front().second;
			fq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 1 && ny >= 1 && nx < n - 1 && ny < m - 1) {
					if (a[nx][ny] != '#' && c[nx][ny] == false) {
						c[nx][ny] = true; f[nx][ny] = f[x][y] + 1;
						fq.push({ nx,ny });
					}
				}
			}
		}
		memset(c, 0, sizeof(c));
		//탈출bfs
		q.push({ sx,sy });
		c[sx][sy] = true;
		es[sx][sy] = 0;
		int ans = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
					if (a[nx][ny] == '.' && c[nx][ny] == false) {
						if (f[nx][ny] == -1 || f[nx][ny] > es[x][y] + 1) {
							c[nx][ny] = true; es[nx][ny] = es[x][y] + 1;
							q.push({ nx,ny });
						}
					}
					else if (a[nx][ny] == 'd' && c[nx][ny] == false) {
						if (f[nx][ny] == -1) {
							ans = es[x][y] + 1;
							while (!q.empty()) {
								q.pop();
							}
							break;
						}
						
					}
				}
			}
		}
		if (ans == 0) cout << "IMPOSSIBLE" << '\n';
		else cout << ans << '\n';
	}
}