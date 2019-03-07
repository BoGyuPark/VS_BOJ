#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 10
using namespace std;
int sel[10], n, m, rflag, bflag;
int RX, RY, BX, BY, found = false;
//          �� �� �� ��
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
vector<string> a, t;
vector<int> ans;
void roll(int &rx, int &ry, int &bx, int &by, int dir) {
	int rf = false;
	//����̴� ������ ���� R�� ���� �������� B�� ���� �������� check
	if (dir == 0) {
		//���� ���ڰ� ������ ����
		if (rx < bx) rf = true;
	}
	else if (dir == 1) {
		//���� ���ڰ� ������ ����
		if (ry < by) rf = true;

	}
	else if (dir == 2) {
		//���� ���ڰ� ū�� ����
		if (rx > bx) rf = true;
	}
	else {
		//���� ���ڰ� ū �ͺ���
		if (ry > by) rf = true;
	}

	for (int i = 0; i < 2; i++) {
		if (rf) {
			char r = t[rx + dx[dir]][ry + dy[dir]];
			while (r == '.' || r == 'O') {
				if (r == 'O') {
					rflag = true;
					t[rx][ry] = '.';
					break;
				}
				else {
					t[rx][ry] = '.';
					t[rx + dx[dir]][ry + dy[dir]] = 'R';
					rx += dx[dir];
					ry += dy[dir];
					r = t[rx + dx[dir]][ry + dy[dir]];
				}
			}
			rf = false;
		}
		else {
			char b = t[bx + dx[dir]][by + dy[dir]];
			while (b == '.' || b == 'O') {
				if (b == 'O') {
					bflag = true;
					t[bx][by] = '.';
					break;
				}
				else {
					t[bx][by] = '.';
					t[bx + dx[dir]][by + dy[dir]] = 'B';
					bx += dx[dir];
					by += dy[dir];
					b = t[bx + dx[dir]][by + dy[dir]];
				}
			}
			rf = true;
		}
	}
	
}

void dfs(int index) {
	if (index == MAX) {
		//t��� ������ ����
		found = false;
		t = a;
		//������ 10���� �̸� ���Ͽ� �� �����϶����� ������ ������.
		int rx = RX, ry = RY, bx = BX, by = BY;
		for (int j = 0; j < MAX; j++) {
			rflag = false; bflag = false;
			roll(rx, ry, bx, by, sel[j]);
			if (bflag == true) break;
			if (rflag == true) {
				ans.push_back(j + 1);
				break;
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (index != 0) {
			//������ ¦���϶�
			if (sel[index - 1] % 2 == 0) {
				if (i % 2 == 0) continue;
				sel[index] = i;
				dfs(index + 1);
			}
			//Ȧ�� �϶�
			else {
				if (i % 2 == 1) continue;
				sel[index] = i;
				dfs(index + 1);
			}
		}
		else {
			sel[index] = i;
			dfs(index + 1);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		a.push_back(s);
		for (int j = 0; j < m; j++) {
			if (s[j] == 'B') { BX = i; BY = j; }
			else if (s[j] == 'R') { RX = i; RY = j; }
		}
	}
	dfs(0);
	sort(ans.begin(), ans.end());
	cout << (ans.size() == 0 ? -1 : ans[0]);
}