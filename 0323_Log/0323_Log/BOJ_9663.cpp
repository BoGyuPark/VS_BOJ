#include<iostream>
using namespace std;
int n, ans = 0;
int dig1[30], dig2[30], c_col[30];
bool check(int row, int col) {
	if (c_col[col]) return false;
	if (dig1[row + col]) return false;
	if (dig2[row - col + n - 1]) return false;
	return true;
}

void dfs(int row) {
	if (row == n) {
		ans += 1;
		return;
	}
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			c_col[col] = dig1[row + col] = dig2[row - col + n - 1] = true;
			dfs(row + 1);
			c_col[col] = dig1[row + col] = dig2[row - col + n - 1] = false;
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	dfs(0); cout << ans;
}