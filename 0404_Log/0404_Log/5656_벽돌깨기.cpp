#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T, tc, n, w, h, a[15][12], cpy[15][12], sel[4], stoneCnt, c[15][12], ans, found;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void downStone() {
	//down
	for (int j = 0; j < w; j++) {
		int icnt = 0;
		for (int i = h - 1; i >= 0; i--) {
			if (cpy[i][j] >= 1) {
				cpy[h - 1 - icnt][j] = cpy[i][j];
				if (h - 1 - icnt != i) cpy[i][j] = 0;
				icnt++;
			}
		}
	}

}

//void downStone() {
//	for (int i = 0; i < w; i++) {
//		int emptyCnt = 0, temp = 0;
//		for (int j = h - 1; j >= 0; j--) {
//			int row = j;
//			if (cpy[row][i] == 0) {
//				emptyCnt++;
//			}
//			else {
//				temp = cpy[row][i];
//				cpy[row][i] = 0;
//				int t = emptyCnt;
//				while (t--) {
//					row++;
//				}
//				cpy[row][i] = temp;
//			}
//		}
//	}
//}

int simulation(int col) {
	//해당 열에서 가장 위에있는 벽돌의 행을 구한다.
	int row = -1, SumStone = 1;
	for (int i = 0; i < h; i++) {
		if (cpy[i][col] > 0) {
			row = i;
			break;
		}
	}
	//해당 열은 벽돌이 없으므로 통과
	if (row == -1) return 0;
	else {
		if (cpy[row][col] == 1) {
			cpy[row][col] = 0;
			return 1;
		}
		else {
			queue<pair<int, int>> q;
			q.push({ row,col });
			c[row][col] = true;
			//cpy[row][col] = 0;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				int Limit = cpy[x][y] - 1;
				cpy[x][y] = 0;
				q.pop();
				for (int i = 0; i < 4; i++) {
					for (int j = 1; j <= Limit; j++) {
						int nx = x + dx[i] * j, ny = y + dy[i] * j;
						if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
						if (c[nx][ny]) continue;
						if (cpy[nx][ny] > 0) {
							q.push({ nx,ny });
							c[nx][ny] = true;
							SumStone++;
						}
					}
				}
			}
			return SumStone;
		}
	}
}

void dfs(int index) {
	if (found) return;
	if (index == n) {
		int returnCnt = 0;
		for (int j = 0; j < n; j++) {
			memset(c, 0, sizeof(c));
			returnCnt += simulation(sel[j]);
			//중력으로 내려준다.
			downStone();
		}
		if (returnCnt == stoneCnt) {
			ans = returnCnt;
			found = true;
			return;
		}
		if (returnCnt > ans) ans = returnCnt;

		//맵복사
		for (int z = 0; z < h; z++) for (int e = 0; e < w; e++)	cpy[z][e] = a[z][e];
		return;
	}

	for (int i = 0; i < w; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> w >> h;
		stoneCnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
				cpy[i][j] = a[i][j];
				if (a[i][j] > 0) stoneCnt++;
			}
		}
		ans = -1;
		found = false;
		dfs(0);
		cout << '#' << tc << ' ' << stoneCnt - ans << '\n';
	}
}