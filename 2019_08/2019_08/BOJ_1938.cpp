/*BOJ 1938 통나무 옮기기*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define HORI 0
#define VERTI 1
char map[51][51];
vector<pair<int, int>> B, E;
int n, check[2][51][51], ans;
int ex, ey, sDir = VERTI, eDir = VERTI;
int dx[] = { -1,1,0,0,0 };
int dy[] = { 0,0,-1,1,0 };
int Rdx[] = { -1,-1,-1,0,0,1,1,1 };
int Rdy[] = { -1,0,1,-1,1,-1,0,1 };
typedef struct {
	int x, y, dir;
}info;
queue<info> q;
bool isRoate(int x, int y) {
	for (int z = 0; z < 8; z++) {
		int nnx = x + Rdx[z], nny = y + Rdy[z];
		if (nnx < 0 || nny < 0 || nnx >= n || nny >= n || map[nnx][nny] == '1') {
			return false;
		}
	}
	return true;
}

bool isMove(int x, int y, int dir) {
	//가로는 0,1  세로는 1, 0
	int n1 = 0, n2 = 1;
	if (dir == VERTI) { n1 = 1, n2 = 0; }
	int nx1 = x - n1, ny1 = y - n2, nx2 = x + n1, ny2 = y + n2;
	if (nx1 < 0 || ny1 < 0 || nx1 >= n || ny1 >= n) return false;
	if (nx2 < 0 || ny2 < 0 || nx2 >= n || ny2 >= n) return false;
	if (map[nx1][ny1] == '0' && map[nx2][ny2] == '0') return true;
	return false;
}

void bfs() {
	memset(check, -1, sizeof(check));
	int sx = B[1].first, sy = B[1].second;
	q.push({ sx,sy, sDir });
	check[sDir][sx][sy] = 0;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dir = q.front().dir;
		q.pop();
		if (x == ex && y == ey && dir == eDir) {
			ans = check[eDir][x][y];
			return;
		}
		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i], ny = y + dy[i], ndir = dir;
			if (i == 4) ndir = (dir + 1) % 2;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (map[nx][ny] == '1') continue;
			if (check[ndir][nx][ny] != -1) continue;
			if (i == 4) {

				if (isRoate(nx, ny)) {
					q.push({ nx,ny,ndir });
					check[ndir][nx][ny] = check[dir][x][y] + 1;
				}
			}
			else {
				if (map[nx][ny] == '0' && isMove(nx, ny, ndir)) {
					q.push({ nx,ny,ndir });
					check[ndir][nx][ny] = check[dir][x][y] + 1;
				}
			}
		}
	}
	return;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') { B.push_back({ i,j }); map[i][j] = '0'; }
			else if (map[i][j] == 'E') { E.push_back({ i,j }); map[i][j] = '0';}
		}
	}

	//hori, verti 판단.
	if (B[0].first == B[1].first) sDir = HORI;
	if (E[0].first == E[1].first) eDir = HORI;

	ex = E[1].first, ey = E[1].second;

	bfs();
	cout << ans;
}
