/*BOJ 16918 º½¹ö¸Ç*/
#include<iostream>
using namespace std;
int n, m, t, check[201][201];
char map[201][201];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << map[i][j];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') check[i][j] = 2;
		}
	}

	int T = 1;
	while (true) {
		if (T == t) break;

		//ÆøÅº ¼³Ä¡
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.') {
					map[i][j] = 'O';
					check[i][j] = 3;
				}
			}
		}

		//1ÃÊ Ãß°¡
		T++;
		//ÆøÅº ½Ã°£ °¨¼Ò
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'O') {
					check[i][j]--;
				}
			}
		}
		if (T == t) break;
		//1ÃÊ Ãß°¡
		T++;
		//ÆøÅº Æø¹ß
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 'O' && check[i][j]==1) {
					map[i][j] = '.';
					for (int z = 0; z < 4; z++) {
						int nx = i + dx[z], ny = j + dy[z];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (check[i][j] < check[nx][ny] && map[nx][ny]=='O') {
							map[nx][ny] = '.';
							check[nx][ny] = 0;
						}
					}
					check[i][j] = 0;
				}
			}
		}
		if (T == t) break;
	}
	printMap();
}