/*BOJ 16954 움직이는 미로 탈출*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
char map[9][9];
int n = 8;
int check[9][9];
int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };
vector<pair<int, int>> wall, temp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				wall.push_back({ i,j });
			}
		}
	}
	queue<pair<int, int>> q;
	q.push({ n - 1, 0 });
	check[n - 1][0] = true;
	while (!q.empty()) {
		int Qsize = q.size();
		memset(check, 0, sizeof(check));
		while (Qsize--) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			if (x == 0 && y == n - 1) {
				cout << 1;
				return 0;
			}
			if (map[x][y] == '#') continue;
			for (int i = 0; i < 9; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (check[nx][ny]) continue;
				if (map[nx][ny] == '.') {
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}

		//wall erase
		for (int i = 0; i < wall.size(); i++) {
			map[wall[i].first][wall[i].second] = '.';
		}
		//wall down
		for (int i = 0; i < wall.size(); i++) {
			int nextRow = wall[i].first + 1;
			if (nextRow < n) {
				map[nextRow][wall[i].second] = '#';
				temp.push_back({ nextRow,wall[i].second });
			}
		}
		wall.clear();
		wall = temp;
		temp.clear();
	}
	cout << 0;
	return 0;
}