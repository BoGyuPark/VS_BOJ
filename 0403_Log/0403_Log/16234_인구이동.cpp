#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, l, r, a[51][51], dirInfo[51][51];
int c[51][51];
//          우 좌 하 상
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q, temp;
void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] == true) continue;
			if (dirInfo[i][j] == 0) continue;
			q.push({ i,j });
			temp.push({ i,j });
			c[i][j] = true;
			int cnt = 1, sum = a[i][j];
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					if (dirInfo[x][y] & (1 << z)) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (c[nx][ny] == true) continue;
						sum += a[nx][ny];
						cnt++;
						q.push({ nx,ny });
						temp.push({ nx,ny });
						c[nx][ny] = true;
					}
				}
			}
			while (!temp.empty()) {
				a[temp.front().first][temp.front().second] = sum / cnt;
				temp.pop();
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

	int ans = 0, found = false;
	while (true) {
		//각 칸의 갈수 있는 방향을 입력한다.
		found = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z], ny = j + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					int dif = abs(a[i][j] - a[nx][ny]);
					if (l <= dif && dif <= r) {
						dirInfo[i][j] += (1 << z);
						found++;
					}
				}
			}
		}
		bfs();
		memset(c, 0, sizeof(c));
		memset(dirInfo, 0, sizeof(dirInfo));
		if (found == 0) break;

		ans++;
	}
	cout << ans;
}