/*BOJ 16933 벽 부수고 이동하기3*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m, k;
int dx[] = { 0,0,-1,1,0 };
int dy[] = { 1,-1,0,0,0 };
int check[2][11][1001][1001];
char map[1001][1001];
typedef struct {
	int x, y, cnt, flag;
}info;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	cin >> map[i][j];
	queue<info> q;
	q.push({ 0,0,0,0 });	// 0: day , 1: night
	check[0][0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, cnt = q.front().cnt, flag = q.front().flag;
		q.pop();
		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			int nextFlag = (flag + 1) % 2;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nextFlag][cnt][nx][ny] != 0) continue;

			//벽 부수기 가능!
			if (cnt < k && flag == 0) {
				if (map[nx][ny] == '1') {
					check[nextFlag][cnt + 1][nx][ny] = check[flag][cnt][x][y] + 1;
					q.push({ nx,ny,cnt + 1,nextFlag });
				}
			}

			//제자리인데 방문한 칸의 개수를 하나 늘린다.
			if (map[nx][ny] == '0' || i == 4) {
				check[nextFlag][cnt][nx][ny] = check[flag][cnt][x][y] + 1;
				q.push({ nx, ny, cnt,nextFlag });
			}
		}
	}

	int ans = 2147483647;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < 2; j++) {
			if (check[j][i][n - 1][m - 1] != 0 && ans > check[j][i][n - 1][m - 1]) {
				ans = check[j][i][n - 1][m - 1];
			}
		}	
	}
	if (ans == 2147483647) ans = -1;
	cout << ans;
}