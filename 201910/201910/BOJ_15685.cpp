/* BOJ 15685 µå·¡°ï Ä¿ºê */
#include<iostream>
#include<vector>
using namespace std;
int n, row, col, d, g, map[101][101], ans;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
vector<int> dirs;
void insertCurve() {

	for (int i = 0; i < g; i++) {
		int dirsSize = dirs.size();
		for (int j = dirsSize-1; j >=0; j--) {
			dirs.push_back((dirs[j] + 1) % 4);
		}
	}

	int x = row, y = col;
	map[x][y] = true;
	for (int i = 0; i < dirs.size(); i++) {
		int nx = x + dx[dirs[i]], ny = y + dy[dirs[i]];
		map[nx][ny] = true;
		x = nx, y = ny;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> col >> row >> d >> g;
		dirs.push_back(d);
		insertCurve();
		dirs.clear();
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans;
}