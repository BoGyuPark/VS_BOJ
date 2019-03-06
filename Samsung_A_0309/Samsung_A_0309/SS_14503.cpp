#include<iostream>
using namespace std;
int n, m, rx, ry, dir, a[51][51], clean = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ro[] = { 3,0,1,2 };
int ba[] = { 2,3,0,1 };
int main() {
	cin >> n >> m >> rx >> ry >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}
	a[rx][ry] = 2;
	while (true) {
		bool found = false;
		for (int i = 0; i < 4; i++) {
			//현재 방향의 왼쪽 방향을 탐색
			int nx = rx + dx[ro[dir]], ny = ry + dy[ro[dir]];
			if (a[nx][ny] == 0) {
				//방향으로 회전 후 그 방향으로 전진.
				dir = ro[dir];
				a[nx][ny] = 2;
				rx = nx; ry = ny;
				found = true;
				break;
			}
			else dir = ro[dir];
		}
		//네 방향 모두 청소가 이미 되어있거나 벽인 경우
		if (!found) {
			int nx = rx + dx[ba[dir]], ny = ry + dy[ba[dir]];
			//후진 가능
			if (a[nx][ny] != 1) { rx = nx; ry = ny; }
			//작동을 멈출 때
			else break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (a[i][j] == 2) clean++;
	}
	cout << clean;
}