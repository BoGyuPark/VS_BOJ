/*BOJ 14948 군대탈출하기*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, map[101][101], check[101][101], ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> level;
int cnt;
struct info {
	int x, y, cnt;
};
queue<info> q;
void go(int x, int y) {
	check[x][y] = true;
	if (x == n - 1 && y == m - 1) {
		cnt++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (check[nx][ny]) continue;
		go(nx, ny);
		check[nx][ny] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	n = 100, m = 100;
	go(0, 0);
	cout << cnt;
}