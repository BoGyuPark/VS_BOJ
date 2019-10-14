/*BOJ 2468 안전 영역*/
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n, map[101][101], check[101][101], maxi, ans = 1;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;
void bfs(int height) {
	memset(check, 0, sizeof(check));
	//flood
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] <= height) check[i][j] = true;
		}
	}
	int safeCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) continue;
			q.push({ i,j });
			safeCnt++;
			check[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (check[nx][ny]) continue;
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	ans = max(ans, safeCnt);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			maxi = max(maxi, map[i][j]);
		}
	}

	for (int i = 1; i <= maxi; i++) bfs(i);
	cout << ans;
}