#include<iostream>
using namespace std;
int n, m, a[501][501];
int trans[19][2][3] = {
	{{0,0,0},{1,2,3}},
	{{1,2,3},{0,0,0}},
	{{0,1,1},{1,0,1}},
	{{1,2,2},{0,0,1}},
	{{1,2,2},{0,0,-1}},
	{{0,1,2},{1,0,0}},
	{{0,1,2},{1,1,1}},
	{{1,0,0},{0,1,2}},
	{{0,0,1},{1,2,2}},
	{{1,1,1},{0,1,2}},
	{{0,0,-1},{1,2,2}},
	{{1,1,2},{0,1,1}},
	{{1,1,2},{0,-1,-1}},
	{{0,-1,-1},{1,1,2}},
	{{0,1,1},{1,1,2}},
	{{0,0,1},{1,2,1}},
	{{0,0,-1},{1,2,1}},
	{{1,2,1},{0,0,-1}},
	{{1,2,1},{0,0,1}},
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	long long sum = 0, ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int z = 0; z < 19; z++) {
				sum = a[i][j];
				for (int x = 0; x < 3; x++) {
					int row = i + trans[z][0][x];
					int col = j + trans[z][1][x];
					if (row < 0 || col < 0 || row >= n || col >= m) break;
					sum += a[row][col];
				}
				if (sum > ans) ans = sum;
			}
		}
	}
	cout << ans;
}