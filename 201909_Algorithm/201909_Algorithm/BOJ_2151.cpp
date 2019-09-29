/*BOJ 2151 거울 설치*/
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n, ans = 2147483647, flag = true;
int check[51][51][4];
char map[51][51];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int transDir1[] = { 3,2,1,0 };	// '/' 일때
int transDir2[] = { 2,3,0,1 };	// '\' 일때
struct info {
	int x, y, dir, cnt;
};
struct cmp {
	bool operator()(info a, info b) {
		return a.cnt > b.cnt;
	}
};
priority_queue<info,vector<info>, cmp> q;

void bfs() {
	while (!q.empty()) {
		int x = q.top().x, y = q.top().y, dir = q.top().dir, cnt = q.top().cnt;
		q.pop();
		
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		
		if (map[nx][ny] == '*') continue;

		if (map[nx][ny] == '.') {
			if (check[nx][ny][dir] == -1 || cnt < check[nx][ny][dir]) {
				check[nx][ny][dir] = cnt;
				q.push({ nx,ny,dir,cnt });
			}
		}
		else if (map[nx][ny] == '!') {
			if (check[nx][ny][dir] == -1 || cnt< check[nx][ny][dir]) {
				check[nx][ny][dir] = cnt;
				q.push({ nx,ny,dir,cnt });
			}
			
			if (check[nx][ny][transDir1[dir]] == -1 || cnt + 1 < check[nx][ny][transDir1[dir]]) {
				check[nx][ny][transDir1[dir]] = cnt + 1;
				q.push({ nx,ny,transDir1[dir],cnt+1 });
			}
			if (check[nx][ny][transDir2[dir]] == -1 || cnt + 1 < check[nx][ny][transDir2[dir]]) {
				check[nx][ny][transDir2[dir]] = cnt + 1;
				q.push({ nx,ny,transDir2[dir],cnt + 1 });
			}
		}
		else if (map[nx][ny] == '#') {
			if (check[nx][ny][dir] == -1) {
				ans = cnt;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(check, -1, sizeof(check));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (flag && map[i][j] == '#') {
				for (int z = 0; z < 4; z++) {
					check[i][j][z] = 0;
					q.push({ i,j,z,0 });
				}
				flag = false;
			}
		}
	}
	bfs();
	cout << ans;
}