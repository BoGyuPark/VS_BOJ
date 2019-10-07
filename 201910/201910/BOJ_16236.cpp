//BOJ_ 16236 아기상어
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, map[21][21], c[21][21], shirkSize = 2, ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;
struct info {
	int dist, x, y;
};
struct cmp {
	bool operator()(info a, info b) {
		if (a.dist > b.dist) return true;
		else if (a.dist == b.dist) {
			if (a.x > b.x) return true;
			else if (a.x == b.x) {
				if (a.y > b.y) return true;
				else return false;
			}
			else return false;
		}
		else {
			return false;
		}
	}
};
priority_queue<info, vector<info>, cmp> pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	memset(c, -1, sizeof(c));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				q.push({ i,j });
				c[i][j] = 0;
				map[i][j] = 0;
			}
		}
	}
	
	int cnt = 0;
	while (true) {
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (c[nx][ny] != -1) continue;
				if (shirkSize < map[nx][ny]) continue;
				q.push({ nx,ny });
				c[nx][ny] = c[x][y] + 1;
				if (map[nx][ny] != 0 && map[nx][ny] < shirkSize ) {
					pq.push({ c[nx][ny],nx,ny });
				}
			}
		}
		if (pq.empty()) break;
		memset(c, -1, sizeof(c));
		ans += pq.top().dist;
		q.push({ pq.top().x,pq.top().y });
		c[pq.top().x][pq.top().y] = 0;
		map[pq.top().x][pq.top().y] = 0;
		while (!pq.empty()) pq.pop();
		cnt++;
		if (cnt == shirkSize) {
			shirkSize++;
			cnt = 0;
		}
	}
	cout << ans;
}