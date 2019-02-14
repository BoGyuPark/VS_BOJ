#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { -1,1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
int L, R, C, d[31][31][31];
char map[31][31][31];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true) {
		memset(map, 0, sizeof(map));
		memset(d, -1, sizeof(d));
		cin >> L >> R >> C;
		int sx, sy, sz, ex, ey, ez;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {sz = i; sx = j; sy = k;}
					else if (map[i][j][k] == 'E') { ez = i; ex = j; ey = k; map[i][j][k] = '.'; }
				}
			}
		}
		queue<tuple<int, int, int>> q;
		q.push({ sz,sx,sy });
		d[sz][sx][sy] = 0;
		while (!q.empty()) {
			int cx, cy, cz;
			tie(cz, cx, cy) = q.front(); q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = cx + dx[i], ny = cy + dy[i], nz = cz + dz[i];
				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < R && ny < C && nz < L) {
					if (map[nz][nx][ny] == '.' && d[nz][nx][ny] == -1) {
						d[nz][nx][ny] = d[cz][cx][cy] + 1;
						q.push({ nz,nx,ny });
					}
				}

			}
		}
		int ans = d[ez][ex][ey];
		if (ans == -1) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << ans << " minute(s)." << '\n';
	}
}