#include<iostream>
using namespace std;
int n, check_dig[40], check_dig2[40], check_col[16],a[16][16], ans = 0;
bool check(int row, int col) {
	if (check_col[col])		return false;
	if (check_dig[row + col])	return false;
	if (check_dig2[row - col + n - 1])		return false;
	return true;
}

void go(int row) {
	if (row == n) {
		ans += 1;
		return;
	}
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			check_dig[row + col] = true;
			check_dig2[row - col + n - 1] = true;
			check_col[col] = true;
			a[row][col] = true;

			go(row + 1);
			
			check_dig[row + col] = false;
			check_dig2[row - col + n - 1] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}
}
int main() {
	cin >> n;	go(0);	cout << ans;
}