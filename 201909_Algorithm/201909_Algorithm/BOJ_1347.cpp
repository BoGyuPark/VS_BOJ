/*BOJ 1347 미로 만들기*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
char map[101][101];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	int x = 50, y = 50, dir = 1;
	map[x][y] = '.';
	int r_min, r_max, c_min, c_max;
	r_min = r_max = c_min = c_max = 50;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'F') {
			map[x + dx[dir]][y + dy[dir]] = '.';
			r_min = min(r_min, x + dx[dir]);
			r_max = max(r_max, x + dx[dir]);
			c_min = min(c_min, y + dy[dir]);
			c_max = max(c_max, y + dy[dir]);
			x += dx[dir], y += dy[dir];
		}
		else if (s[i] == 'R') dir = (dir + 1) % 4;
		else if (s[i] == 'L') dir = (dir + 3) % 4;
	}
	for (int i = r_min; i <= r_max; i++) {
		for (int j = c_min; j <= c_max; j++) {
			if (map[i][j] != '.') map[i][j] = '#';
			cout << map[i][j];
		}
		cout << '\n';
	}
}