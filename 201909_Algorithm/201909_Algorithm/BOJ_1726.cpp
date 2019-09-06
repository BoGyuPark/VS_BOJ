/*BOJ 1726 로봇*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int r[] = { 2,3,1,0 };
int l[] = { 3,2,0,1 };
int n, m, map[101][101], c[4][4][101][101];
int sx, sy, now_dir, ex, ey, dest_dir, ans;
struct info {
	int dir, k, x, y;
};
queue<info> q;

bool isPossible(int x, int y, int dir, int k) {
	
	for (int i = 1; i <= k; i++) {
		int nx = x + dx[dir] * i, ny = y + dy[dir] * i;
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
		if (map[nx][ny] == 1) return false;
	}
	return true;
}

void bfs() {
	memset(c, -1, sizeof(c));
	q.push({ now_dir - 1,0,sx - 1,sy - 1 });
	c[now_dir - 1][0][sx - 1][sy - 1] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int dir = q.front().dir, dist = q.front().k;
		q.pop();

		//exit 조건
		if (x == ex - 1 && y == ey - 1 && dir == dest_dir - 1) {
			ans = c[dir][dist][x][y];
			return;
		}

		//현재 방향, turn left, turn right

		for (int nextDir : { dir, l[dir], r[dir] }) {
			//현재 방향일때 k가 1,2,3인 경우
			if (nextDir == dir) {
				for (int i = 1; i < 4; i++) {
					if (isPossible(x, y, nextDir, i)) {
						int nx = x + dx[nextDir] * i, ny = y + dy[nextDir] * i;
						if (c[nextDir][i][nx][ny] != -1) continue;
						c[nextDir][i][nx][ny] = c[dir][dist][x][y] + 1;
						q.push({ nextDir,i,nx,ny });
					}
					else break;
				}
			}
			// turn left, turn right
			else {
				if (c[nextDir][0][x][y] != -1) continue;
				c[nextDir][0][x][y] = c[dir][dist][x][y] + 1;
				q.push({ nextDir,0,x,y });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) cin >> map[i][j];

	cin >> sx >> sy >> now_dir >> ex >> ey >> dest_dir;
	bfs();
	cout << ans;
}