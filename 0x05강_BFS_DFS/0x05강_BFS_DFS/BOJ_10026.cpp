#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, c1[101][101], c2[101][101], normal = 0, rg = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[101][101], b[101][101];
void bfs(int i, int j, char t, char m[101][101], int c[101][101]) {
	queue<pair<int, int> > q;
	q.push({ i,j }); c[i][j] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int z = 0; z < 4; z++) {
			int nx = x + dx[z], ny = y + dy[z];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (m[nx][ny] == t && c[nx][ny] == false) {
					c[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			//R을 G로 바꾸어 b map을 변경
			if (a[i][j] == 'R') b[i][j] = 'G';
			else b[i][j] = a[i][j];
		}
	//normal, rg의 개수 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c1[i][j] == false) {
				bfs(i, j, a[i][j], a, c1);
				normal++;
			}
			if (c2[i][j] == false) {
				bfs(i, j, b[i][j], b, c2);
				rg++;
			}
		}
	}
	cout << normal << ' ' << rg;
}