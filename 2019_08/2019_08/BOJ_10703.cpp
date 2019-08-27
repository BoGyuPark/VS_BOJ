#include<iostream>
#include<vector>
using namespace std;
int n, m, miniDist = 2147483647;
char map[3001][3001];
vector<pair<int, int>> v;
void findMiniDist() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		int d = 1, flag = false;
		while (true) {
			if (map[x + d][y] == '#') break;
			else if (map[x + d][y] == 'X') {
				flag = true;
				break;
			}
			else d++;
			if (d - 1 > miniDist) break;
		}
		if (!flag && d - 1 != 0 && miniDist > d - 1) miniDist = d - 1;
	}
}

void downMap() {
	for (int i = v.size() - 1; i >= 0; i--) {
		int x = v[i].first, y = v[i].second;
		map[x][y] = '.';
		x += miniDist;
		map[x][y] = 'X';
	}
}

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << map[i][j];
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'X') v.push_back({ i,j });
		}
	}

	findMiniDist();
	downMap();
	printMap();
}