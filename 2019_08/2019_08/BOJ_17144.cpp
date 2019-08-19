/*BOJ 17144 미세먼지 안녕!*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, t, map[51][51], ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
typedef struct {
	int x, y, value;
}info;
vector<pair<int, int>> fan;
queue <info> q;
void bfs() {
	//미리 확산할 값을 넣어두기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) {
				q.push({ i,j, map[i][j] });
				map[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, num = q.front().value;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] != -1) {
				cnt++;
				map[nx][ny] += num / 5;
			}
		}
		map[x][y] += num - (num / 5 * cnt);
	}
}
void reverseRotate() {
	int temp = map[fan[0].first][fan[0].second];
	int r = fan[0].first - 1, c = fan[0].second;
	int rowMax = r + 1, colMax = c;
	//아래로
	for (int i = 1; i < rowMax; i++) {
		map[r][c] = map[r - 1][c];
		r--;
	}
	//왼쪽
	for (int i = 0; i < m - 1; i++) {
		map[r][c] = map[r][c + 1];
		c++;
	}
	//위로
	for (int i = 0; i < rowMax; i++) {
		map[r][c] = map[r + 1][c];
		r++;
	}
	//오른쪽
	for (int i = 0; i < m - 2; i++) {
		map[r][c] = map[r][c - 1];
		c--;
	}
	map[r][c] = 0;
}
void Rotate() {
	int temp = map[fan[1].first][fan[1].second];
	int r = fan[1].first, c = fan[1].second;
	int rowMax = n - r - 1;
	r++;
	//위로
	for (int i = 1; i < rowMax; i++) {
		map[r][c] = map[r + 1][c];
		r++;
	}
	//왼쪽
	for (int i = 0; i < m - 1; i++) {
		map[r][c] = map[r][c + 1];
		c++;
	}
	//아래로
	for (int i = 0; i < rowMax; i++) {
		map[r][c] = map[r - 1][c];
		r--;
	}
	//오른쪽
	for (int i = 0; i < m - 2; i++) {
		map[r][c] = map[r][c - 1];
		c--;
	}
	map[r][c] = 0;
}
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) fan.push_back({ i,j });
		}
	}
	for (int i = 0; i < t; i++) {
		//먼지 확산
		bfs();
		//회전
		reverseRotate();
		Rotate();
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) ans += map[i][j];
		}
	}
	cout << ans;
}