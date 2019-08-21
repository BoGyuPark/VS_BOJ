/*BOJ 11559 Puyo Puyo*/
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
char map[13][7];
const int n = 12, m = 6;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int check[13][7], boomCnt;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << map[i][j] << ' ';
		cout << '\n';
	}
}
void boom() {
	memset(check, 0, sizeof(check));
	boomCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '.') {
				char color = map[i][j];	
				q.push({ i,j });
				v.push_back({ i,j });
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (check[nx][ny] == false && color == map[nx][ny]) {
							q.push({ nx,ny });
							check[nx][ny] = true;
							v.push_back({ nx,ny });
						}
					}
				}

				if (v.size() >= 4) {
					boomCnt++;
					for (int i = 0; i < v.size(); i++) {
						map[v[i].first][v[i].second] = '.';
					}
				}
				v.clear();
			}
		}
	}
}
void down() {
	for (int c = 0; c < m; c++) {
		int emptyCnt = 0;
		int r = n - 1;
		while (r >= 0) {
			if (map[r][c] == '.') emptyCnt++;
			else {
				if (emptyCnt > 0) {
					map[r + emptyCnt][c] = map[r][c];
					map[r][c] = '.';
				}
			}
			r--;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	int ans = 0;
	//printMap();
	
	while (true) {
		//boom
		boom();
		//printMap();
		if (boomCnt == 0) break;
		//down
		down();
		//printMap();
		ans++;
	}
	cout << ans;
}