/*BOJ 2447 º° Âï±â 10*/
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 2200
int n;
char map[MAX][MAX];
void go(int x, int y, int num) {
	if (num == 1) {
		map[x][y] = '*';
		return;
	}

	int div = num / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			go(x + (i*div), y + (j*div), div);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	memset(map, ' ', sizeof(map));
	go(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << map[i][j];
		cout << '\n';
	}
	return 0;
}