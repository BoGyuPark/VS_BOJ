#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, cpy[51][51], c[51][51];
int sel[11], check[250], emptyCnt, ans;
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
int virusSize;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int bfs() {
	int MaxCnt = 0, cnt = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (cnt == emptyCnt) return MaxCnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (c[nx][ny] != -1) continue;
			if (cpy[nx][ny] != 1) {
				if (cpy[nx][ny] == 0) cnt++;
				q.push({ nx,ny });
				c[nx][ny] = c[x][y] + 1;
				if (MaxCnt < c[nx][ny]) MaxCnt = c[nx][ny];
			}
		}
	}
	return -1;
}
void dfs(int index, int start) {
	if (index == m) {
		memset(c, -1, sizeof(c));
		for (int j = 0; j < m; j++) {
			q.push({ virus[sel[j]].first, virus[sel[j]].second });
			c[virus[sel[j]].first][virus[sel[j]].second] = 0;
		}
		int temp = bfs();
		while (!q.empty()) q.pop();
		if (temp >= 0) {
			if (ans > temp) ans = temp;
		}
		return;
	}
	for (int i = start; i < virusSize; i++) {
		if (check[i] == true) continue;
		check[i] = true;
		sel[index] = i;
		dfs(index + 1, i);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cpy[i][j];
			if (cpy[i][j] == 2) virus.push_back({ i,j });
			else if (cpy[i][j] == 0) emptyCnt++;
		}
	}
	ans = 2147483647;
	virusSize = virus.size();
	dfs(0, 0);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}