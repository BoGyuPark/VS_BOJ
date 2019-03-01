#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, buf[8], a[9][9], cpy[9][9], emptycnt = 0, cctvcnt = 0, expen, ans;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int dx2[4][3] = { {1,3,0},{0,2,0},{0,0,0},{0,0,0} };
int dx3[4][3] = { {0,1,0},{1,2,0},{2,3,0},{3,0,0} };
int dx4[4][3] = { {0,1,2},{1,2,3},{2,3,0},{3,0,1} };
queue<pair<int, int>> fq;
vector<pair<int, int>> v;
void bfs1(int i, int j, int dir) {
	i += dx[dir];
	j += dy[dir];
	while (a[i][j] != 6) {
		if (i < 0 || j < 0 || i >= n || j >= m) break;
		if (a[i][j] == 0) {
			a[i][j] = 1;
			expen++;
		}
		i += dx[dir];
		j += dy[dir];
	}
}
void bfsS(int i, int j, int dir, int dirmap[4][3], int num,int limit) {
	if (num == 2 && dir >= 2) return;
	int x = i, y = j;
	for (int z = 0; z < limit; z++) {
		x = i + dx[dirmap[dir][z]];
		y = j + dy[dirmap[dir][z]];
		//cctv는 cctv를 통과한다.
		while (a[x][y] != 6) {
			if (x < 0 || y < 0 || x >= n || y >= m) break;
			//cctv라면
			if (a[x][y] == 0) {
				a[x][y] = num;
				expen++;
			}
			x += dx[dirmap[dir][z]];
			y += dy[dirmap[dir][z]];
		}
	}
}
void go(int index) {
	if (index == cctvcnt) {
		expen = 0;
		for (int i = 0; i < cctvcnt; i++) {
			//v[i]의 좌표에서 buf[i]방향으로 맵을 변형
			//v[i]의 좌표값에 따라 cctv가 1,2,3,4번에 따라 다르게 해야한다.
			int state = a[v[i].first][v[i].second];
			if(state==1)	bfs1(v[i].first, v[i].second, buf[i]);
			else if (state == 2) bfsS(v[i].first, v[i].second, buf[i], dx2, 2, 2);
			else if(state==3) bfsS(v[i].first, v[i].second, buf[i], dx3, 3, 2);
			else bfsS(v[i].first, v[i].second, buf[i], dx4, 4, 3);
		}
		if (ans > (emptycnt - expen)) ans = emptycnt - expen;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = cpy[i][j];
		return;
	}
	for (int i = 0; i < 4; i++) {
		buf[index] = i;
		go(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 5) fq.push({ i,j });
			else if (a[i][j] > 0 && a[i][j] < 5) {
				v.push_back({ i,j }); cctvcnt++;
			}
		}
	}
	//미리 cctv가 5면 처리한다.
	while (!fq.empty()) {
		int x = fq.front().first, y = fq.front().second;
		fq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			while (a[nx][ny] !=6) {
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
				if (a[nx][ny] == 0) { a[nx][ny] = 5; }
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
	//빈칸의 개수를 구해놓는다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cpy[i][j] = a[i][j];
			if (a[i][j] == 0) emptycnt++;
		}
	}
	ans = 2147483647;
	//순열돌린다.
	go(0);
	cout << ans;
}