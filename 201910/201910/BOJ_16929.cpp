/*BOJ 16929 Two Dots*/
#include<iostream>
#include<cstring>
using namespace std;
int n, m, check[51][51], sx, sy, flag;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int transDir[] = { 1,0,3,2 };
char map[51][51];
void go(int x, int y, int possibleDir,char target) {
	if (flag) return;
	for (int i = 0; i < 4; i++) {
		if (possibleDir & (1 << i)) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] != target) continue;
			
			//exit
			if (nx == sx && ny == sy) {
				flag = true;
				return;
			}
			if (check[nx][ny]) continue;
			check[nx][ny] = true;
			go(nx, ny, (15 - (1 << transDir[i])), target);
		}
	}
}
void search() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(check, 0, sizeof(check));
			sx = i, sy = j;
			flag = false;
			go(i, j, 15, map[i][j]);
			if (flag) return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	search();
	cout << (flag ==true ? "Yes" : "No");
}