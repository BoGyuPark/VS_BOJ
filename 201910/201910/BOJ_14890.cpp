/* BOJ 14890 경사로*/
#include<iostream>
#include<cstring>
using namespace std;
int n, L, map[101][101], colMap[101][101], checkmap[101][101], ans;
int dy[] = { -1,1 };
bool isInsert(int r, int c, int dir) {
	int y = c;
	int h = map[r][c];
	int ny = y + dy[dir];
	int cnt = 1;
	for (int i = 0; i < L - 1; i++) {
		if (ny < 0 || ny >= n || checkmap[r][ny]) break;

		if (h == map[r][ny]) {
			cnt++;
			ny += dy[dir];
		}
	}
	if (cnt == L) {
		for (int i = 0; i < L; i++) {
			checkmap[r][y] = true;
			y += dy[dir];
		}
		return true;
	}
	else return false;
}

bool isPossible(int r) {

	for (int i = 0; i < n - 1; i++) {
		if (map[r][i] < map[r][i + 1]) {
			if (map[r][i] + 1 == map[r][i + 1]) {
				if (!checkmap[r][i] && isInsert(r, i, 0)) {

				}
				else return false;
			}
			//증가하지만 높이 차이가 2이상 일 때
			else return false;

		}
		else if (map[r][i] > map[r][i + 1]) {
			if (map[r][i] == map[r][i + 1] + 1) {
				if (!checkmap[r][i + 1] && isInsert(r, i + 1, 1)) {
					i += L - 1;
				}
				else return false;
			}
			// 감소하지만 높이 차이가 2이상 일 때
			else return false;

		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			colMap[j][i] = map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (isPossible(i)) ans++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = colMap[i][j];
		}
	}

	memset(checkmap, 0, sizeof(checkmap));
	for (int i = 0; i < n; i++) {
		if (isPossible(i)) ans++;
	}
	cout << ans;
}