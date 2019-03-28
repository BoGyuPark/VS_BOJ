#include<iostream>
using namespace std;
int tc, T, a[4][4];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int cnt = 0;
char overlap[10000000];
void dfs(int index, int x, int y, int num) {
	if (index == 7) {
		if (overlap[num] != T) {
			cnt++; overlap[num] = T;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
		dfs(index + 1, nx, ny, num * 10 + a[nx][ny]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	for (T = 1; T <= tc; T++) {
		cnt = 0;
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> a[i][j];
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++) {
				dfs(1, i, j, a[i][j]);
			}
		cout << '#' << T << ' ' << cnt << '\n';
	}
}