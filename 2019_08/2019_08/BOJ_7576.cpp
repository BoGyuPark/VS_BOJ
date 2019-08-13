/*BOJ 7576 ≈‰∏∂≈‰*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, k, ans, flag;
int map[1001][1001], check[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	memset(check, -1, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
				check[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (check[nx][ny] != -1) continue;
			if (map[nx][ny] == 0) {
				q.push({ nx,ny });
				check[nx][ny] = check[x][y] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1 && check[i][j] == -1) continue;
			if (check[i][j] == -1) flag = true;
			else {
				if (ans < check[i][j]) ans = check[i][j];
			}
		}
	}
	if (flag) ans = -1;
	cout << ans;
}