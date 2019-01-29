#include<iostream>
using namespace std;
int map[10][10], row[10][10], col[10][10], area[10][10];
void go(int index) {
	if (index == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << ' ';
			}
			cout << "\n";
		}
		exit(0);
	}
	int x = index / 9; int y = index % 9;
	if (map[x][y] != 0) {
		go(index + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] == 0 && col[y][i] == 0 && area[(x / 3) * 3 + y / 3][i] == 0) {
				row[x][i] = col[y][i] = area[(x / 3) * 3 + y / 3][i] = true;
				map[x][y] = i;
				go(index + 1);
				row[x][i] = col[y][i] = area[(x / 3) * 3 + y / 3][i] = 0;
				map[x][y] = 0;
			}
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				row[i][map[i][j]] = true;
				col[j][map[i][j]] = true;
				area[(i / 3) * 3 + j / 3][map[i][j]] = true;
			}
		}
	}
	go(0);
}