/* BOJ 2931 °¡½º°ü*/
#include<iostream>
using namespace std;
int n, m, destX, destY, destDirs, ans;
char map[26][26];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int dirs[] = { 0,10,9,5,6,3,12,15 };
int transDir[] = { 1,0,3,2 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '|') map[i][j] = '5';
			else if (map[i][j] == '-') map[i][j] = '6';
			else if (map[i][j] == '+') map[i][j] = '7';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ('1' <= map[i][j] && map[i][j] <= '7') {
				for (int z = 0; z < 4; z++) {
					if (dirs[map[i][j] - '0'] & (1 << z)) {
						int nx = i + dx[z], ny = j + dy[z];
						if (map[nx][ny] == '.') {
							destX = nx, destY = ny;
							destDirs += (1 << transDir[z]);
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= 7; i++) if (destDirs == dirs[i]) ans = i;
	cout << destX + 1 << ' ' << destY + 1 << ' ';
	if (ans == 5) cout << '|';
	else if (ans == 6) cout << '-';
	else if (ans == 7) cout << '+';
	else cout << ans;
}