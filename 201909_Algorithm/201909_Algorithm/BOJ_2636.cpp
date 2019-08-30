/*BOJ 2636 ДЎБо*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, map[101][101], check[101][101], sx, sy, OneCnt;
int prev_Size, T = -1;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
vector<pair<int, int>> v;

void bfs() {

	while (!q.empty()) {

		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny]) continue;

			if (map[nx][ny] == 0) {
				q.push({ nx,ny });
				check[nx][ny] = true;
			}
			else {
				v.push_back({ nx,ny });
				check[nx][ny] = true;
			}
		}
	}
	if (v.size() != 0) prev_Size = v.size();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) { sx = i, sy = j; }
			else if (map[i][j] == 1) OneCnt++;
		}
	}
	q.push({ sx,sy });
	check[sx][sy] = true;
	while (!q.empty()) {
		bfs();
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first, y = v[i].second;
			map[x][y] = 0;
			check[x][y] = true;
			q.push({ x,y});
		}
		v.clear();
		T++;
	}
	cout << T << '\n' << prev_Size;
}