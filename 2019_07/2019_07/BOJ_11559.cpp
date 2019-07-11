/*BOJ 11559 Puyo Puyo*/
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#define n 12
#define m 6
using namespace std;
char map[12][6];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int check[12][6];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
int bfs(int row, int col, char target) {
	v = vector<pair<int, int>>();
	q.push({ row,col });
	check[row][col] = true;
	v.push_back({ row,col });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny] == true) continue;
			if (map[nx][ny] == target) {
				q.push({ nx,ny });
				check[nx][ny] = true;
				v.push_back({ nx,ny });
			}
		}
	}

	if (v.size() >= 4) {
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = '.';
		}
		return 1;
	}
	return 0;
}

void downPuyo() {
	for (int col = 0; col < m; col++) {
		int emptyCnt = 0;
		for (int row = n-1; row >=0; row--) {
			char temp = map[row][col];
			if (map[row][col] == '.') emptyCnt++;
			else {
				map[row][col] = '.';
				map[row + emptyCnt][col] = temp;
			}
		}
	}
}

bool boom() {
	memset(check, 0, sizeof(check));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.' || check[i][j] == true) continue;
			char target = map[i][j];
			cnt += bfs(i, j, target);
		}
	}
	if (cnt == 0) return false;
	else return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (true) {
		if (!boom()) break;
		//printMap();
		downPuyo();
		//printMap();
		ans++;
	}
	cout << ans;
}