/* BOJ 17406 배열 돌리기 4*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n, m, k, map[51][51], cpy[51][51], sel[7], check[7], ans = 2147483647;
typedef struct {
	int r, c, s;
}info;
vector<info> v;
void rotateMap(int sx, int sy, int ex, int ey) {
	int maxSize = ex - sx;
	int r = sx, c = sy;
	while (maxSize != 0) {
		int temp = map[r][c];
		//왼쪽 
		for (int i = 1; i <= maxSize; i++) {
			map[r][c] = map[r + 1][c];
			r++;
		}
		//아래
		for (int i = 1; i <= maxSize; i++) {
			map[r][c] = map[r][c + 1];
			c++;
		}
		//오른쪽
		for (int i = 1; i <= maxSize; i++) {
			map[r][c] = map[r - 1][c];
			r--;
		}
		//위
		for (int i = 1; i <= maxSize - 1; i++) {
			map[r][c] = map[r][c - 1];
			c--;
		}
		//cout << "r : " << r << " c: " << c << '\n';
		map[r][c] = temp;

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';*/
		maxSize -= 2;
		r++;
	}
}

void go(int index) {
	if (index == k) {
		for (int j = 0; j < k; j++) {
			//시작점, 끝점 잡고 회전시킨다.
			int r, c, s;
			r = v[sel[j]].r, c = v[sel[j]].c, s = v[sel[j]].s;
			int sx, sy, ex, ey;
			sx = r - s, sy = c - s, ex = r + s, ey = c + s;
			rotateMap(sx - 1, sy - 1, ex - 1, ey - 1);
		}

		//Max Row value;
		for (int a = 0; a < n; a++) {
			int sum = 0;
			for (int b = 0; b < m; b++) {
				sum += map[a][b];
			}
			if (ans > sum) ans = sum;
		}
		
		//map copy
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				map[a][b] = cpy[a][b];
			}
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
	go(0);
	cout << ans;
}