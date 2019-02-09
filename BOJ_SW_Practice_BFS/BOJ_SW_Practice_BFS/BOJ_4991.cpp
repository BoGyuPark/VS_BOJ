#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int w, h, ok, arr[21][21] = { 0, };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char map[21][21];
void bfs(int x, int y, int order, vector<pair<int, int> > &dir) {
	int check[21][21] = { 0, };
	int d[21][21] = { 0, };
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 0;
	while (!q.empty()) {
		int nowx = q.front().first, nowy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nowx + dx[i], ny = nowy + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (check[nx][ny] == false && map[nx][ny] != 'x') {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[nowx][nowy] + 1;
				}
			}
		}
	}
	//s로부터 도착 지점, 거리 정보를 저장한다.
	for (int i = 0; i < dir.size(); i++) {
		if (x == dir[i].first && y == dir[i].second) continue;
		if (d[dir[i].first][dir[i].second] == 0) { ok = true; break; }
		arr[order][i] = d[dir[i].first][dir[i].second];
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (true) {
		//로봇의 위치 및 더러운 칸의 위치
		vector<pair<int, int> > dir(1);
		cin >> w >> h;
		if (h == 0 && w == 0)	break;
		//맵의 정보를 받아 로봇의 위치와 더러운방의 위치를 저장
		for (int i = 0; i < h; i++) {
			cin >> map[i];
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 'o') {
					dir[0] = make_pair(i, j);
				}else if (map[i][j] == '*') 
					dir.push_back(make_pair(i, j));
			}
		}
		//로봇에서 각 더러운칸의 거리, 각 더러운칸에서 다른 더러운칸의 거리 정보 계산
		vector<int> order(dir.size());
		ok = false;
		for (int i = 0; i < dir.size(); i++) {
			bfs(dir[i].first, dir[i].second, i, dir);
			order[i] = i;
			if (ok == true) break;
		}
		if (ok == true) cout << -1 << '\n';
		else {
			int ans = 999999;
			do {
				int temp = 0;
				for (int i = 0; i < dir.size() - 1; i++) {
					temp += arr[order[i]][order[i + 1]];
				}
				if (ans > temp) ans = temp;
			} while (next_permutation(order.begin() + 1, order.end()));
			cout << ans << '\n';
		}
		memset(map, 0, sizeof(map));
		memset(arr, 0, sizeof(arr));
	}
}