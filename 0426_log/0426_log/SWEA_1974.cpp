#include<iostream>
#include<cstring>
using namespace std;
int  T, tc, a[9][9], c[9], b[9][9], check[9][9];
int ans = 0;
bool rowCheck() {
	//가로검사
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) c[a[i][j] - 1 ]++;
		int ok = 0;
		for (int j = 0; j < 9; j++) if (c[j] == 1) ok++;
		if (ok != 9) return false;
		memset(c, 0, sizeof(c));
	}
	return true;
}

bool colCheck() {
	//세로검사
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) c[a[j][i] - 1 ]++;
		int ok = 0;
		for (int j = 0; j < 9; j++) if (c[j] == 1) ok++;
		if (ok != 9) return false;
		memset(c, 0, sizeof(c));
	}
	return true;
}

bool areaCheck() {
	//섹터검사
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) 
			check[b[i][j]][a[i][j] - 1]++;	
	}
	for (int i = 0; i < 9; i++) {
		int ok = 0;
		for (int j = 0; j < 9; j++) {
			if (check[i][j] == 1) ok++;
		}
		if (ok != 9) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> a[i][j];
				b[i][j] = j / 3 + (i / 3) * 3;
			}
		}
		ans = 0;
		bool t1 = rowCheck();
		memset(c, 0, sizeof(c));
		bool t2 = colCheck();
		memset(c, 0, sizeof(c));
		bool t3 = areaCheck();
		ans = t1 * t2 * t3;
		cout << '#' << tc << ' ' << ans << '\n';
		memset(a, 0, sizeof(a));
		memset(check, 0, sizeof(check));
	}
}