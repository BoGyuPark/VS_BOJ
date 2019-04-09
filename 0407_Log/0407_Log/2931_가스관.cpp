#include<iostream>
#include<queue>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int mx, my, zx, zy, ansx, ansy;
int n, m, outDirs[25][25], inDirs, check[25][25];
char a[25][25], findBlock[100];
queue<pair<int, int>> q;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '|') outDirs[i][j] += 5;
			else if (a[i][j] == '-') outDirs[i][j] += 10;
			else if (a[i][j] == '+') outDirs[i][j] += 15;
			else if (a[i][j] == '1') outDirs[i][j] += 6;
			else if (a[i][j] == '2') outDirs[i][j] += 3;
			else if (a[i][j] == '3') outDirs[i][j] += 9;
			else if (a[i][j] == '4') outDirs[i][j] += 12;
			else if (a[i][j] == 'M') { mx = i, my = j; }
			else if (a[i][j] == 'Z') { zx = i, zy = j; }
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != 'M' && a[i][j] != 'Z' && a[i][j] != '.') {
				if (check[i][j] == true) continue;
				q.push({ i,j });
				check[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						if (outDirs[x][y] & (1 << z)) {
							int nx = x + dx[z], ny = y + dy[z];
							if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
							if (check[nx][ny] == true) continue;

							//파이프와 연결되지 않은 좌표에서 inDirs를 입력
							if (a[nx][ny] == '.') {
								ansx = nx, ansy = ny;
								inDirs += (1 << z);
							}
							else {
								q.push({ nx,ny });
								check[nx][ny] = true;
							}

						}
					}
				}
			}
		}
	}
	findBlock[3] = '4', findBlock[6] = '3', findBlock[12] = '2';
	findBlock[9] = '1', findBlock[15] = '+', findBlock[10] = '-';
	findBlock[5] = '|';
	//해당좌표의 indis값으로 어느 블록인지 찾는다.
	char c = findBlock[inDirs];
	cout << ansx + 1 << ' ' << ansy + 1 << ' ' << c;
}