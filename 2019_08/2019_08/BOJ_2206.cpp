/*BOJ 2206 벽 부수고 이동하기*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, check[2][1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char map[1001][1001];
typedef struct {
	int x, y, cnt;
}info;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) cin >> map[i][j];
		
	queue<info> q;
	q.push({ 0,0,0 });
	check[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cur_cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (cur_cnt < 1) {
				if (map[nx][ny] == '1') {
					if (check[cur_cnt][nx][ny] == 0) {
						check[cur_cnt + 1 ][nx][ny] = check[cur_cnt][x][y] + 1;
						q.push({ nx,ny,cur_cnt + 1 });
					}
				}
			}
			if (map[nx][ny] == '0') {
				if (check[cur_cnt][nx][ny] == 0) {
					check[cur_cnt][nx][ny] = check[cur_cnt][x][y] + 1;
					q.push({ nx,ny,cur_cnt });
				}
			}
		}
	}

	int ans = 2147483647;
	if (check[0][n - 1][m - 1] != 0) ans = min(ans, check[0][n - 1][m - 1]);
	if (check[1][n - 1][m - 1] != 0) ans = min(ans, check[1][n - 1][m - 1]);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}