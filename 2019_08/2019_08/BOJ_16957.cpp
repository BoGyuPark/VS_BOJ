/*BOJ 16957 체스판 위의 공*/
#include<iostream>
#include<queue>
using namespace std;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int n, m, map[501][501], cnt[501][501];
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (cnt[x][y] != 0) {
			cnt[x][y]++;
			continue;
		}
		int count = 0, minNum = 2147483647, nnx, nny;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] <= map[x][y]) {
				count++;
				if (minNum > map[nx][ny]) {
					nnx = nx, nny = ny;
					minNum = map[nx][ny];
				}
			}
		}
		//이동을 멈추고 해당 좌표에 카운트 증가.
		if (count == 0) cnt[x][y]++;
		//가장 작은 정수가 있는 칸으로 이동
		else {
			if (cnt[nnx][nny] == 0) {
				q.push({ nnx,nny });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			q.push({ i,j });
		}

	bfs();	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << cnt[i][j] << ' ';
		cout << '\n';
	}
}