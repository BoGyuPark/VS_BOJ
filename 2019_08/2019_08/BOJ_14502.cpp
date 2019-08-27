/*BOJ 14502 ¿¬±¸¼Ò*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, map[9][9], c[65], sel[3], check[9][9], virusCnt, ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
vector<pair<int, int>> zero, virus;
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
				virusCnt++;
			}
		}
	}
	if (ans < zero.size() - 3 - virusCnt) ans = zero.size() - 3 - virusCnt;
}
void go(int index, int start) {
	if (index == 3) {
		for (int j = 0; j < 3; j++) map[zero[sel[j]].first][zero[sel[j]].second] = 1;
		virusCnt = 0;
		memset(check, 0, sizeof(check));
		for (int j = 0; j < virus.size(); j++) {
			q.push({ virus[j].first,virus[j].second });
			check[virus[j].first][virus[j].second] = true;
		}
		bfs();

		for (int j = 0; j < 3; j++) map[zero[sel[j]].first][zero[sel[j]].second] = 0;
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
			else if (map[i][j] == 2) virus.push_back({ i,j });
		}
	}
	go(0,0);
	cout << ans;
}