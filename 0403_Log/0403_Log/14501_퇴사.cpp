#include<iostream>
using namespace std;
int n, t[16], p[16], sel[16], ans = -1;
void dfs(int index) {
	if (index == n) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (sel[j] == 1) {
				if (j + t[j] > n) continue;
				sum += p[j];
				j += t[j] - 1;
			}
		}
		if (ans < sum) ans = sum;
		return;
	}

	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i] >> p[i];
	dfs(0);
	cout << ans;
}