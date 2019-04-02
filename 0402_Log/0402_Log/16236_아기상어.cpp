#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<tuple>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, a[21][21], sx, sy, SharkSize = 2;
vector<tuple<int, int, int>> foodList;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) { sx = i; sy = j; a[i][j] = 0; }
		}
	}
	int cnt = 0, eatCnt = 0;
	while (true) {
		//먹이 리스트를 만든다.
		queue<pair<int, int>> q;
		q.push({ sx, sy });
		int c[21][21];
		memset(c, -1, sizeof(c));
		c[sx][sy] = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (a[nx][ny] > SharkSize) continue;
				if (c[nx][ny] != -1) continue;
				q.push({ nx,ny });
				c[nx][ny] = c[x][y] + 1;
				if (a[nx][ny] < SharkSize && a[nx][ny]> 0)
					foodList.push_back({ c[nx][ny],nx,ny });
			}
		}
		if (foodList.size() == 0) break;
		sort(foodList.begin(), foodList.end());
		int dist, row, col;
		tie(dist, row, col) = foodList[0];
		cnt += dist;
		sx = row;
		sy = col;
		a[sx][sy] = 0;
		eatCnt++;
		if (eatCnt == SharkSize) {
			SharkSize++;
			eatCnt = 0;
		}
		foodList.clear();
		//cout << cnt << '\n';
	}
	cout << cnt;
}
