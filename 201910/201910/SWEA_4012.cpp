#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, tc, n, map[17][17], ans;
vector<int> team1, team2;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
		ans = 2147483647;
		int sel[17] = { 0, };
		for (int i = n / 2; i < n; i++) sel[i] = 1;
		do {
			for (int i = 0; i < n; i++) {
				if (sel[i] == 0) team1.push_back(i);
				else team2.push_back(i);
			}
			int sum1 = 0, sum2 = 0;
			for (int i = 0; i < n / 2; i++) {
				for (int j = 0; j < n / 2; j++) {
					sum1 += map[team1[i]][team1[j]];
					sum2 += map[team2[i]][team2[j]];
				}
			}
			int dif = abs(sum1 - sum2);
			ans = min(ans, dif);
			team1.clear(), team2.clear();
		} while (next_permutation(sel, sel + n));
		cout << '#' << tc << ' ' << ans << '\n';
	}
}