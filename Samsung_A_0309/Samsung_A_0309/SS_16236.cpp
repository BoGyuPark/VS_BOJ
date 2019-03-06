#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
int a[21][21], n, sx, sy, sharkSize, eatcnt = 0, temp;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<tuple<int, int, int>> eq;
int bfs(int i, int j) {
	//           거리, x, y
	vector<tuple<int, int, int>> eatable;
	int c[21][21];
	memset(c, -1, sizeof(c));
	c[i][j] = 0;
	queue<pair<int, int>> q;
	q.push({ i,j });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z], ny = y + dy[z];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (c[nx][ny] != -1) continue;
			if (a[nx][ny] <= sharkSize) {
				if (a[nx][ny] != 0 && a[nx][ny] < sharkSize) {
					eatable.push_back({ c[x][y] + 1,nx,ny });
				}
				c[nx][ny] = c[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	//나의 다음 먹이감들을 큐에 넣는다.
	sort(eatable.begin(), eatable.end());
	if (eatable.size() == 0) return -1;
	eq.push(eatable[0]);
	a[get<1>(eatable[0])][get<2>(eatable[0])] = 0;
	if (eq.size() == 0) return -1;
	else return c[get<1>(eq.front())][get<2>(eq.front())];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				sx = i, sy = j;
				a[i][j] = 0;
			}
		}
	}
	sharkSize = 2;
	int ans = 0;
	eq.push({ 0,sx,sy });

	while (true) {
		if (eatcnt == sharkSize) {
			sharkSize++;
			eatcnt = 0;
		}
		int value, x, y;
		tie(value, x, y) = eq.front();
		eq.pop();
		temp = bfs(x, y);
		if (temp == -1) break;
		if (temp > 0) {
			ans += temp;
			eatcnt++;
		}
	}
	cout << ans;
}