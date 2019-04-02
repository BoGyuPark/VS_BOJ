#include<iostream>
using namespace std;
int n, m, r, c, dir, a[51][51], check[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int overDirs[] = { 2,3,0,1 };
int visited[51][51][4];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> r >> c >> dir;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	int cnt = 0;

	while (true) {
		if (a[r][c] == 0 && check[r][c] == false) {
			check[r][c] = true;
			cnt++;
		}
		//네 방향 모두 청소가 이미 되어있거나 벽인 경우
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			int nx = r + dx[i], ny = c + dy[i];
			if (a[nx][ny] == 1 || check[nx][ny] == true) flag++;
		}

		if (flag == 4) {
			//바라보고있는 방향의 반대로 이동 가능한가?
			//반복되기전 방향으로 바꾼다.
			if (a[r + dx[overDirs[dir]]][c + dy[overDirs[dir]]] == 0) {
				r += dx[overDirs[dir]];
				c += dy[overDirs[dir]];
				continue;
			}
			//작동을 멈춘다.
			else break;
		}
		else {
			dir = (dir + 3) % 4;
			int nx = r + dx[dir], ny = c + dy[dir];
			if (a[nx][ny] == 0 && check[nx][ny] == false) {
				r = nx; c = ny;
				continue;
			}
		}
	}
	cout << cnt;
}