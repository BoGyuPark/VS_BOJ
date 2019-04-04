#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, a[9][9], c[9][9], mini;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> Zero, virus;
int bfs() {
	memset(c, 0, sizeof(c));
	queue<pair<int, int>> q;
	int cnt = 0;
	for (int s = 0; s < virus.size(); s++) {
		q.push({ virus[s].first,virus[s].second });
		c[virus[s].first][virus[s].second] = true;
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c[nx][ny] == true) continue;
			if (a[nx][ny] == 0) {
				c[nx][ny] = true;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) Zero.push_back({ i,j });
			else if (a[i][j] == 2) virus.push_back({ i,j });
		}
	}
	int t[64] = { 0, };
	t[0] = t[1] = t[2] = 1;
	mini = 2147483647;
	do {
		for (int i = 0; i < Zero.size(); i++) {	
			if (t[i] == 1) a[Zero[i].first][Zero[i].second] = 1;
		}
		int remainArea = bfs();
		if (mini > remainArea) mini = remainArea;
		for (int i = 0; i < Zero.size(); i++) {
			if (t[i] == 1) a[Zero[i].first][Zero[i].second] = 0;
		}
	} while (prev_permutation(t,t+Zero.size()));

	int ans;
	ans = Zero.size() - 3 - mini;
	cout << ans;
}