/*BOJ 1987 ¾ËÆÄºª*/
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, ans = 1;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char arr[21][21];
bool alphaCheck[30];
void go(int x, int y, int dist) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (alphaCheck[arr[nx][ny] - 'A']) continue;
		alphaCheck[arr[nx][ny] - 'A'] = true;
		ans = max(dist + 1 , ans);

		go(nx, ny, dist + 1);

		alphaCheck[arr[nx][ny] - 'A'] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];
	alphaCheck[arr[0][0] - 'A'] = true;
	go(0,0,1);
	cout << ans;
}