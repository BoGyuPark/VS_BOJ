#include<iostream>
using namespace std;
int n, m, x, y, k, dice[7], map[21][21], dir;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0, };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> map[i][j];

	while (k--) {
		cin >> dir;	dir--;
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			//dir이 E인경우
			int temp;
			if (dir == 0) {
				temp = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[6];
				dice[6] = dice[3];
				dice[3] = temp;
			}
			else if (dir == 1) {
				temp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[6] = dice[4];
				dice[4] = temp;
			}
			else if (dir == 2) {
				temp = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[6];
				dice[6] = dice[2];
				dice[2] = temp;
			}
			else {
				temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[6] = dice[5];
				dice[5] = temp;
			}
			if (map[nx][ny] == 0) {
				map[nx][ny] = dice[6];
			}
			else {
				dice[6] = map[nx][ny];
				map[nx][ny] = 0;
			}
			x = nx; y = ny;
			cout << dice[1] << '\n';
		}
	}
}