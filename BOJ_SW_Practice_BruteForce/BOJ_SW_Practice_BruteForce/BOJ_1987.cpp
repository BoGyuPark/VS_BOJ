#include<iostream>
using namespace std;
int r, c, check[200], ans = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
char map[21][21];
void dfs(int x, int y, int cnt) {
	if (cnt > ans) ans = cnt;
	for (int i = 0; i < 4; i++) {
		int nx, ny;
		nx = x + dx[i]; ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (check[map[nx][ny]] == false) {
				check[map[nx][ny]] = true;
				dfs(nx, ny, cnt + 1);
				check[map[nx][ny]] = false;
			}
		}
	}
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)		cin >> map[i];
	check[map[0][0]] = true;
	dfs(0, 0, 1);
	cout << ans;
}