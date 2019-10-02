/* BOJ 6593 »ó¹ü ºôµù */
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int L, n, m, check[31][31][31], sL, sx, sy, ans;
char build[31][31][31];
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
struct info {
	int z, x, y;
};
queue<info> q;
bool bfs() {
	memset(check, -1, sizeof(check));
	check[sL][sx][sy] = 0;
	q.push({ sL,sx,sy });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nz >= L || nx >= n || ny >= m) continue;
			if (check[nz][nx][ny] != -1) continue;
			if (build[nz][nx][ny] == '#') continue;
			if (build[nz][nx][ny] == 'E') {
				ans = check[z][x][y] + 1;
				while (!q.empty()) q.pop();
				return true;
			}
			else if (build[nz][nx][ny] == '.') {
				check[nz][nx][ny] = check[z][x][y] + 1;
				q.push({ nz,nx,ny });
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> L >> n >> m;
		if (L == 0) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < n; j++) {
				for (int z = 0; z < m; z++) {
					cin >> build[i][j][z];
					if (build[i][j][z] == 'S') {
						sL = i, sx = j, sy = z;
					}
				}
			}
		}
		ans = 0;
		if (bfs()) cout << "Escaped in " << ans << " minute(s).\n";
		else cout << "Trapped!\n";
	}

}