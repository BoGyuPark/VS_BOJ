/* BOJ 2589 º¸¹°¼¶*/
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, check[51][51], ans;
char map[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> v;
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] != -1) continue;
			if (map[nx][ny] == 'W') continue;
			q.push({ nx,ny });
			check[nx][ny] = check[x][y] + 1;
			ans = max(ans, check[nx][ny]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') v.push_back({ i,j });
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		memset(check, -1, sizeof(check));
		q.push({ v[i].first,v[i].second });
		check[v[i].first][v[i].second] = 0;
		bfs();
	}
	cout << ans;
}