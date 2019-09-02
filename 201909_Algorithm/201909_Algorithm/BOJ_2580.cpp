/* BOJ 2580 스도쿠*/
#include<iostream>
#include<vector>
using namespace std;
int map[9][9], check[81], sector[10][10], row[10][10], col[10][10], flag;
const int n = 9;
vector<pair<int, int>> v;
void setSudo(int x, int y, int num, bool value) {
	row[x][num] = col[y][num] = sector[(x / 3) * 3 + y / 3 + 1][num] = value;
}
bool isPossible(int x, int y, int num) {
	//가로 체크, 세로 체크, 섹터 체크
	if (!row[x][num] && !col[y][num] &&
		!sector[(x / 3) * 3 + y / 3 + 1][num])
		return true;
	else return false;
}

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void go(int index) {
	if (flag) return;
	if (index == v.size()) {
		printMap();
		flag = true;
		return;
	}

	for (int j = 1; j <= 9; j++) {
		int x = v[index].first, y = v[index].second;
		if (isPossible(x, y, j)) {
			setSudo(x, y, j, true);
			map[x][y] = j;

			go(index + 1);

			if (flag) return;
			map[x][y] = 0;
			setSudo(x, y, j, false);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) v.push_back({ i,j });

			//섹터를 미리 세팅
			setSudo(i, j, map[i][j], true);
		}
	}
	go(0,0);
}