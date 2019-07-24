/*BOJ 16137 견우와직녀*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, map[11][11], check[11][11][20], cross[11][11], ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> zero, sel;
typedef struct {
	int x, y, t;
}info;
queue<info> q;
void bfs() {
	q.push({ 0,0,0 });
	memset(check, -1, sizeof(check));
	check[0][0][0] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, t = q.front().t;
		q.pop();

		//오작교인 경우
		if (map[x][y] >= 2 && t % map[x][y] != 0) {
			int nt = (t + 1) % map[x][y];
			if (check[x][y][nt] == -1) {
				check[x][y][nt] = check[x][y][t] + 1;
				q.push({ x,y,nt });
			}
		}
		else
		{
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				//연속으로 오작교 이동 할 수 없다.
				if (map[x][y] >= 2 && map[nx][ny] >= 2) continue;
				if (map[nx][ny] >= 1) {
					int nt = (check[x][y][t] + 1) % map[nx][ny];
					if (check[nx][ny][nt] == -1) {
						check[nx][ny][nt] = check[x][y][t] + 1;
						q.push({ nx,ny,nt });
					}
				}
			}
		}	
	}
	if (ans > check[n - 1][n - 1][0] && check[n - 1][n - 1][0] != -1) 
		ans = check[n - 1][n - 1][0];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zero.push_back({ i,j });
		}
	}
	//교차지점 찾기
	for (int i = 0; i < zero.size(); i++) {
		int x = zero[i].first, y = zero[i].second;
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j], ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == 0) cnt++;
		}
		if (cnt >= 2) cross[x][y] = true;
	}

	ans = 2147483647;
	for (int i = 0; i < zero.size(); i++) {
		int x = zero[i].first, y = zero[i].second;
		if (cross[x][y]) continue;
		map[x][y] = m;
		bfs();
		map[x][y] = 0;
	}
	cout << ans;
}