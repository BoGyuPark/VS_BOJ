//BOJ_16234 인구이동
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, L, R, map[51][51], c[51][51];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
bool bfs(int row, int col) {
	v.push_back({ row,col });
	q.push({ row,col });
	c[row][col] = true;
	int cnt = 1, sum = map[row][col];
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (c[nx][ny]) continue;
			int dif = abs(map[x][y] - map[nx][ny]);
			if (L <= dif && dif <= R) {
				cnt++;
				sum += map[nx][ny];
				q.push({ nx,ny });
				c[nx][ny] = true;
				v.push_back({ nx,ny });
			}
		}
	}

	for (auto i : v) map[i.first][i.second] = sum / cnt;
	v.clear();
	if (cnt >= 2) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> L >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (true) {
		int flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!c[i][j]) {
					flag += bfs(i, j);
				}
			}
		}
		if (flag == 0) break;
		memset(c, 0, sizeof(c));
		ans++;
	}
	cout << ans;
}