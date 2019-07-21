/*BOJ 2580 ½ºµµÄí*/
#include<iostream>
#include<vector>
using namespace std;
int map[9][9];
vector<pair<int, int>> insert_pos;
bool finishFlag;
void printMap() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool check_sudoku(int row, int col, int target) {
	for (int i = 0; i < 9; i++) {
		if (map[row][i] == target || map[i][col] == target) return false;
	}
	int nrow = (row / 3) * 3;
	int ncol = (col / 3) * 3;
	for (int i = nrow; i < nrow + 3; i++) {
		for (int j = ncol; j < ncol + 3; j++) {
			if (map[i][j] == target) return false;
		}
	}
	return true;
}

void go(int index) {

	if (finishFlag) return;
	if (index == insert_pos.size()) {
		printMap();
		finishFlag = true;
		return;
	}

	for (int i = 1; i < 10; i++) {
		int r = insert_pos[index].first, c = insert_pos[index].second;
		if (check_sudoku(r, c, i)) {
			map[r][c] = i;
			go(index + 1);
			map[r][c] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) insert_pos.push_back({ i,j });
		}
	}
	go(0);
}