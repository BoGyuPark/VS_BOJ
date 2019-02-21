#include<iostream>
#include<queue>
using namespace std;
int n, m, c[251][251], ts = 0, tw = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char a[251][251];
void bfs(int i, int j) {
	int scnt = 0, wcnt = 0;
	queue<pair<int, int>> q;
	q.push({ i,j });
	c[i][j] = true;
	if (a[i][j] == 'v') wcnt++;
	else scnt++;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z], ny = y + dy[z];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (c[nx][ny] == false && a[nx][ny] != '#') {
					c[nx][ny] = true;
					q.push({ nx,ny });
					if (a[nx][ny] == 'v') wcnt++;
					else if (a[nx][ny] == 'o') scnt++;
				}
			}
		}
	}
	if (wcnt >= scnt) scnt = 0;
	else wcnt = 0;
	ts += scnt; tw += wcnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'v' || a[i][j] == 'o') {
				if (c[i][j] == false) bfs(i, j);
			}
		}
	}
	cout << ts << ' ' << tw;
}