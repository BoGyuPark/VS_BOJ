#include<iostream>
using namespace std;
int T, tc, n, l, t[20], k[20];
int ans;
void go(int index, int t_sum,  int k_sum) {
	if (k_sum > l) return;
	if (index == n) {
		if (ans < t_sum) ans = t_sum;
		return;
	}
	go(index + 1, t_sum + t[index], k_sum + k[index]);
	go(index + 1, t_sum, k_sum);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			cin >> t[i] >> k[i];
		}
		ans = -1;
		go(0, 0, 0);
		cout << "#" << tc << " " << ans << '\n';
	}
}