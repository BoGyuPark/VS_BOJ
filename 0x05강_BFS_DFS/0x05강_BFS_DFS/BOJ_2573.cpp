#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, c[301][301], a[301][301], temp[301][301], sum;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void OneMelt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > 0) {
				int x = i, y = j;
				int ice = 0;
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
						if (a[nx][ny] <= 0) ice++;
					}
				}
				temp[x][y] = (a[x][y] - ice < 0 ? 0 : a[x][y] - ice);
			}
		}
	}		
}
int bfs() {
	sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > 0 && c[i][j] == false) {
				q.push({ i,j }); c[i][j] = true;
				sum++;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second; q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
							if (a[nx][ny] > 0 && c[nx][ny] == false) {
								c[nx][ny] = true;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}
	}
	return sum;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> a[i][j];
	int ans = -1, cnt = 0;
	while (true) {
		OneMelt(); cnt++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) a[i][j] = temp[i][j];
		ans = bfs();
		if (ans >= 2) {
			cout << cnt;	break;
		}
		else if (ans == 0) {
			cout << 0;		break;
		}
		memset(temp, 0, sizeof(temp));
		memset(c, 0, sizeof(c));
	}
}