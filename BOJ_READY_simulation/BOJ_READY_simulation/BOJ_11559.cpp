#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int c[13][7], ans = 0, flag = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char a[13][7], al[5] = { 'R','G','B','P','Y' };
vector<pair<int, int>> p;
void dfs(int x, int y, int index) {
	c[x][y] = true;
	p.push_back({ x,y });
	char t = al[index];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 12 && ny < 6) {
			if (c[nx][ny] == false && a[nx][ny] == t) {
				dfs(nx, ny, index);
			}
		}
	}
}
void simulate() {
	vector<queue<char>> color(6);
	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >= 0; j--) {
			if (a[j][i] != '.') {
				color[i].push(a[j][i]);
				a[j][i] = '.';
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		int colsize = color[i].size();
		for (int j = 11; j > 11 - colsize; j--) {
			a[j][i] = color[i].front();
			color[i].pop();
		}
	}

}

void remove() {
	for (int i = 0; i < p.size(); i++) {
		int x = p[i].first, y = p[i].second;
		a[x][y] = '.';
	}
}

int main() {
	for (int i = 0; i < 12; i++) cin >> a[i];
	while (true) {
		flag = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (a[i][j] != '.') {
					for (int z = 0; z < 5; z++) {
						if (a[i][j] == al[z]) {
							dfs(i, j, z);
							if (p.size() >= 4) {
								remove();
								flag++;
							}
							p.clear();
							memset(c, 0, sizeof(c));
						}
					}
				}
				
			}
		}
		if (flag == 0) break;
		simulate();
		ans++;
	}
	cout << ans;
}