#include<iostream>
#include<string>
#include<deque>
using namespace std;
int n, m, maze[101][101], c[101][101], d[101][101];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int main() {
	cin >> n >> m;
	string s;
	//m:За, n:ї­
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			maze[i][j] = s[j] - '0';
		}
	}
	deque<pair<int,int> > dq;
	c[0][0] = true;
	d[0][0] = 0;
	dq.push_back(make_pair(0, 0));
	while (!dq.empty()) {
		int x, y;
		x = dq.front().first; y = dq.front().second;
		dq.pop_front();
		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i]; ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (c[nx][ny] == false) {
					if (maze[nx][ny] == 0) {
						dq.push_front(make_pair(nx, ny));
						c[nx][ny] = true;
						d[nx][ny] = d[x][y];
					}
					else {
						dq.push_back(make_pair(nx, ny));
						c[nx][ny] = true;
						d[nx][ny] = d[x][y] + 1;
					}
				}
			}
		}
	}
	cout << d[m - 1][n - 1];
	return 0;
}