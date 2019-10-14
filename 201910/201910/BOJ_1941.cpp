/*BOJ 1941 소문난 칠공주*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
char map[6][6];
int n = 5, ans, sel[7], c[26], visited[6][6];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<pair<int, int>> v;
queue<pair<int, int>> q;
void bfs(int row, int col) {
	int Scnt = 0, Ycnt = 0;
	visited[row][col] = 2;
	q.push({ row,col });
	if (map[row][col] == 'S') Scnt++;
	else Ycnt++;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] == true) {
				q.push({ nx,ny });
				visited[nx][ny] = 2;
				if (map[nx][ny] == 'S') Scnt++;
				else Ycnt++;

				if (Ycnt >= 4) {
					while (!q.empty())	q.pop();
					return;
				}
			}
		}
	}

	if (Scnt + Ycnt == 7 && Scnt >= 4) ans++;
}
void go(int index,int start) {
	if (index == 7) {

		for (int j = 0; j < index; j++) {
			visited[v[sel[j]].first][v[sel[j]].second] = true;
		}
		bfs(v[sel[0]].first, v[sel[0]].second);

		for (int j = 0; j < index; j++) {
			visited[v[sel[j]].first][v[sel[j]].second] = false;
		}
		return;
	}
	for (int i = start; i < v.size(); i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			v.push_back({ i,j });
		}
	
	go(0,0);
	cout << ans;
}