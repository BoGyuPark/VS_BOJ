#include<iostream>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int TransDirs[4][6] = { 
	{3,1,0,5,4,2},
	{2,1,5,0,4,3},
	{4,0,2,3,5,1},
	{1,5,2,3,0,4},
};
int n, m, x, y, k, a[21][21], dirs[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int i = 0; i < k; i++) {
		int t; cin >> t;
		dirs[i] = t - 1;
	}
	int dice[6] = { 0, };
	for (int i = 0; i < k; i++) {
		int nx = x + dx[dirs[i]], ny = y + dy[dirs[i]];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		//주사위 굴리기
		int temp[6] = { 0, };
		for (int j = 0; j < 6; j++) temp[j] = dice[TransDirs[dirs[i]][j]];
		for (int j = 0; j < 6; j++) dice[j] = temp[j];
		
		if (a[nx][ny] == 0) a[nx][ny] = dice[5];
		else {
			dice[5] = a[nx][ny];
			a[nx][ny] = 0;
		}
		cout << dice[0] << '\n';
		x += dx[dirs[i]];
		y += dy[dirs[i]];
	}
}