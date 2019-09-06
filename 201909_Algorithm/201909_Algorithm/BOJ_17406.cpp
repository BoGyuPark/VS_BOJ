/*BOJ 17406 배열 돌리기 4*/
#include<iostream>
#include<vector>
using namespace std;
int n, m, k, map[51][51], cpy[51][51], c[7], sel[7], ans;
struct info {
	int r, c, s;
};
vector<info> v;

void findMin() {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) sum += map[i][j];
		if (ans > sum) ans = sum;
	}
}

void Rotate(int sx, int sy, int ex, int ey) {
	while (true) {
		int temp = map[sx][sy];
		int Max = ex - sx;
		if (Max == 0) break;
		//위
		int r = sx, c = sy;
		for (int i = 0; i < Max; i++) {
			map[r][c] = map[r + 1][c];
			r++;
		}
		//왼
		for (int i = 0; i < Max; i++) {
			map[r][c] = map[r][c + 1];
			c++;
		}
		//아
		for (int i = 0; i < Max; i++) {
			map[r][c] = map[r - 1][c];
			r--;
		}
		//오
		for (int i = 0; i < Max - 1; i++) {
			map[r][c] = map[r][c - 1];
			c--;
		}
		map[r][c] = temp;
		
		sx++; sy++; ex--; ey--;
	}
	
}

void simulate() {
	for (int i = 0; i < k; i++) {
		int r = v[sel[i]].r, c = v[sel[i]].c, s = v[sel[i]].s;
		Rotate(r - s - 1, c - s - 1, r + s - 1, c + s - 1);
	}
}

void mapCpy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) map[i][j] = cpy[i][j];
	}
}

void go(int index) {
	if (index == k) {
		simulate();
		findMin();
		mapCpy();
		return;
	}
	for (int i = 0; i < k; i++) {
		if (c[i]) continue;
		c[i] = true;
		sel[index] = i;
		go(index + 1);
		c[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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