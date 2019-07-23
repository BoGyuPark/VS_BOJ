/*BOJ 1983 통나무 옮기기*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[] = { -1,1,0,0,0 };
int dy[] = { 0,0,-1,1,0 };
int n, ans, tx, ty, ex, ey;
int tongVerti, tarVerti, tongIdx, targetIdx;
char map[51][51];
int tong[3][2], target[3][2], check[2][51][51];
typedef struct info {
	int verti, x, y;
};
queue<info> q;

bool checkVerti(int arr[3][2]) {
	if (arr[0][0] - arr[1][0] == 0) return false;
	else return true;
}

bool RotationBoundary(int nx, int ny) {
	for (int z = nx - 1; z < nx + 2; z++) {
		for (int a = ny - 1; a < ny + 2; a++) {
			if (map[z][a] == '1') return false;
		}
	}
	return true;
}

bool checkBoundary(int x, int y) {
	
	if (x < 0 || y < 0 || x >= n || y >= n) return false;
	if (map[x][y] == '1') return false;
	return true;
}

bool isPossible(int x, int y, int dir, int verti) {
	//세로
	if (verti == 1) {
		if (checkBoundary(x - 1, y) && checkBoundary(x, y) && checkBoundary(x + 1 , y)) {
			return true;
		}
		else return false;
	}
	//가로
	else {
		if (checkBoundary(x, y - 1) && checkBoundary(x, y) && checkBoundary(x, y + 1)) {
			return true;
		}
		else return false;
	}
}

void bfs() {
	memset(check, -1, sizeof(check));
	info info = { tongVerti,tx,ty };
	q.push(info);
	check[tongVerti][tx][ty] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, verti = q.front().verti;
		q.pop();
		if (x == ex && y == ey && verti== tarVerti) {
			ans = check[verti][x][y];
			break;
		}
		//상하좌우 회전
		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i], ny = y + dy[i], nverti = verti;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == '1') continue;
			//가로-> 세로로 , 세로->가로로 변경전에 체크한다.
			if (i == 4) {
				if (RotationBoundary(nx, ny)) {
					nverti = (verti + 1) % 2;
				}
				else continue;
			}
			if (isPossible(nx, ny, i, nverti)) {
				if (check[nverti][nx][ny] != -1) continue;
				check[nverti][nx][ny] = check[verti][x][y] + 1;
				q.push({ nverti,nx,ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				tong[tongIdx][0] = i;
				tong[tongIdx][1] = j;
				tongIdx++;
				map[i][j] = '0';
			}
			else if (map[i][j] == 'E') {
				target[targetIdx][0] = i;
				target[targetIdx][1] = j;
				targetIdx++;
				map[i][j] = '0';
			}
		}
	}

	tongVerti = checkVerti(tong);
	tarVerti = checkVerti(target);

	//중앙값
	tx = tong[1][0], ty = tong[1][1];
	ex = target[1][0], ey = target[1][1];

	bfs();
	cout << ans;
}