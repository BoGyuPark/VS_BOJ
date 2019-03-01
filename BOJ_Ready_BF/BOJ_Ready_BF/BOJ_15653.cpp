#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n, m, d[11][11][11][11];
typedef struct info {
	int irx, iry, ibx, iby;
};
//움직였는지, 구멍에 빠졌는지
pair<bool, bool> simulate(vector<string> &a, int &x, int &y, int dir) {
	//R,B 구슬이 구멍에 빠진 후 R과B를 맵에서 없앨 경우
	if (a[x][y] == '.') return{ false,false };
	bool move = false;
	
	while (true) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if (a[nx][ny] == '#') return { move,false };
		//이동 중에 다음 좌표에 다른 구슬이 있는 경우.
		else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') return { move,false };
		//계속 이동을 해야하기 때문에 return 하지 않는다.
		else if (a[nx][ny] == '.') {
			swap(a[nx][ny], a[x][y]);
			x = nx; y = ny;
			move = true;
		}
		else if (a[nx][ny] == 'O') {
			a[x][y] = '.';
			move = true;
			return { move,true };
		}
	}
	return { false,false };
}
//구슬이 멈출 때까지 구슬을 움직인다.
//레퍼런스로 주는 것이 핵심.
pair<bool, bool> next(vector<string> a, int &nrx, int &nry, int &nbx, int &nby, int dir) {
	//맵에 R과 B를 저장
	a[nrx][nry] = 'R';
	a[nbx][nby] = 'B';
	bool rflag = false, bflag = false;

	while (true) {
		//안움직엿는지, 구멍에빠졌는지
		pair<bool, bool> p1 = simulate(a, nrx, nry, dir);
		pair<bool, bool> p2 = simulate(a, nbx, nby, dir);
		//둘다 더 이상 안움직인경우
		if (p1.first == false && p2.first == false) break;
		if (p1.second) rflag = true;
		if (p2.second) bflag = true;
	}
	return { rflag,bflag };
}
int main() {
	cin >> n >> m;
	//R과 B의 좌표를 받아온다.
	vector<string> a(n);
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'R') { rx = i; ry = j; a[i][j] = '.'; }
			if (a[i][j] == 'B') { bx = i; by = j; a[i][j] = '.'; }
		}
	}
	memset(d, -1, sizeof(d));
	queue<info> q;
	q.push({ rx,ry,bx,by });
	d[rx][ry][bx][by] = 0;
	int ans = -1;
	//정답을 찾은경우 while 탈출위하여
	bool found = false;
	while (!q.empty()) {
		int rx = q.front().irx, ry = q.front().iry;
		int bx = q.front().ibx, by = q.front().iby;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			//  R 구멍, B 구멍
			pair<bool, bool> holestate = next(a, nrx, nry, nbx, nby, i);
			if (holestate.second) continue;
			if (holestate.first) {
				found = true;
				ans = d[rx][ry][bx][by] + 1;
				break;
			}
			//방문한곳이면 (nrx,nry,nbx,nby는 한 번 기울임으로써 좌표가 바뀜)
			if (d[nrx][nry][nbx][nby] != -1) continue;
			q.push({ nrx,nry,nbx,nby });
			d[nrx][nry][nbx][nby] = d[rx][ry][bx][by] + 1;
		}
		if (found) break;
	}
	cout << ans;
}