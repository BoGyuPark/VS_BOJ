/*BOJ 16509 장군*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int r1, r2, c1, c2, ans;
int map[10][9], check[10][9];
queue<pair<int, int>> q;
//           상 우 하 좌
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int transDir[4][2] = { {0,1},{1,2},{3,2}, {0,3} };
int ddx[] = { -1,-1,1,1 };
int ddy[] = { -1,1,1,-1 };
bool checkBoundary(int x, int y) {
	return (x < 0 || y < 0 || x >= 10 || y >= 9);
}

bool isWall(int x, int y, int dir) {
	int nx = x + ddx[dir], ny = y + ddy[dir];
	if (checkBoundary(nx, ny)) return false;
	if (nx == r2 && ny == c2) return false;

	nx += ddx[dir], ny += ddy[dir];

	if (checkBoundary(nx, ny)) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(check, -1, sizeof(check));
	cin >> r1 >> c1 >> r2 >> c2;
	q.push({ r1,c1 });
	check[r1][c1] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (x == r2 && y == c2) {
			ans = check[x][y];
			break;
		}

		//네방향 체크
		for (int i = 0; i < 4; i++) {
			//상하좌우에서 양쪽 대각선 체크
			int nx = x + dx[i], ny = y + dy[i];
			if (checkBoundary(nx,ny)) continue;
			if (nx == r2 && ny == c2) continue;

			int nnx = nx + ddx[transDir[i][0]] * 2;
			int nny = ny + ddy[transDir[i][0]] * 2;
			if (check[nnx][nny] == -1) {
				if (isWall(nx, ny, transDir[i][0])) {
					q.push({ nnx,nny });
					check[nnx][nny] = check[x][y] + 1;
				}
			}

			nnx = nx + ddx[transDir[i][1]] * 2;
			nny = ny + ddy[transDir[i][1]] * 2;
			if (check[nnx][nny] == -1) {
				if (isWall(nx, ny, transDir[i][1])) {
					q.push({ nnx,nny });
					check[nnx][nny] = check[x][y] + 1;
				}
			}
		}
	}
	cout << ans;
}