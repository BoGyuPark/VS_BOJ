/*BOJ 16985  Maaaaaaaaaze*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int map[5][5][5], check[5][5][5], cpy[5][5][5];
int sel[6], finalMap[5][5][5], visited[5][5][5];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
int ans = 2147483647;
const int n = 5;
typedef struct {
	int z, x, y;
}info;
queue<info> q;
void rotateMap(int mmap[][5], int rotateNum) {
	int temp[5][5] = { 0, };
	for (int t = 0; t < rotateNum; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = mmap[n - 1 - j][i];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mmap[i][j] = temp[i][j];
			}
		}
	}
}
int bfs() {
	memset(visited, -1, sizeof(visited));
	if (finalMap[0][0][0] == 0) return -1;
	q.push({ 0,0,0 });
	visited[0][0][0] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= n || nz >= n) continue;
			if (visited[nz][nx][ny] != -1) continue;
			if (finalMap[nz][nx][ny] == 1) {
				q.push({ nz,nx,ny });
				visited[nz][nx][ny] = visited[z][x][y] + 1;
			}
		}
	}
	return visited[4][4][4];
}

void go(int index) {
	if (index == n) {
		//각 층을 돌려준다.
		// 층, 행, 열
		for (int j = 0; j < n; j++) {
			rotateMap(map[j], sel[j]);
		}

		//이제 층을 섞어줍니다.
		int tmp[] = { 1,2,3,4,5 };

		do {
			for (int x = 0; x < 5; x++) {
				for (int a = 0; a < 5; a++) {
					for (int b = 0; b < 5; b++) {
						finalMap[x][a][b] = map[tmp[x] - 1][a][b];
					}
				}
			}

			//결과 값을 추출한다. bfs
			int tempAns = bfs();
			//cout << tempAns << '\n';
			if (tempAns != -1&& ans>tempAns) ans = tempAns;

		} while (next_permutation(tmp, tmp + 5));

		//map copy
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				for (int c = 0; c < n; c++) {
					map[a][b][c] = cpy[a][b][c];
				}
			}
		}

		return;
	}
	for (int i = 0; i < 4; i++) {
		sel[index] = i;
		go(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {
				cin >> map[i][j][z];
				cpy[i][j][z] = map[i][j][z];
			}
		}
	}
	//5개층에서 회전을 먼저 정한다.
	go(0);
	if (ans == 2147483647) ans = -1;
	cout << ans;
}