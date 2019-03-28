#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int tc, T, r, c;
char a[20][20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int op[128];
int flag = false;
int visited[16][4][20][20];
void dfs(int i, int j, int dir, int me) {
	if (flag) return;
	//종료 시점 만들자 (언제 @에 안들어가고 무의미하단걸 알까?)
	while (true) {
		if (visited[me][dir][i][j] == true) return;
		visited[me][dir][i][j] = true;
		char t = a[i][j];
		if (t == '<' ||t=='>' || t=='v' || t=='^') {
			dir = op[t];
		}
		else if (t == '_') {
			if (me == 0) dir = 0;
			else dir = 1;
		}
		else if (t == '|') {
			if (me == 0) dir = 2;
			else dir = 3;
		}
		else if (t == '?') {
			for (int d = 0; d < 4; d++) {
				//다음 좌표가 벽이 밖인 경우
				int nx = i + dx[d], ny = j + dy[d];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
					if (d == 0) j = 0;
					else if (d == 1) j = c;
					else if (d == 2) i = 0;
					else i = r;
				}
				else {
					i += dx[d]; j += dy[d];
				}
				dfs(i, j, d, me);		
			}
		}
		//프로그램 정지되는 경우
		else if (t == '@') {
			flag = true;
			return;
		}
		else if (t >= '0' && t <= '9') {
			me = t - '0';
		}
		else if (t == '+') {
			if (me == 15) me = 0;
			else me += 1;
		}
		else if (t == '-') {
			if (me == 0) me = 15;
			else me -= 1;
		}

		//다음 좌표가 벽이 밖인 경우
		int nx = i + dx[dir], ny = j + dy[dir];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
			if (dir == 0) j = 0;
			else if (dir == 1) j = c;
			else if (dir == 2) i = 0;
			else i = r;
		}
		else {
			i += dx[dir]; j += dy[dir];
		}
		//cout << me << ' ' << dir << ' ' << i << ' ' << j << '\n';
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> a[i][j];
		op['<'] = 1;	op['>'] = 0;	op['^'] = 3;	op['v'] = 2;
		dfs(0, 0, 0, 0);
		string s;
		if (flag) s = "YES";
		else s = "NO";
		cout << '#' << tc << ' ' << s << '\n';
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++) a[i][j] = 0;
		flag = false;
	}
}