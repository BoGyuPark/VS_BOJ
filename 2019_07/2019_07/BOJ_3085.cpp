/*BOJ 3085 사탕 게임*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, ans;
char map[51][51];
void row_check(int row, int col, int flag) {
	int cnt = 1;
	for (int i = col; i < n - 1; i++) {
		if (map[row + flag][i] == map[row + flag][i + 1]) cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 1;
		}
		ans = max(ans, cnt);
	}
}
void col_check(int row, int col, int flag) {
	int cnt = 1;
	for (int i = row; i < n - 1; i++) {
		if (map[i][col+ flag] == map[i + 1][col + flag]) cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 1;
		}
		ans = max(ans, cnt);
	}
}

void len_row_check(int row, int col) {
	row_check(row, 0, 0);
	col_check(0, col, 0);
	col_check(0, col, 1);
}

void len_col_check(int row, int col) {
	col_check(0, col, 0);
	row_check(row, 0, 0);
	row_check(row, 0, 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
	ans = 1;
	//swap안한 상태에서 돌리기
	int temp = 1;
	for (int i = 0; i < n; i++) {
		temp = 1;
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) temp++;
			else {
				ans = max(ans, temp);
				temp = 1;
			}
		}
		ans = max(ans, temp);
	}
	temp = 1;
	for (int i = 0; i < n; i++) {
		temp = 1;
		for (int j = 0; j < n - 1; j++) {
			if (map[j][i] == map[j + 1][i]) temp++;
			else {
				ans = max(ans, temp);
				temp = 1;
			}
		}
		ans = max(ans, temp);
	}

	//행에서 swap
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(map[i][j], map[i][j + 1]);
			len_row_check(i, j);
			swap(map[i][j + 1], map[i][j]);
		}
	}
	//열에서 swap
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(map[j][i], map[j+1][i]);
			len_col_check(j, i);
			swap(map[j+1][i], map[j][i]);
		}
	}
	cout << ans;
}