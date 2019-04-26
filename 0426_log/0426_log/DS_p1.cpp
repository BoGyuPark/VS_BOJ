#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, t, map[51][51], c[51][51];
int rotateRow, reverseRow;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == -1) continue;
			c[nx][ny] += map[x][y] / 5;
			cnt++;
		}
		c[x][y] += map[x][y] - (map[x][y] / 5)*cnt;
		map[x][y] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] += c[i][j];
		}
	}
	memset(c, 0, sizeof(c));
}
void FindPos() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) q.push({ i,j });
		}
	}
}

void rotate() {
	//아래 밀기
	int row = rotateRow;
	int col = 0;
	for (int i = row - 2; i >= 0; i--) {
		map[i + 1][col] = map[i][col];
	}
	//왼쪽으로 밀기
	for (int i = col + 1; i < m; i++) {
		map[0][i - 1] = map[0][i];
	}
	//위로 밀기
	for (int i = 1; i <= row; i++) {
		map[i - 1][m - 1] = map[i][m - 1];
	}
	//오른쪽으로 밀기
	for (int i = m - 2; i >= 1; i--) {
		map[row][i + 1] = map[row][i];
	}
	map[row][1] = 0;
}

void reverseRotate() {
	//위로 밀기
	int row = reverseRow;
	int col = 0;
	for (int i = row + 2; i < n; i++) {
		map[i - 1][col] = map[i][col];
	}
	//왼쪽으로 밀기
	for (int i = col + 1; i < m; i++) {
		map[n - 1][i - 1] = map[n - 1][i];
	}
	//아래로 밀기
	for (int i = n - 2; i >= row; i--) {
		map[i + 1][m - 1] = map[i][m - 1];
	}
	//오른쪽으로 밀기
	for (int i = m - 2; i >= 1; i--) {
		map[row][i + 1] = map[row][i];
	}
	map[row][1] = 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> t;
	int flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (flag == true) {
					rotateRow = i;
					flag = false;
				}
				else reverseRow = i;
			}
			else if (map[i][j] > 0) {
				q.push({ i,j });
			}
		}
	}

	for (int i = 0; i < t; i++) {
		bfs();
		rotate();
		reverseRotate();
		FindPos();
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) ans += map[i][j];
		}
	}
	cout << ans;
}