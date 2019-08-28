/*SWEA 1220 Magnetic*/
#include<iostream>
using namespace std;
int T, map[101][101], n, ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int tc = 1; tc <= 10; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
		ans = 0;
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {

				if (map[i][j] == 1) {
					int row = i;
					while (true) {
						if (map[row + 1][j] == 2) {
							ans++;
							i = row + 1;
							break;
						}
						row++;
						if (row >= n) {
							i = row;
							break;
						}
					}
				}

			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}