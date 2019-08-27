/*BOJ 14501 Επ»η*/
#include<iostream>
using namespace std;
int n, sel[16], T[16], P[16], ans;
void go(int index) {
	if (index == n) {
		int t = 0, sum = 0;
		for (int j = 0; j < n; j++) {
			if (sel[j] == 1 && j>=t && j + T[j] <= n) {
				sum += P[j];
				t = j + T[j];
			}
		}
		if (ans < sum) ans = sum;
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		go(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> T[i] >> P[i];
	go(0);
	cout << ans;
}