#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, a[9][9], zerocnt;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> zero, virus;
int bfs() {
	int c[9][9] = { 0, }, viruscnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first,virus[i].second });
		c[virus[i].first][virus[i].second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c[nx][ny] == true) continue;
			if (a[nx][ny] == 0) {
				c[nx][ny] = true;
				q.push({ nx,ny });
				viruscnt++;
			}
		}
	}
	return zerocnt - 3 - viruscnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) zero.push_back({ i,j });
			else if (a[i][j] == 2) virus.push_back({ i,j });
		}
	}
	zerocnt = zero.size();
	int t[64] = { 0, }, ans = -1;
	t[0] = t[1] = t[2] = 1;
	do {
		for (int i = 0; i < zerocnt; i++) 
			if (t[i]) a[zero[i].first][zero[i].second] = 1;
		int temp = bfs();
		if (temp > ans) ans = temp;
		for (int i = 0; i < zerocnt; i++) 
			if (t[i]) a[zero[i].first][zero[i].second] = 0;
	} while (prev_permutation(t, t + zerocnt));
	cout << ans;
}