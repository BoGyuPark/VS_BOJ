#include<iostream>
using namespace std;
int n, a[11][11], dig1[22], dig2[22], ans, MAX = 0;
bool check(int row, int col) {
	if (a[row][col] == 0) return false;
	if (dig1[row + col]) return false;
	if (dig2[row - col + n - 1]) return false;
	return true;
}
void dfs(int row, int col, int sum, int pivot) {
	if (sum > MAX) MAX = sum;
	if (row >= n) return;
	if (col >= n) {
		if (++row % 2 == pivot) col = 0;
		else col = 1;
	}

	if (check(row, col)) {
		dig1[row + col] = dig2[row - col + n - 1] = true;
		dfs(row, col + 2, sum + 1, pivot);
		dig1[row + col] = dig2[row - col + n - 1] = false;
	}
	dfs(row, col + 2, sum, pivot);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> a[i][j];
	
	ans = 0, 
	//white∆«
	dfs(0, 0, 0, 0);
	ans += MAX;
	MAX = 0;
	//black∆«
	dfs(0, 1, 0, 1);
	ans += MAX;
	cout << ans;
}