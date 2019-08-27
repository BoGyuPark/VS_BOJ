/*BOJ 14499 주사위 굴리기*/
#include<iostream>
using namespace std;
int n, m, k, sx, sy, map[21][21], dir;
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
int dice[7], temp[7];
int trans[5][7] = {
	{0,0,0,0,0,0,0},
	{0,4,2,1,6,5,3},
	{0,3,2,6,1,5,4},
	{0,5,1,3,4,6,2},
	{0,2,6,3,4,1,5}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> sx >> sy >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}

	for (int i = 0; i < k; i++) {
		cin >> dir;
		int nx = sx + dx[dir], ny = sy + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		for (int j = 1; j < 7; j++) temp[j] = dice[trans[dir][j]];
		
		cout << temp[1] << '\n';
		if (map[nx][ny] == 0) map[nx][ny] = temp[6];
		else {
			temp[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		sx = nx, sy = ny;
		for (int j = 1; j < 7; j++) dice[j] = temp[j];
	}
}