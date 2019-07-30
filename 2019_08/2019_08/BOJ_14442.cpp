/*BOJ 14442 벽 부수고 이동하기2*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, k;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int check[11][1001][1001];
char map[1001][1001];
typedef struct {
	int x, y, cnt;
}info;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)	cin >> map[i][j];
	queue<info> q;
	q.push({ 0,0,0 });
	check[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[cnt][nx][ny] != 0) continue;
			
			//벽 부수기 가능!
			if (cnt < k) {
				if (map[nx][ny] == '1') {
					check[cnt + 1][nx][ny] = check[cnt][x][y] + 1;
					q.push({ nx,ny,cnt + 1 });
				}
			}

			if (map[nx][ny] == '0') {
				check[cnt][nx][ny] = check[cnt][x][y] + 1;
				q.push({ nx, ny, cnt });
			}
		}
	}
	
	int ans = 2147483647;
	for (int i = 0; i <= k; i++) {
		if (check[i][n - 1][m - 1] != 0 && ans > check[i][n - 1][m - 1]) {
			ans = check[i][n - 1][m - 1];
		}
	}
	if (ans == 2147483647) ans = -1;
	cout << ans;
}