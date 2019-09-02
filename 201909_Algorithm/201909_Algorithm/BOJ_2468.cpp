/*BOJ 2468 안전 영역*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n, map[101][101], miniH = 2147483647, maxH = -2147483647, ans;
int check[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

void flood(int h) {
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < h) check[i][j] = true;
		}
	}
}

void findCnt() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) continue;
			cnt++;
			q.push({ i,j });
			check[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (check[nx][ny]) continue;
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}
	}
	if (cnt > ans) ans = cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			miniH = min(miniH, map[i][j]);
			maxH = max(maxH, map[i][j]);
		}
	}

	for (int i = miniH; i <= maxH; i++) {
		flood(i);
		findCnt();
	}
	cout << ans;
}