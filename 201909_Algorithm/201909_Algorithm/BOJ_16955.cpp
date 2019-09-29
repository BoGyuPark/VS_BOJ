/*BOJ 16955 오목, 이길수 있을까?*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char map[11][11];
int Xcnt, n = 10, check[11][11], ans;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
//empty pos
vector<pair<int, int>> v;

bool checkWin(int r, int c, int num1, int num2) {
	int cnt = 1;
	for (int dir : {num1, num2}) {
		int x = r, y = c;
		while (true)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
			if (map[nx][ny] == 'X') cnt++;
			else break;
			x = nx, y = ny;
		}
	}
	if (cnt >= 5) return true;
	else return false;
}
void simulate() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		//3,4 : 가로, 1,6 : 세로, 2,5 : 왼쪽 대각선, 0,7 : 오른쪽 대각선
		if (checkWin(x, y, 3, 4) || checkWin(x, y, 1, 6)
			|| checkWin(x, y, 0, 7) || checkWin(x, y, 2, 5)) {
			ans = 1;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> map[i][j];
			
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'X') {
				int x = i, y = j;
				for (int z = 0; z < 8; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (check[nx][ny] || map[nx][ny] != '.') continue;
					check[nx][ny] = true;
					v.push_back({ nx,ny });
				}
			}
		}
	}
	simulate();
	cout << ans;
}