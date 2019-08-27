/*BOJ 14500 테트로미노*/
#include<iostream>
using namespace std;
int n, m, map[501][501], ans;
int shapeX[19][4] = {
	{0,0,0,0},
	{0,1,2,3},
	{0,0,1,1},
	{0,1,2,2},
	{0,1,2,2},
	{0,0,1,2},
	{0,0,1,2},

	{0,1,1,1},
	{0,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{0,1,1,2},
	{0,1,1,2},
	{0,0,-1,-1},
	{0,0,1,1},
	{0,0,0,-1},
	{0,1,2,1},
	{0,1,2,1},
	{0,0,0,1}
};
int shapeY[19][4] = {
	{0,1,2,3},
	{0,0,0,0},
	{0,1,0,1},
	{0,0,0,1},
	{0,0,0,-1},
	{0,1,0,0},
	{0,1,1,1},

	{0,0,1,2},
	{0,0,-1,-2},
	{0,1,2,0},
	{0,1,2,2},
	{0,0,1,1},
	{0,0,-1,-1},
	{0,1,1,2},
	{0,1,1,2},
	{0,1,2,1},
	{0,0,0,1},
	{0,0,0,-1},
	{0,1,2,1}
};
void calc(int x, int y) {
	for (int i = 0; i < 19; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + shapeX[i][j], ny = y + shapeY[i][j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				sum = 0;
				break;
			}
			sum += map[nx][ny];
		}
		if (ans < sum) ans = sum;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) calc(i, j);
	cout << ans;
}