/*BOJ 3019 테트리스*/
#include<iostream>
#include<vector>
using namespace std;
int n = 110, m, map[111][101], P, maxCnt, ans;
int maxi[8] = { 0,2,1,2,2,4,4,4 };
vector<pair<int, int>> v;
//       번호,가능한개수,좌표
pair<int,int> tetris[8][4][3] = {
	{
		{{0,0},{0,0},{0,0}},
		{{0,0},{0,0},{0,0}},
		{{0,0},{0,0},{0,0}},
		{{0,0},{0,0},{0,0}}
	},
	{
		{{-1,0},{-2,0},{-3,0}},
		{{0,1},{0,2},{0,3}},
		{{0,0},{0,0},{0,0}},
		{{0,0},{0,0},{0,0}}
	},
	{
		{{0,1},{-1,0},{-1,1}},
		{{0,0},{0,0},{0,0}},
		{{0,0},{0,0},{0,0}},
		{{0,0},{0,0},{0,0}}
	},
	{
		{{0,1},{-1,1},{-1,2}},
		{{-1,0},{-1,-1},{-2,-1}},
		{{0,0},{0,0},{0,0}},
		{{0,0},{0,0},{0,0}}
	},
	{
		{{0,1},{-1,-1},{-1,0}},
		{{-1,0},{-1,1},{-2,1}},
		{{0,0},{0,0},{0,0}},
		{{0,0},{0,0},{0,0}}
	},
	{
		{{0,1},{0,2},{-1,1}},
		{{-1,0},{-1,1},{-2,0}},
		{{-1,-1},{-1,0},{-1,1}},
		{{-1,-1},{-1,0},{-2,0}}
	},
	{
		{{0,1},{0,2},{-1,2}},
		{{-1,0},{-2,0},{-2,-1}},
		{{-1,0},{-1,1},{-1,2}},
		{{0,1},{-1,0},{-2,0}}
	},
	{
		{{0,1},{0,2},{-1,0}},
		{{-1,0},{-2,0},{-2,1}},
		{{-1,0},{-1,-1},{-1,-2}},
		{{0,1},{-1,1},{-2,1}}
	}
};
void insertTetris(int x, int y, int idx, int value) {
	map[x][y] = value;
	for (int j = 0; j < 3; j++) {
		int nx = x + tetris[P][idx][j].first, ny = y + tetris[P][idx][j].second;
		map[nx][ny] = value;
	}
}
void isPossible(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < maxCnt; i++) {
		int flag = false;
		for (int j = 0; j < 3; j++) {
			int nx = x + tetris[P][i][j].first, ny = y + tetris[P][i][j].second;
			if (nx >= n || ny < 0 || ny >= m || map[nx][ny] == 1) {
				flag = true;
				break;
			}
		}
		//놓을 수는 있다.
		if (!flag) {
			insertTetris(x, y, i, true);
			int impossible = false;
			//밑에 빈칸이 있는지 확인
			for (int j = 0; j < 3; j++) {
				int nx = x + tetris[P][i][j].first + 1 , ny = y + tetris[P][i][j].second;
				if (nx >= n || map[nx][ny] == 1) continue;
				if (map[nx][ny] == 0) { impossible = true; break; }
			}
			if (!impossible) cnt++;
			insertTetris(x, y, i, false);
		}
	}
	ans += cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> P;
	for (int i = 0; i < m; i++) {
		int h; cin >> h;
		int j = 0;
		while (h--) {
			map[n - 1 - j][i] = true;
			j++;
		}
		v.push_back({ n - 1 - j,i });
	}
	maxCnt = maxi[P];
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		isPossible(x, y);
	}
	cout << ans;
}