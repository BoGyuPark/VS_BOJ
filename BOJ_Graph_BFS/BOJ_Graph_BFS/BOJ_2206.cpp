#include<iostream>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
int n, m, maze[1001][1001], d[1001][1001][2];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			maze[i][j] = s[j] - '0';
		}
	}
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(0, 0, 0));
	d[0][0][0] = 1;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();	q.pop();
		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i]; ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (maze[nx][ny] == 0 && d[nx][ny][z] == 0) {
					d[nx][ny][z] = d[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
				if (z == 0 && maze[nx][ny] == 1 && d[nx][ny][z + 1] == 0) {
					d[nx][ny][z+1] = d[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z + 1));
				}
			}
		}
	}
	if (d[n - 1][m - 1][0] != 0 && d[n - 1][m - 1][1] != 0) {
		cout << min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
	}
	else if (d[n - 1][m - 1][0] != 0) {
		cout << d[n - 1][m - 1][0];
	}
	else if (d[n - 1][m - 1][1] != 0) {
		cout << d[n - 1][m - 1][1];
	}
	else
		cout << -1;
	return 0;
}