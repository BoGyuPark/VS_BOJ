/*BOJ 16236 아기 상어*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, sx, sy, check[20][20], map[20][20], ss, eatCnt, ans;
typedef struct {
	int dist, x, y;
}info;

struct cmp{
	bool operator()(info a, info b) {
		if (a.dist == b.dist) {
			if (a.x == b.x) {
				return a.y > b.y;
			}
			else
				return a.x > b.x;
		}
		else 
			return a.dist > b.dist;
	}
};
priority_queue<info,vector<info>,cmp> pq;
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sx = i, sy = j;
				map[i][j] = 0;
			}
		}
	}
	ss = 2;
	while (true) {

		memset(check, -1, sizeof(check));
		q.push({ sx,sy });
		check[sx][sy] = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (check[nx][ny] != -1) continue;
				if (map[nx][ny] <= ss) {
					check[nx][ny] = check[x][y] + 1;
					q.push({ nx,ny });

					if (map[nx][ny]!=0 && map[nx][ny] < ss) {
						pq.push({ check[nx][ny], nx, ny });
					}

				}
			}
		}

		if (pq.empty()) break;
		ans += pq.top().dist;
		sx = pq.top().x;
		sy = pq.top().y;
		map[sx][sy] = 0;
		eatCnt++;
		if (eatCnt == ss) {
			ss++;
			eatCnt = 0;
		}
		while (!pq.empty()) pq.pop();
	}
	cout << ans;
}