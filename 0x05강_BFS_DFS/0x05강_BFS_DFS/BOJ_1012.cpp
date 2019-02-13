#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int t, n, m, i, j, k, xpos, ypos, cnt;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		int c[51][51] = { 0, }, a[51][51] = { 0, };
		for (i = 0; i < k; i++) { 
			cin >> xpos >> ypos;
			a[ypos][xpos] = 1;
		}
		cnt = 0;
		queue<pair<int, int>> q;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (a[i][j] == 1 && c[i][j] == false) {
					cnt++;
					q.push(make_pair(i, j));
					c[i][j] = true;
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second; q.pop();
						for (int z = 0; z < 4; z++) {
							int nx = x + dx[z], ny = y + dy[z];
							if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
								if (a[nx][ny] == 1 && c[nx][ny] == false) {
									c[nx][ny] = true;
									q.push(make_pair(nx, ny));
								}
							}
						}
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}
