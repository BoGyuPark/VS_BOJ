//BOJ_2178_SearchMaze
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int maze[101][101];
int check[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
void bfs(int x, int y)
{
	queue<pair<int, int> > q; q.push(make_pair(x, y));
	check[x][y] = 1;
	int befx, befy, nx, ny;
	while (!q.empty()) {
		befx = q.front().first; befy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = befx + dx[i]; ny = befy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (check[nx][ny] == 0 && maze[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = check[befx][befy] + 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			maze[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0);
	cout << check[n - 1][m - 1];
	return 0;
}