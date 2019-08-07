/*BOJ 2210 숫자판 점프*/
#include<iostream>
#include<string>
#include<queue>
#include<set>
using namespace std;
int map[5][5];
const int n = 5;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
typedef struct {
	int x, y;
	string s;
}info;
queue<info> q;
set<string> ans;
void bfs(int row, int col) {
	string t = to_string(map[row][col]);
	q.push({ row,col,t });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		string nowStr = q.front().s;
		q.pop();
		if (nowStr.size() == 6) {
			ans.insert(nowStr);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			string nextStr = nowStr + to_string(map[nx][ny]);
			q.push({ nx,ny,nextStr });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bfs(i, j);
		}
	}
	cout << ans.size() << '\n';
	return 0;
}