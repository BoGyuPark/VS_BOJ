/*BOJ 10026 적록색약*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, check[101][101];
char a[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int bfs() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == true) continue;
			cnt++;
			char target = a[i][j];
			queue<pair<int, int>> q;
			q.push({ i,j });
			check[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (check[nx][ny] == true) continue;
					if (a[nx][ny] == target) {
						q.push({ nx,ny });
						check[nx][ny] = true;
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int sector_cnt = 0;
	sector_cnt = bfs();
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'G') a[i][j] = 'R';
		}
	}
	int cnt = bfs();
	cout << sector_cnt << " " << cnt;
}