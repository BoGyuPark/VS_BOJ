#include<iostream>
#include<queue>
using namespace std;
int n, l, r, a[51][51], cnt = 0, opencnt;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void bfs(int i, int j, int c[][51], int d[][51]) {
	if (d[i][j] == 0) return;
	int sum = a[i][j], t = a[i][j];
	c[i][j] = true;
	queue<pair<int, int>> q, moved;
	q.push({ i,j });
	moved.push({ i,j });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int z = 0; z < 4; z++) {
			if (d[x][y] & (1 << z)) {
				int nx = x + dx[z], ny = y + dy[z];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (c[nx][ny] == true) continue;
				c[nx][ny] = true;
				q.push({ nx,ny });
				moved.push({ nx,ny });
				sum += a[nx][ny];
			}
		}
	}
	//나눈 값을 연합인 좌표에 다시 저장
	sum /= moved.size();
	while (!moved.empty()) {
		int x = moved.front().first, y = moved.front().second;
		moved.pop();
		a[x][y] = sum;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

	while (true) {
		opencnt = 0;
		//국경을 open
		int c[51][51] = { 0, }, d[51][51] = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = i, y = j;
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z], ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					int dif = a[x][y] - a[nx][ny];
					if (dif < 0) dif = -dif;
					//국경선 open가능, 국경선에 해당하는 방향을 저장.
					if (dif >= l && dif <= r) {
						d[x][y] += (1 << z);
						opencnt++;
					}
				}
			}
		}
		if (opencnt == 0) break;
		cnt++;
		//bfs 돌린다.
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) if (c[i][j] == false) bfs(i, j, c, d);
	}
	cout << cnt;
}