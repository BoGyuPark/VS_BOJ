/*BOJ 16957 체스판 위의 공*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int transDir[] = { 7,6,5,4,3,2,1,0 };
int n, m, map[501][501], dirs[501][501], cnt[501][501], check[501][501];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
void bfs(int row, int col) {
	q.push({ row,col });
	check[row][col] = true;
	int count = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			if (dirs[x][y] &(1 << i)) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (check[nx][ny]) continue;
				q.push({ nx,ny });
				check[nx][ny] = true;
				count++;
			}
		}
	}
	cnt[row][col] = count;
}

void search() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = i, y = j;
			int dir = -1, minNum = 2147483647, nnx, nny;
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (map[nx][ny] <= map[x][y]) {
					if (minNum > map[nx][ny]) {
						minNum = map[nx][ny];
						dir = i;
					}
				}
			}
			if (dir == -1) v.push_back({ x,y });				
			else dirs[x + dx[dir]][y + dy[dir]] += (1<<transDir[dir]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) cin >> map[i][j];
	
	search();

	for (int i = 0; i < v.size(); i++) bfs(v[i].first, v[i].second);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << cnt[i][j] << ' ';
		cout << '\n';
	}
}