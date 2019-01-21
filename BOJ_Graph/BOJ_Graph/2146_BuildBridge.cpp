//BOJ_2146_BuildBridge
#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;
int map[101][101];
int check[101][101];
int dis[101][101];
int n, cnt = 1;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int> > q;
void dfs(int x, int y) {
	q.push(make_pair(x, y));
	check[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx, ny;
		nx = x + dx[i]; ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (check[nx][ny] == 0 && map[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				dfs(i, j);
				cnt++;
			}
			if (map[i][j] == 1) {
				dis[i][j] = 0;
			}
			else {
				dis[i][j] = -1;
			}
		}
	}
	//섬 분류 완료

	//영토 확장
	while (!q.empty()) {
		int nx, ny, befx, befy;
		befx = q.front().first; befy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = befx + dx[i]; ny = befy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (dis[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					dis[nx][ny] = dis[befx][befy] + 1;
					check[nx][ny] = check[befx][befy];
				}
			}
		}
	}
	int nx, ny, ans = INT_MAX;
	//각 칸과 인접한 칸의 그룹 번호가 다르면 다리를 만든다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				nx = i + dx[k]; ny = j + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (check[i][j] != check[nx][ny] && ans > dis[i][j] + dis[nx][ny]) {
						ans = dis[i][j] + dis[nx][ny];
					}
				}
			}
		}
	}
	cout << ans;

	return 0;
}