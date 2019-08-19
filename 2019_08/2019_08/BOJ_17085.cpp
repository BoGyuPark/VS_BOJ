/*BOJ 십자가 2개 놓기*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, m, check[16][16], sel[2], c[230], ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char map[16][16];
vector<pair<int, int>> cross;

void simulate() {
	memset(check, 0, sizeof(check));
	int x1 = cross[sel[0]].first, y1 = cross[sel[0]].second;
	int x2 = cross[sel[1]].first, y2 = cross[sel[1]].second;
	
	int c1Size = 1, c2Size = 1;
	int c1Flag = 0, c2Flag = 0;
	check[x1][y1] = true;
	check[x2][y2] = true;
	int c1Area = 1, c2Area = 1;
	while (true) {

		c1Flag = false;
		for (int i = 0; i < 4; i++) {
			int nx = x1 + dx[i] * c1Size, ny = y1 + dy[i] * c1Size;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				c1Flag = true;
				break;
			}
			if (check[nx][ny] || map[nx][ny] == '.') {
				c1Flag = true;
				break;
			}
		}

		if (!c1Flag) {
			for (int i = 0; i < 4; i++) {
				int nx = x1 + dx[i] * c1Size, ny = y1 + dy[i] * c1Size;
				check[nx][ny] = true;
			}
			c1Size++;
			c1Area += 4;
		}

		c2Flag = false;
		for (int i = 0; i < 4; i++) {
			int nx = x2 + dx[i] * c2Size, ny = y2 + dy[i] * c2Size;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				c2Flag = true;
				break;
			}
			if (check[nx][ny] || map[nx][ny] == '.') {
				c2Flag = true;
				break;
			}
		}

		if (!c2Flag) {
			for (int i = 0; i < 4; i++) {
				int nx = x2 + dx[i] * c2Size, ny = y2 + dy[i] * c2Size;
				check[nx][ny] = true;
			}
			c2Size++;
			c2Area += 4;
		}

		if (ans < c1Area*c2Area) ans = c1Area * c2Area;

		if (c1Flag&&c2Flag) break;
	}
	
}
void go(int index,int start) {
	if (index == 2) {
		//십자가 중심점을 고르자.
		simulate();
		return;
	}
	for (int i = start; i < cross.size(); i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1, i);
		c[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') cross.push_back({ i,j });
		}
	}
	go(0, 0);
	cout << ans;
}