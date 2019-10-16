/*BOJ 16924 십자가 찾기*/
#include<iostream>
#include<vector>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m, check[101][101];
char map[101][101];
struct info {
	int x, y, s;
};
vector<pair<int, int>> v;
vector<info> star;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') v.push_back({ i,j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		int dist = 1;
		while (true) {
			int breakFlag = false;
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j] * dist, ny = y + dy[j] * dist;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == '.') {
					breakFlag = true;
					break;
				}
			}
			if (breakFlag) break;
			else {
				star.push_back({ x,y,dist });
				check[x][y] = true;
				for (int j = 0; j < 4; j++) {
					int nx = x + dx[j] * dist, ny = y + dy[j] * dist;
					check[nx][ny] = true;
				}
			}
			dist++;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) cnt++;
		}
	}
	if (cnt == v.size()) {
		cout << star.size() << '\n';
		for (auto i : star) cout << i.x + 1 << ' ' << i.y + 1 << ' ' << i.s << '\n';
	}
	else cout << -1;
}