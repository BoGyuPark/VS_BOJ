/*2105. [모의 SW 역량테스트] 디저트 카페*/
#include<iostream>
#include<cstring>
using namespace std;
int T, tc, n, map[21][21], num[101], sel[2], ans;
int dx[] = { 1,1,-1,-1 };
int dy[] = { -1,1,1,-1 };

int Rotate(int i, int j) {

	int cnt = 0;
	int x = i, y = j;

	for (int z = 0; z < 4; z++) {

		int MAX = (z % 2 == 0 ? sel[0] : sel[1]);	//sel[0] : 가로, sel[1] 세로 길이

		for (int a = 0; a < MAX; a++) {

			int nx = x + dx[z], ny = y + dy[z];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) return -1;

			if (num[map[nx][ny]] == false) {
				cnt++;
				num[map[nx][ny]] = true;
			}
			else return -1;
			x = nx, y = ny;
			nx += dx[z], ny += dy[z];
		}
	}
	return cnt;
}

void simulate() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = Rotate(i, j);
			if (temp != -1 && ans < temp) ans = temp;
			memset(num, 0, sizeof(num));
		}
	}
}

void go(int index) {

	if (index == 2) {
		simulate();
		return;
	}
	for (int i = 0; i < n - 2; i++) {
		sel[index] = i + 1;
		go(index + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) cin >> map[i][j];
		
		ans = -1;
		go(0);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}