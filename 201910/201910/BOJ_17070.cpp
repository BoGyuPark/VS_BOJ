#include<iostream>
#include<vector>
using namespace std;
int n, map[17][17], ans;
int dx[] = { 0,1,1 };	//오른쪽, 아래, 대각선 
int dy[] = { 1,0,1 };
vector<int> dirs[3];
void go(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		ans++;
		return;
	}

	for (int i = 0; i < dirs[dir].size(); i++) {
		int ndir = dirs[dir][i];
		int nx = x + dx[ndir], ny = y + dy[ndir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (ndir == 2) {
			if (map[x + 1][y] == 0 && map[x][y + 1] == 0 && map[nx][ny] == 0) {
				go(nx, ny, ndir);
			}
		}
		else {
			if (map[nx][ny] == 0) go(nx, ny, ndir);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> map[i][j];
	}

	dirs[0].push_back(0);
	dirs[0].push_back(2);
	dirs[1].push_back(1);
	dirs[1].push_back(2);
	dirs[2].push_back(0);
	dirs[2].push_back(1);
	dirs[2].push_back(2);
	go(0, 1, 0);
	cout << ans;
}