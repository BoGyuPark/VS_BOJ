/*BOJ 16938 Ä·ÇÁ ÁØºñ*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, L, R, X, level[16], sel[16], ans;
void go(int index) {
	if (index == n) {
		int sum = 0, cnt = 0, mini = 2147483647, maxi = -1;
		for (int j = 0; j < n; j++) {
			if (sel[j]) {
				cnt++;
				mini = min(mini, level[j]);
				maxi = max(maxi, level[j]);
				sum += level[j];
			}
		}
		int dif = maxi - mini;
		if (cnt >= 2 && dif >= X && (sum >= L && sum <= R)) {
			ans++;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		go(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> L >> R >> X;
	for (int i = 0; i < n; i++) cin >> level[i];
	go(0);
	cout << ans;
}