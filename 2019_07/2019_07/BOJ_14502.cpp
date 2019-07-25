/*BOJ 14502 ¿¬±¸¼Ò*/
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n, m, safeCnt, ans;
int check[9][9], sel[3], map[9][9], visited[65];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> safe, virus;
queue<pair<int, int>> q;
void bfs() {
	memset(check, 0, sizeof(check));
	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first, y = virus[i].second;
		q.push({ x,y });
		check[x][y] = true;
	}
	int addVirusCnt = 0;
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
				addVirusCnt++;
			}
		}
	}
	if (ans < safeCnt - addVirusCnt - 3) ans = safeCnt - addVirusCnt - 3;
}

void go(int index,int start) {
	if (index == 3) {
		for (int j = 0; j < 3; j++) {
			int x = safe[sel[j]].first, y = safe[sel[j]].second;
			map[x][y] = 1;
		}
		bfs();
		for (int j = 0; j < 3; j++) {
			int x = safe[sel[j]].first, y = safe[sel[j]].second;
			map[x][y] = 0;
		}
		return;
	}
	for (int i = start; i < safeCnt; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		sel[index] = i;
		go(index + 1, i);
		visited[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				safe.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	safeCnt = safe.size();
	go(0,0);
	cout << ans;
}