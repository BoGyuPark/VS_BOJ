/*BOJ 17406 배열 돌리기 4*/
#include<iostream>
#include<vector>
using namespace std;
int n, m, k, map[51][51], cpy[51][51], sel[7], check[7], ans;
struct info {
	int r, c, s;
};
vector<info> v;
void Rotate(int idx) {
	int sx = v[idx].r - v[idx].s, sy = v[idx].c - v[idx].s;
	int ex = v[idx].r + v[idx].s, ey = v[idx].c + v[idx].s;
	
	while (true) {
		int temp = map[sx][sy];
		int r = sx, c = sy;
		int RowMax = ex - sx, ColMax = ey - sy;

		//up
		for (int i = 0; i < RowMax; i++) {
			map[r][c] = map[r + 1][c];
			r++;
		}
		//left
		for (int i = 0; i < ColMax; i++) {
			map[r][c] = map[r][c + 1];
			c++;
		}
		//down
		for (int i = 0; i < RowMax; i++) {
			map[r][c] = map[r - 1][c];
			r--;
		}
		//right
		for (int i = 0; i < ColMax - 1; i++) {
			map[r][c] = map[r][c - 1];
			c--;
		}
		map[r][c] = temp;
		sx += 1, sy += 1; ex -= 1, ey -= 1;

		if (sx == ex && sy == ey) break;
	}
}

void go(int index) {
	if (index == k) {
		
		for (int j = 0; j < index; j++) Rotate(sel[j]);
		
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) sum += map[i][j];
			if (ans > sum) ans = sum;
		}

		//memory copy
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) map[i][j] = cpy[i][j];
		}
		return;
	}

	for (int i = 0; i < k; i++) {
		if (check[i]) continue;
		check[i] = true;
		sel[index] = i;
		go(index + 1);
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			cpy[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		v.push_back({ t1,t2,t3 });
	}
	ans = 2147483647;
	go(0);
	cout << ans;
}