/*BOJ 4574 스도미노쿠*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n, domino[10][10], map[9][9];
int row[10][10], col[10][10], sector[10][10];
int dx[] = { 0,1 };
int dy[] = { 1,0 };
bool finishFlag;

void printMap() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void init_sudoku(int r, int c, bool flag) {
	row[r][map[r][c]] = flag;
	col[c][map[r][c]] = flag;
	sector[r / 3 * 3 + c / 3][map[r][c]] = flag;
}

bool check_sudoku(int x, int y, int num) {
	return !row[x][num] && !col[y][num] && !sector[x / 3 * 3 + y / 3][num];
}

void go(int index) {
	if (finishFlag) return;
	if (index == 81) {
		printMap();
		finishFlag = true;
		return;
	}

	int x = index / 9, y = index % 9;
	if (map[x][y] != 0) {
		go(index + 1);
		if (finishFlag) return;
	}
	else {
		for (int z = 0; z < 2; z++) {
			//다음위치 insert 가능한지 체크
			int nx = x + dx[z], ny = y + dy[z];
			if (nx < 0 || ny < 0 || nx >= 9 || ny >= 9) continue;
			if (map[nx][ny] != 0) continue;

			//원 위치와 다음 위치에 숫자 넣을 때 스도쿠 가능한지 체크한다.
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					if (i == j) continue;
					if (domino[i][j]) continue;

					if (check_sudoku(x, y, i) && check_sudoku(nx, ny, j)) {
						map[x][y] = i;
						map[nx][ny] = j;
						init_sudoku(x, y, true);
						init_sudoku(nx, ny, true);
						domino[i][j] = domino[j][i] = true;

						go(index + 1);
						if (finishFlag) return;

						domino[i][j] = domino[j][i] = false;
						init_sudoku(x, y, false);
						init_sudoku(nx, ny, false);
						map[x][y] = 0;
						map[nx][ny] = 0;
					}
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			int u, v;
			string lu, lv;
			cin >> u >> lu >> v >> lv;
			int u_row = lu[0] - 'A', u_col = lu[1] - '0' - 1;
			int v_row = lv[0] - 'A', v_col = lv[1] - '0' - 1;
			map[u_row][u_col] = u;
			map[v_row][v_col] = v;

			domino[u][v] = domino[v][u] = true;
			
			init_sudoku(u_row, u_col,true);
			init_sudoku(v_row, v_col,true);
		}
		for (int i = 1; i <= 9; i++) {
			string s; cin >> s;
			int s_row = s[0] - 'A', s_col = s[1] - '0' - 1;

			map[s_row][s_col] = i;
			init_sudoku(s_row, s_col, true);
		}
	
		cout << "Puzzle " << tc << '\n';
		tc++;
		finishFlag = false;
		go(0);
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(sector, 0, sizeof(sector));
		memset(map, 0, sizeof(map));
		memset(domino, 0, sizeof(domino));
	}
}