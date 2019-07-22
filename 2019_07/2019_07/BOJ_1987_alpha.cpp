/*BOJ 1987 ¾ËÆÄºª_³²±ØÅ»Ãâ*/
#include<iostream>
using namespace std;
int n, m, ans = 1;
int alpha[30];
char map[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void go(int x, int y, int dist) {
	if (ans < dist) ans = dist;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (alpha[map[nx][ny] - 'A']) continue;
		alpha[map[nx][ny] - 'A'] = true;
		go(nx, ny, dist + 1);
		alpha[map[nx][ny] - 'A'] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	alpha[map[0][0] - 'A'] = true;
	go(0, 0, 1);
	cout << ans;
}