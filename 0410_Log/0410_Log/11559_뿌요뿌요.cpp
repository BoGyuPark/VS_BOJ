#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
char a[12][6], color;
int c[12][6], ans = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0, };
queue<pair<int, int>> q;
vector<pair<int, int>> v;
void printMap() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) cout << a[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void downMap() {
	for (int col = 0; col < 6; col++) {
		int emptyCnt = 0;
		for (int r = 11; r >= 0; r--) {
			if (a[r][col] == '.') emptyCnt++;
			else {
				char temp = a[r][col];
				a[r][col] = '.';
				a[r + emptyCnt][col] = temp;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) cin >> a[i][j];

	while (true) {
		memset(c, 0, sizeof(c));
		int flag = 0;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (a[i][j] != '.') {
					color = a[i][j];
					q.push({ i,j });
					v.push_back({ i,j });
					c[i][j] = true;
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second;
						q.pop();
						for (int z = 0; z < 4; z++) {
							int nx = x + dx[z], ny = y + dy[z];
							if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
							if (c[nx][ny]) continue;
							if (a[nx][ny] == color) {
								v.push_back({ nx,ny });
								q.push({ nx,ny });
								c[nx][ny] = true;
							}
						}
					}
					if (v.size() >= 4) {
						for (int z = 0; z < v.size(); z++) {
							a[v[z].first][v[z].second] = '.';
						}
						flag++;
					}
					v.clear();
				}
			}
		}
		//ม฿ทย
		downMap();
		//printMap();
		if (flag > 0) ans++;
		else break;
	}
	cout << ans;

}