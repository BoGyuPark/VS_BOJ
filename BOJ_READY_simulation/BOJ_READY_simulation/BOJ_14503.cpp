#include<iostream>
using namespace std;
int n, m, r, c, d, a[51][51], ans = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int main() {
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];
	while (true) {
		if (a[r][c] == 0)	a[r][c] = -1;
		//네방향이 벽이거나 청소한 경우
		if (a[r - 1][c] != 0 && a[r][c + 1] != 0 && a[r + 1][c] != 0 && a[r][c - 1] != 0) {
			if (a[r - dx[d]][c - dy[d]] != 1) {
				r = r - dx[d]; 
				c = c - dy[d];
			}
			else break;
		}
		else {
			//각 방향을 탐색
			d = (d + 3) % 4;
			if (a[r + dx[d]][c + dy[d]] == 0) {
				r = r + dx[d];
				c = c + dy[d];
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (a[i][j] == -1) ans++;
	cout << ans;
}