#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef struct info {
	int irx, iry, ibx, iby;
};
int n, m, d[11][11][11][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
//움직였는지, 구멍에 들어갔는지
pair<bool, bool> simulate(vector<string> &s, int &x, int &y, int dir) {
	if (s[x][y] == '.') return { false, false };
	bool move = false;
	while (true) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if (s[nx][ny] == '#' || s[nx][ny] == 'R' || s[nx][ny] == 'B') return { move,false };
		else if (s[nx][ny] == '.') {
			swap(s[nx][ny], s[x][y]);
			x = nx; y = ny;
			move = true;
		}
		else if (s[nx][ny] == 'O') {
			s[x][y] = '.';
			move = true;
			return { move,true };
		}
	}
}

//R hole, B hole 통과 유무
pair<bool, bool> next(vector<string> s, int &nrx, int &nry, int &nbx, int &nby, int dir) {
	//맵에 R과 B의 저장
	s[nrx][nry] = 'R';
	s[nbx][nby] = 'B';
	bool Rhole = false, Bhole = false;
	while (true) {
		pair<bool, bool> p1 = simulate(s, nrx, nry, dir);
		pair<bool, bool> p2 = simulate(s, nbx, nby, dir);
		//더 이상 움직이지 않을 때
		if (p1.first == false && p2.first == false) break;
		if (p1.second) Rhole = true;
		if (p2.second) Bhole = true;
	}
	return { Rhole,Bhole };
}


int main() {
	cin >> n >> m;
	vector<string> s(n);
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'B') { bx = i; by = j; s[i][j] = '.'; }
			if (s[i][j] == 'R') { rx = i; ry = j; s[i][j] = '.'; }
		}
	}
	memset(d, -1, sizeof(d));
	queue<info> q;
	q.push({ rx,ry,bx,by });
	d[rx][ry][bx][by] = 0;
	int ans = -1, found = false;
	while (!q.empty()) {
		int rx = q.front().irx, ry = q.front().iry, bx = q.front().ibx, by = q.front().iby;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			//기울인다.
			pair<bool, bool> holes = next(s, nrx, nry, nbx, nby, i);
			if (holes.second) continue;
			if (holes.first) {
				ans = d[rx][ry][bx][by] + 1;
				found = true;
				break;
			}
			
			//이전에 방문했다면
			if (d[nrx][nry][nbx][nby] != -1) continue;
			d[nrx][nry][nbx][nby] = d[rx][ry][bx][by] + 1;
			q.push({ nrx,nry,nbx,nby });
		}
		//정답 찾은 경우
		if (found) break;
	}
	cout << ans;
	//cout << (ans > 10 ? -1 : ans);
}