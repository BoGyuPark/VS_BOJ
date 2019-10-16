/*BOJ 16956 ´Á´ë¿Í ¾ç*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int n, m, check[501][501];
char map[501][501];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'W') {
				q.push({ i,j });
				check[i][j] = true;
			}
			else if (map[i][j] == 'S') {
				v.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j], ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == '.') {
				map[nx][ny] = 'D';
			}
		}
	}
	bool flag = false;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j], ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny]) continue;
			if (map[nx][ny] == '.') {
				q.push({ nx,ny });
				check[nx][ny] = true;
			}
			else if (map[nx][ny] == 'S') {
				flag = true;
				while (!q.empty()) q.pop();
				break;
			}
		}
	}
	if (flag) cout << 0;
	else {
		cout << 1 << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << map[i][j];
			cout << '\n';
		}
	}
}