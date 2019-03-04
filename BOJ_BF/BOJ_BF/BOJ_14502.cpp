#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, map[9][9], zerocnt, temp[65], ans = -1;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int> > zero, virus;
int bfs() {
	int viruscnt = 0, c[9][9] = { 0, };
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first,virus[i].second });
		c[virus[i].first][virus[i].second] = 1;
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c[nx][ny] == true) continue;
			if (map[nx][ny] == 0) {
				c[nx][ny] = true;
				q.push({ nx,ny });
				viruscnt++;
			}
		}
	}
	return zerocnt - viruscnt - 3;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back({ i,j });
			else if (map[i][j] == 0) zero.push_back({ i,j });
		}
	}
	zerocnt = zero.size();
	temp[0] = temp[1] = temp[2] = 1;
	do {
		for (int i = 0; i < zerocnt; i++) 
			if (temp[i] == 1) map[zero[i].first][zero[i].second] = 1;
		int t = bfs();
		if (ans < t) ans = t;
		for (int i = 0; i < zerocnt; i++) 
			if (temp[i] == 1) map[zero[i].first][zero[i].second] = 0;	
	} while (prev_permutation(temp, temp + zerocnt));
	cout << ans;
}