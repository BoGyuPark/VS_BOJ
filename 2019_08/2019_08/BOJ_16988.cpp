/*BOJ 16988  Baaaaaaaaaduk2 (Easy)*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
vector<pair<int, int>> zero;
int n, m, map[21][21], check[21][21], sel[2], c[441], ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void bfs() {
	int cnt = 0, flag = 0, sum = 0;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2 && !check[i][j]) {
				cnt = 1;	flag = 0;	q.push({ i,j });
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (check[nx][ny]) continue;
						if (map[nx][ny] == 2) {
							q.push({ nx,ny });
							check[nx][ny] = true;
							cnt++;
						}
						else if (map[nx][ny] == 0) flag = true;
					}
				}
				if (!flag) sum += cnt;
				else {
					while (!q.empty()) q.pop();
				}
			}
		}
	}
	if (ans < sum) ans = sum;
}
void go(int index,int start) {
	if (index == 2) {
		for (int j = 0; j < 2; j++) map[zero[sel[j]].first][zero[sel[j]].second] = 1;
		bfs();
		for (int j = 0; j < 2; j++) map[zero[sel[j]].first][zero[sel[j]].second] = 0;
		return;
	}
	for (int i = start; i < zero.size(); i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zero.push_back({ i,j });
		}
	}
	go(0,0);
	cout << ans;
}