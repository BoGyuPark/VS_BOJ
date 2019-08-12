/*BOJ 1941 소문난 칠공주*/
//7명 중에 4명이상 이다솜파여야한다.
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
char map[7][7];
int check[26], sel[8], visited[5][5], dis[5][5];
const int n = 5;
int ans = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> v;
int bfs(int row, int col) {
	queue<pair<int, int>> q;
	memset(dis, 0, sizeof(dis));
	int Scnt = 0, Ycnt = 0;
	if (map[row][col] == 'S') Scnt++;
	dis[row][col] = true;
	q.push({ row,col });
	int cnt = 1;
	while (!q.empty()) {
		if (Ycnt > 3) break;
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] && dis[nx][ny] == false) {
				if (map[nx][ny] == 'S') Scnt++;
				else Ycnt++;
				q.push({ nx,ny });
				dis[nx][ny] = true;
				cnt++;
			}
		}
	}

	if (cnt == 7) {
		return Scnt;
	}
	else {
		return -1;
	}
}

void go(int index, int start, int Ycnt) {
	if (Ycnt > 3) return;
	if (index == 7) {
		for (int j = 0; j < index; j++) {
			visited[v[sel[j]].first][v[sel[j]].second] = true;
		}

		int temp = bfs(v[sel[0]].first, v[sel[0]].second);

		if (temp >= 4) {
			ans++;
		}
		memset(visited, 0, sizeof(visited));
		return;
	}
	for (int i = start; i < v.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		sel[index] = i;
		if (map[v[i].first][v[i].second] == 'Y') {
			go(index + 1, i, Ycnt + 1);
		}
		else {
			go(index + 1, i, Ycnt);
		}
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			v.push_back({ i,j });
		}
	}
	go(0,0,0);
	cout << ans;
}