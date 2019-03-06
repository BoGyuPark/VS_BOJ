#include<iostream>
#include<deque>
using namespace std;
int n, k, l, x, a[103][103];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
char c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		//사과있는곳은 -1
		a[t1][t2] = -1;
	}
	cin >> l;
	deque<pair<int, int>> s;
	deque<pair<int, char>> dirinfo;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		dirinfo.push_back({ x,c });
	}
	//뱀의 처음
	s.push_back({ 1,1 });
	//뱀의 영역
	a[1][1] = 1;
	int t = 0;
	int dir = 1; // 오른쪽 방향
	while (true) {
		//초마다 확인하여 방향을 바꿔준다.
		if (dirinfo.size() > 0) {
			if (t == dirinfo.front().first) {
				char d = dirinfo.front().second;
				if (d == 'L') dir = (dir + 3) % 4;
				else dir = (dir + 1) % 4;
				dirinfo.pop_front();
			}
		}
		int x = s.front().first, y = s.front().second;
		int nx = x + dx[dir], ny = y + dy[dir];
		//벽에 부딪히면 종료
		if (nx<1 || ny<1 || nx>n || ny>n) break;
		//자기 몸과 부딪히면 종료
		if (a[nx][ny] == 1) break;
		s.push_front({ nx,ny });
		//사과가 없으면 꼬리를 자른다.
		if (a[nx][ny] != -1) {
			a[s.back().first][s.back().second] = 0;
			s.pop_back();
		}
		a[nx][ny] = 1;
		t++;
	}
	cout << t + 1;
}