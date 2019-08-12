/*BOJ 안전영역 2468*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, map[101][101], check[101][101];
int MAX = -1, ans = 1;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void bfs(int pivot) {
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < pivot) {
				check[i][j] = -1;
			}
		}
	}
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				area++;
				q.push({ i,j });
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i], ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (check[nx][ny] == 0) {
							q.push({ nx,ny });
							check[nx][ny] = true;
						}
					}
				}
			}
		}
	}
	if (area > ans) ans = area;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] > MAX) {
				MAX = map[i][j];
			}
		}
	}
	for (int i = 1; i <= MAX; i++) bfs(i);
	cout << ans;
}