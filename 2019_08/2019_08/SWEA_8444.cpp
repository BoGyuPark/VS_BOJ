#include<iostream>
#include<cstring>
using namespace std;
int T, tc, arr[102], n, map[102], ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 1 && map[i] == 0 || arr[i] == 0 && map[i] == 1) {
				for (int j = i; j <= n; j += i) map[j] = (map[j] + 1) % 2;
				ans++;
			}

			int cnt = 0;
			for (int j = 1; j <= n; j++) if (arr[j] == map[j]) cnt++;
			if (cnt == n) break;
		}
		
		cout << '#' << tc << ' ' << ans << '\n';
		memset(map, 0, sizeof(map));
	}
}
