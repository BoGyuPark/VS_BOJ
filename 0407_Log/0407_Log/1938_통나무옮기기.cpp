#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
vector<pair<int, int>> v, e;	//통나무의 좌표
int n, c[50][50][2];
char a[50][50];
string s;
typedef struct info {
	int x, y, dir;
};
queue<info> q;
//        상 하 좌 우 회전
int dx[] = { -1,1,0,0,0 };
int dy[] = { 0,0,-1,1,0 };
int Rdx[] = { -1,-1,-1,0,0,1,1,1 };
int Rdy[] = { -1,0,1,-1,1,-1,0,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
			if (s[j] == 'B') {
				v.push_back({ i,j });
				s[j] = 0;
			}
			else if (s[j] == 'E') e.push_back({ i,j });
		}
	}
	//통나무가 세로로 있는지 가로로 있는지 체크
	int t = 0;	// t = 0 일때 세로
	if (v[0].first - v[1].first == 0) t = 1;	// t = 1 일때 통나무는 가로

	int ansDirs = 0;
	if (e[0].first - e[1].first == 0) ansDirs = 1;
	memset(c, -1, sizeof(c));
	q.push({ v[1].first,v[1].second,t });
	c[v[1].first][v[1].second][t] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, nowdir = q.front().dir;
		q.pop();
		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (a[nx][ny] == '1') continue;
			if (i == 4) {
				if (c[nx][ny][1 - nowdir] != -1) continue;
				int flag = false;
				for (int z = 0; z < 8; z++) {
					int nnx = nx + Rdx[z], nny = ny + Rdy[z];
					if (nnx < 0 || nny < 0 || nnx >= n || nny >= n || a[nnx][nny] == '1') {
						flag = true;
						break;
					}
				}
				if (!flag) {
					q.push({ nx,ny, 1 - nowdir });
					c[nx][ny][1- nowdir] = c[x][y][nowdir] + 1;
				}
			}
			else {
				if (c[nx][ny][nowdir] != -1) continue;
				//통나무 가로 (좌,우 확인)
				if (nowdir == 1) {
					//중심의 왼쪽과 오른쪽이 만족할 경우
					if (ny - 1 >= 0 && a[nx][ny - 1] != '1' &&
						(ny + 1 < n && a[nx][ny + 1] != '1')) {
						//
						q.push({ nx,ny,nowdir });
						c[nx][ny][nowdir] = c[x][y][nowdir] + 1;
					}
				}
				else {
					//중심의 위과 아래를 만족할 경우
					if (nx - 1 >= 0 && a[nx - 1][ny] != '1' &&
						(nx + 1 < n && a[nx + 1][ny] != '1')) {
						q.push({ nx,ny,nowdir });
						c[nx][ny][nowdir] = c[x][y][nowdir] + 1;
					}
				}
			}
		}
	}
	//ans1은 세로, ans2는 가로
	int ans1 = c[e[1].first][e[1].second][ansDirs];
	if (ans1 == -1) cout << 0;
	else cout << ans1;
}