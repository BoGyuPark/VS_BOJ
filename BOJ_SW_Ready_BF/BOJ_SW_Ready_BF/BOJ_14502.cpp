#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, a[65][65], c[65][65], temp[65], Limit;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int bfs() {
	int virus = 0;
	queue<pair<int, int>> qq;
	qq = q;
	while (!qq.empty()) {
		int x = qq.front().first, y = qq.front().second;
		qq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c[nx][ny] == true) continue;
			if (a[nx][ny] == 0) {
				c[nx][ny] = true;
				qq.push({ nx,ny });
				virus++;
			}
		}
	}
	return virus;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) { v.push_back({ i,j }); Limit++; }
			else if (a[i][j] == 2) {
				q.push({ i,j });
				c[i][j] = true;
			}
		}
	temp[0] = temp[1] = temp[2] = 1;
	int ans = 0;
	do {
		//map에서 벽을 3개 만든다.
		for (int i = 0; i < Limit; i++) {if (temp[i] == 1) a[v[i].first][v[i].second] = 1;}
		//bfs로 바이러스 전파시킨다.
		int t = bfs();
		if (ans < (Limit - 3 - t)) ans = Limit - 3 - t;
		//0으로 다시 변경
		for (int i = 0; i < Limit; i++) {if (temp[i] == 1) a[v[i].first][v[i].second] = 0;}
		memset(c, 0, sizeof(c));
	} while (prev_permutation(temp, temp + Limit));
	cout << ans;
}