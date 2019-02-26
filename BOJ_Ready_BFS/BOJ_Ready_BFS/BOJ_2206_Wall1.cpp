#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int a[1001][1001], d[2][1001][1001], n, m;
typedef struct info {
	int ix, iy, ir;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
	}
	queue<info> q;
	q.push({ 0,0,0 });
	d[0][0][0] =  1;
	while (!q.empty()) {
		int x = q.front().ix, y = q.front().iy, cnt = q.front().ir;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			//맵이 빈칸이고 벽을한번도 안부신 경우
			if (a[nx][ny] == 0 && d[cnt][nx][ny] == 0) {
				d[cnt][nx][ny] = d[cnt][x][y] + 1;
				q.push({ nx,ny,cnt });
			}
			//벽을부순횟수가 0이고 맵이 벽이고 이전에 벽을 부순적이 없고 
			if (cnt == 0 && a[nx][ny] == 1 && d[cnt + 1][nx][ny] == 0) {
				q.push({ nx,ny,cnt + 1 });
				d[cnt+1][nx][ny] = d[cnt][x][y] + 1;
			}
		}
	}
	if (d[0][n - 1][m - 1] == 0 && d[1][n - 1][m - 1] == 0) cout << -1;
	else if (d[0][n - 1][m - 1] == 0) cout << d[1][n - 1][m - 1];
	else if (d[1][n - 1][m - 1] == 0) cout << d[0][n - 1][m - 1];
	else cout << min(d[0][n - 1][m - 1] , d[1][n - 1][m - 1]);
}