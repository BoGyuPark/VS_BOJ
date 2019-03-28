#include<iostream>
#include<vector>
using namespace std;
int map[10][10], n;
vector<pair<int, int>> zero;
bool poss(int num, int x, int y) {
	int rx = x / 3 * 3, ry = y / 3 * 3;
	for (int i = 0; i < 9; i++) {
		if (map[x][i] == num || map[i][y] == num) return false;
	}
	for (int i = rx; i < rx + 3; i++) {
		for (int j = ry; j < ry + 3; j++) 
			if (map[i][j] == num) return false;
	}
	return true;
}

void dfs(int index) {
	if (index == n) {
		for (int z = 0; z < 9; z++) {
			for (int j = 0; j < 9; j++) cout << map[z][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 0; i < 9; i++) {
		if (poss(i + 1, zero[index].first, zero[index].second)) {
			map[zero[index].first][zero[index].second] = i + 1;
			dfs(index + 1);
			map[zero[index].first][zero[index].second] = 0;
		}		
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zero.push_back({ i,j });
			}
		}
	}
	n = zero.size();
	dfs(0);
}