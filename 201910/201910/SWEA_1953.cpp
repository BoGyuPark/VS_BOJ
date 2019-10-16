#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T, tc, n, m, sx, sy, L, map[51][51], check[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int outPossible[] = { 0,15,3,12,9,10,6,5 };
int inPossible[] = { 0,15,3,12,6,5,9,10 };
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m >> sx >> sy >> L; L--;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cin >> map[i][j];
		}
		int ans = 1, cnt = 0;
		q.push({ sx,sy });
		check[sx][sy] = true;
		while (L--) {
			int Qsize = q.size();
			while (Qsize--) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					if (outPossible[map[x][y]] & (1 << i)) {
						int nx = x + dx[i], ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (check[nx][ny] || map[nx][ny] == 0) continue;
						if (inPossible[map[nx][ny]] & (1 << i)) {
							q.push({ nx,ny });
							check[nx][ny] = true;
							ans++;
						}
					}
				}
			}
		}
		while (!q.empty()) q.pop();
		
		cout << '#' << tc << ' ' << ans << '\n';
		memset(check, 0, sizeof(check));
	}
}