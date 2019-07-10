#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, sx, sy, f_sx, f_sy;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ji_dist[1003][1003], fire_dist[1003][1003];
char a[1003][1003];
queue<pair<int, int>> q;

void bfs() {
	q.push({ sx,sy });
	ji_dist[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n+2 || ny >=m+2) continue;
			if (ji_dist[nx][ny] != -1) continue;
			if (a[nx][ny] == '.') {
				if((fire_dist[nx][ny] > ji_dist[x][y] + 1)||fire_dist[nx][ny]==-1){
					q.push({ nx,ny });
					ji_dist[nx][ny] = ji_dist[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	memset(fire_dist, -1, sizeof(fire_dist));
	memset(ji_dist, -1, sizeof(ji_dist));
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'J') {
				sx = i, sy = j;
			}
			else if (a[i][j] == 'F') {
				q.push({ i,j });
				fire_dist[i][j] = 0;
			}
		}
	}

	//바깥 외벽 만들기
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
				a[i][j] = '.';
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx >= n+1 || ny >=m+1 ) continue;
			if (fire_dist[nx][ny] != -1) continue;
			if (a[nx][ny] == '.') {
				q.push({ nx,ny });
				fire_dist[nx][ny] = fire_dist[x][y] + 1;
			}
		}
	}
	bfs();


	int ans = 2147483647;
	//바깥 외벽 만들기
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
				if (ans > ji_dist[i][j] && ji_dist[i][j] != -1) ans = ji_dist[i][j];
			}
		}
	}
	if (ans == 2147483647) cout << "IMPOSSIBLE";
	else cout << ans;
}