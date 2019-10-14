/* BOJ 9663 N-Queen*/
#include<iostream>
using namespace std;
int n, col[16], dig1[30], dig2[30], ans;

void go(int row) {
	if (row == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (col[i] + dig1[row + i] + dig2[n - 1 - (i - row)] == 0) {
			col[i] = dig1[row + i] = dig2[n - 1 - (i - row)] = 1;
			go(row + 1);
			col[i] = dig1[row + i] = dig2[n - 1 - (i - row)] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	go(0);
	cout << ans;
}