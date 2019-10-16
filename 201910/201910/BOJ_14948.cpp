/*BOJ 14948 군대탈출하기*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, map[101][101], check[2][101][101], ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> level;
struct info {
	int x, y, cnt;
};
queue<info> q;
bool search(int k) {
	if (map[0][0] > k) return false;
	memset(check, 0, sizeof(check));
	q.push({ 0,0,0 });
	check[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] <= k && check[cnt][nx][ny] == 0) {
				
				check[cnt][nx][ny] = true;
				q.push({ nx,ny,cnt });
				if (nx == n - 1 && ny == m - 1) {
					while (!q.empty()) q.pop();
				}
			}
			else {
				if (cnt == 0 && check[cnt + 1][nx][ny] == 0) {
					if (nx == n - 1 && ny == m - 1) continue;
					check[cnt + 1][nx][ny] = true;
					int nnx = nx + dx[i], nny = ny + dy[i];
					if (nnx < 0 || nny < 0 || nnx >= n || nny >= m) continue;
					if (map[nnx][nny] <= k) {
						check[cnt + 1][nnx][nny] = true;
						q.push({ nnx,nny,cnt + 1 });
					}
				}
			}
		}
	}
	if (check[0][n - 1][m - 1] + check[1][n - 1][m - 1] > 0) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			level.push_back(map[i][j]);
		}
	}
	sort(level.begin(), level.end());
	level.erase(unique(level.begin(), level.end()), level.end());
	for (int i = 0; i < level.size(); i++) {
		if (search(level[i])) {
			cout << level[i];
			break;
		}
	}
}