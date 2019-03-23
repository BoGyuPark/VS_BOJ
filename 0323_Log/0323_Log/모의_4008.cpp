#include<iostream>
#include<cstring>
using namespace std;
int T, tc, n, MAX, MIN, a[13];
void dfs(int index, int pl, int mi, int mu, int di, int cal) {
	if (index == n - 1) {
		if (MAX < cal) MAX = cal;
		if (MIN > cal) MIN = cal;
		return;
	}
	if (pl > 0) dfs(index + 1, pl - 1, mi, mu, di, cal + a[index + 1]);
	if (mi > 0) dfs(index + 1, pl, mi - 1, mu, di, cal - a[index + 1]);
	if (mu > 0) dfs(index + 1, pl, mi, mu - 1, di, cal * a[index + 1]);
	if (di > 0) dfs(index + 1, pl, mi, mu, di - 1, cal / a[index + 1]);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	for (T = 1; T <= tc; T++) {
		cin >> n;
		int pl, mi, mu, di;
		cin >> pl >> mi >> mu >> di;
		for (int i = 0; i < n; i++) cin >> a[i];
		MAX = -2147483647; MIN = 2147483647;
		dfs(0, pl, mi, mu, di, a[0]);
		memset(a, 0, sizeof(0));
		cout << '#' << T << ' ' << MAX - MIN << '\n';
	}
}