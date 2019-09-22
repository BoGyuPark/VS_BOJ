/*BOJ 1789 종이의 개수*/
#include<iostream>
using namespace std;
int n, map[2200][2200], cnt[3];
bool isSame(int N, int x, int y) {
	int num = map[x][y];
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (num != map[i][j]) return false;
		}
	}
	return true;
}
void go(int N, int x, int y) {
	if (N == 0) return;

	//종이가 모두 같은 수로 되어있는지 check
	if (isSame(N, x, y)) {
		cnt[map[x][y] + 1]++;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				go(N / 3, x + (N / 3 * i), y + (N / 3 * j));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	go(n, 0, 0);
	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}