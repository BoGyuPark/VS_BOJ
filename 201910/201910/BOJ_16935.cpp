/*BOJ 16935 배열 돌리기 3*/
#include<iostream>
using namespace std;
int n, m, R, map[101][101], cpy[101][101];
void cpyMap(int sx, int sy, int maxRow, int maxCol) {
	for (int i = sx; i < maxRow; i++) {
		for (int j = sy; j < maxCol; j++) {
			map[i][j] = cpy[i][j];
		}
	}
}
void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << map[i][j] << ' ';
		cout << '\n';
	}
}
void upDown() {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m; j++) swap(map[i][j], map[n - 1 - i][j]);
	}
}
void leftRight() {
	for (int j = 0; j < m / 2; j++) {
		for (int i = 0; i < n; i++) swap(map[i][j], map[i][m - 1 - j]);
	}
}
void rightRotate() {
	swap(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cpy[i][j] = map[m - 1 - j][i];
		}
	}
	cpyMap(0, 0, n, m);
}
void leftRotate() {
	swap(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cpy[i][j] = map[j][n - 1 - i];
		}
	}
	cpyMap(0, 0, n, m);
}
void partRightRotate() {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			int temp = map[i][j];
			map[i][j] = map[i + n / 2][j];
			map[i + n / 2][j] = map[i + n / 2][j + m / 2];
			map[i + n / 2][j + m / 2] = map[i][j + m / 2];
			map[i][j + m / 2] = temp;
		}
	}
}
void partLeftRotate() {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			int temp = map[i][j];
			map[i][j] = map[i][j + m / 2];
			map[i][j + m / 2] = map[i + n / 2][j + m / 2];
			map[i + n / 2][j + m / 2] = map[i + n / 2][j];
			map[i + n / 2][j] = temp;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> map[i][j];
	}
	for (int i = 0; i < R; i++) {
		int order; cin >> order;
		if (order == 1) upDown();
		else if (order == 2) leftRight();
		else if (order == 3) rightRotate();
		else if (order == 4) leftRotate();
		else if (order == 5) partRightRotate();
		else partLeftRotate();
	}
	printMap();
}