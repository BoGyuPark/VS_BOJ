#include<iostream>
using namespace std;
int T = 10, tc, n;
#define MAX 100
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (T--) {
		int map[MAX][MAX + 2] = { 0, };
		cin >> tc;
		int ex, ey;
		for (int i = 0; i < MAX; i++) {
			for (int j = 1; j <= MAX; j++){
				cin >> map[i][j];
				if (map[i][j] == 2) {ex = i; ey = j;}
			}
		}
		int ans = 0;
		for (int i = 1; i <= MAX; i++) {
			if (map[0][i] == 1) {
				int col = i;
				for (int j = 0; j < MAX; j++) {
					int row = j;
					int l = col - 1, r = col + 1;
					if (map[row][l] == 1) {
						while (map[row][l] == 1 && l >= 0) {
							l--;
							col = l + 1;
						}
					}
					else {
						while (map[row][r] == 1 && r <= MAX) {
							r++;
							col = r - 1;
						}
					}
					if (row==ex && col==ey) ans = i - 1;
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}