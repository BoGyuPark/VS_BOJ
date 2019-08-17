/*BOJ 3987 보이저 1호*/
#include<iostream>
#include<cstring>
using namespace std;
//          U R D L
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int slash[] = { 1,0,3,2 };
int reSlash[] = { 3,2,1,0 };
int n, m, sx, sy, ans, tempDir;
char ansDir[] = "URDL";
char map[501][501];
int check[501][501];
int simulate(int dir) {
	memset(check, -1, sizeof(check));
	int cnt = 1;
	int d = dir;
	int x = sx, y = sy;
	check[x][y] = dir;
	while (true) {
		if (map[x][y] == '/') d = slash[d];
		else if (map[x][y] == '\\') d = reSlash[d];
		
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
		if (map[nx][ny] == 'C') break;
		
		//무한 루프인 경우를 체크하자 (좌표에 방향을 저장)
		if (check[nx][ny] == d) return -1;
		check[nx][ny] = d;
		x = nx, y = ny;
		cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	cin >> sx >> sy;
	sx--; sy--;
	for (int i = 0; i < 4; i++) {
		int temp = simulate(i);
		if (temp == -1) {
			cout << ansDir[i] << '\n' << "Voyager";
			return 0;
		}
		else {
			if (temp > ans) {
				ans = temp;
				tempDir = i;
			}
		}
	}
	cout << ansDir[tempDir] << '\n' << ans;
}