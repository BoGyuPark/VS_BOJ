/*BOJ 1261 ¾Ë°í½ºÆÌ*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, ans, check[101][101];
char map[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
struct info {
	int x, y, cnt;
};
struct cmp {
	bool operator()(info a, info b) {
		return a.cnt > b.cnt;
	}
};
priority_queue<info, vector<info>, cmp> q;
void bfs() {
	q.push({ 0,0,0 });
	check[0][0] = 0;
	while (!q.empty()) {
		int x = q.top().x, y = q.top().y, cnt = q.top().cnt;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (nx == n - 1 && ny == m - 1) {
				ans = cnt;
				return;
			}
			if (map[nx][ny] == '1') {
				if (check[nx][ny] == -1) {
					q.push({ nx,ny,cnt + 1 });
					check[nx][ny] = cnt + 1;
				}	
			}
			else {
				if (check[nx][ny] == -1) {
					q.push({ nx,ny,cnt });
					check[nx][ny] = cnt;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) cin >> map[i][j];
	memset(check, -1, sizeof(check));
	bfs();
	cout << ans;
}