#include<iostream>
#include<vector>
#include<deque>
#include<cstring>
using namespace std;
int n, k, x, y, l, a[101][101], check[101][101], dir = 0, time = 0;;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
deque<pair<int, char>> dirinfo;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		a[x - 1][y - 1] = -1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t; char t1;
		cin >> t >> t1;
		dirinfo.push_back({ t,t1 });
	}
	deque<pair<int, int>> s;
	s.push_back({ 0,0 });
	while (true) {
		//초기 뱀의 위치들을 check한다.
		for (int i = 0; i < s.size(); i++) 	check[s[i].first][s[i].second] = true;
		if (dirinfo.size() > 0) {
			if (time == dirinfo.front().first) {
				char c = dirinfo.front().second;
				if (c == 'L') 	dir = (dir + 3) % 4;
				else dir = (dir + 1) % 4;
				dirinfo.pop_front();
			}
		}
		x = s.front().first; y = s.front().second;
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			//먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
			if (check[nx][ny] == false) {
				s.push_front({ nx,ny });
				//사과가 있다면 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
				if (a[nx][ny] == -1) a[nx][ny] = 0;
				else s.pop_back();
			}
			//자기자신의 몸과 부딪히면 끝
			else break;
		}
		//벽에 부딪히면 끝
		else break;
		memset(check, 0, sizeof(check));
		time++;
	}
	cout << time + 1;
}