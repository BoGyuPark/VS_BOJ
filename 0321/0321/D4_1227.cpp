#include<iostream>
#include<queue>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int buf; cin >> buf;
		char a[101][101];
		int c[101][101] = { 0, };
		int sx, sy, ex, ey;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> a[i][j];
				if (a[i][j] == '2') {
					sx = i; sy = j;
				}
				else if (a[i][j] == '3') {
					ex = i; ey = j;
				}
			}
		}

		c[sx][sy] = true;
		queue<pair<int, int>> q;
		q.push({ sx,sy });
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100) continue;
				if (c[nx][ny] == true) continue;
				if (a[nx][ny] == '0' || a[nx][ny]=='3') {
					q.push({ nx,ny });
					c[nx][ny] = true;
				}
			}
		}
		cout << '#' << tc << ' ' << c[ex][ey]<< '\n';
	}
}