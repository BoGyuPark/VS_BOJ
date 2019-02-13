#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int t, n, sx, sy, ex, ey, a[301][301], c[301][301];
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(c, -1, sizeof(c));
		cin >> n >> sx >> sy >> ex >> ey;
		queue<pair<int, int>> q;
		if (sx == ex && sy == ey) cout << 0 << '\n';
		else {
			q.push({ sx,sy }); c[sx][sy] = 0;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second; q.pop();
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
						if (c[nx][ny] == -1) {
							c[nx][ny] = c[x][y] + 1;
							q.push({ nx,ny });
						}
					}
				}

			}
			cout << c[ex][ey] << '\n';
		}
	}
}