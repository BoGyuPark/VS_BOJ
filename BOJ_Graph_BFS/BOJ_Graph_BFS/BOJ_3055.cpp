#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
int r, c, water[51][51], mov[51][51], check[51][51], ddx, ddy, sx, sy;
char map[51][51];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
queue<pair<int, int> > q;
int main() {
	cin >> r >> c;
	string s;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == 'D' || s[j] == 'X') {
				if (s[j] == 'D') {
					ddx = i; 
					ddy = j;
				}
				water[i][j] = -1;
			}
			else if (s[j] == '*') {
				q.push(make_pair(i, j));
			}
			else if (s[j] == 'S') {
				sx = i; sy = j;
			}
			map[i][j] = s[j];
		}
	}
	int x, y, nx, ny;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		check[x][y] = true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i]; ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (check[nx][ny] == false && water[nx][ny] == 0) {
					check[nx][ny] = true; q.push(make_pair(nx, ny));
					water[nx][ny] = water[x][y] + 1;
				}
			}
		}
	}
	memset(check, 0, sizeof(check));
	q.push(make_pair(sx, sy));
	mov[sx][sy] = 1;
	bool flag = 0;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		check[x][y] = true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i]; ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (check[nx][ny] == false) {
					if (water[nx][ny] > mov[x][y] || water[nx][ny] == 0) {
						check[nx][ny] = true; q.push(make_pair(nx, ny));
						mov[nx][ny] = mov[x][y] + 1;
					}
					else if (nx == ddx && ny == ddy) {
						flag = 1;
						cout << mov[x][y];
						while (!q.empty()) {
							q.pop();
						}
						break;
					}
					
				}
			}
		}
	}
	if (flag == 0) {
		cout << "KAKTUS";
	}
	return 0;
}