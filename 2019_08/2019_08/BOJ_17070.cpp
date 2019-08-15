#include<iostream>
using namespace std;
int map[17][17], n, cnt; 
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };
// dir 0 : 가로, 1: 세로, 2: 대각선
void go(int x, int y, int dir) {

	if (x == n - 1 && y == n - 1) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (dir == 0 && i == 1) continue;
		if (dir == 1 && i == 0) continue;
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map[nx][ny] == 1) continue;

		//대각선인 경우 4칸 모두 확인
		if (i == 2) {
			if (map[nx][ny - 1] != 0 || map[nx - 1][ny] != 0) continue;
			go(nx, ny, i);
		}
		else 
			go(nx, ny, i);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> map[i][j];
	go(0, 1, 0);
	cout << cnt;
}