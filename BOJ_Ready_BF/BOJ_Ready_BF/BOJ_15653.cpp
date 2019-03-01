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
//����������, ���ۿ� ��������
pair<bool, bool> simulate(vector<string> &a, int &x, int &y, int dir) {
	//R,B ������ ���ۿ� ���� �� R��B�� �ʿ��� ���� ���
	if (a[x][y] == '.') return{ false,false };
	bool move = false;
	
	while (true) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if (a[nx][ny] == '#') return { move,false };
		//�̵� �߿� ���� ��ǥ�� �ٸ� ������ �ִ� ���.
		else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') return { move,false };
		//��� �̵��� �ؾ��ϱ� ������ return ���� �ʴ´�.
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
//������ ���� ������ ������ �����δ�.
//���۷����� �ִ� ���� �ٽ�.
pair<bool, bool> next(vector<string> a, int &nrx, int &nry, int &nbx, int &nby, int dir) {
	//�ʿ� R�� B�� ����
	a[nrx][nry] = 'R';
	a[nbx][nby] = 'B';
	bool rflag = false, bflag = false;

	while (true) {
		//�ȿ���������, ���ۿ���������
		pair<bool, bool> p1 = simulate(a, nrx, nry, dir);
		pair<bool, bool> p2 = simulate(a, nbx, nby, dir);
		//�Ѵ� �� �̻� �ȿ����ΰ��
		if (p1.first == false && p2.first == false) break;
		if (p1.second) rflag = true;
		if (p2.second) bflag = true;
	}
	return { rflag,bflag };
}
int main() {
	cin >> n >> m;
	//R�� B�� ��ǥ�� �޾ƿ´�.
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
	//������ ã����� while Ż�����Ͽ�
	bool found = false;
	while (!q.empty()) {
		int rx = q.front().irx, ry = q.front().iry;
		int bx = q.front().ibx, by = q.front().iby;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			//  R ����, B ����
			pair<bool, bool> holestate = next(a, nrx, nry, nbx, nby, i);
			if (holestate.second) continue;
			if (holestate.first) {
				found = true;
				ans = d[rx][ry][bx][by] + 1;
				break;
			}
			//�湮�Ѱ��̸� (nrx,nry,nbx,nby�� �� �� ��������ν� ��ǥ�� �ٲ�)
			if (d[nrx][nry][nbx][nby] != -1) continue;
			q.push({ nrx,nry,nbx,nby });
			d[nrx][nry][nbx][nby] = d[rx][ry][bx][by] + 1;
		}
		if (found) break;
	}
	cout << ans;
}