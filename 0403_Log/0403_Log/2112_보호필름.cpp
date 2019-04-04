#include<iostream>
using namespace std;
int T, tc, n, m, k, map[13][20], sel[13], cpy[13][20], ans;
bool FindPass() {
	int cnt = 0;
	for (int col = 0; col < m; col++) {
		int colPass = 1, ConFirm = false;
		for (int row = 1; row < n; row++) {
			if (row == n - k + 2 && colPass == 1) break;
			if (cpy[row - 1][col] == cpy[row][col]) colPass++;
			else colPass = 1;
			if (colPass == k) {	cnt++;	ConFirm = true;	break;}
		}
		if (!ConFirm) return false;
	}
	return true;
}

void dfs(int index, int inCnt) {
	if (ans <= inCnt) return;
	if (index == n) {
		//j행
		for (int j = 0; j < n; j++) {
			if (sel[j] > 0) {
				int num = (sel[j] == 1 ? 0 : 1);
				//약품 투여
				for (int z = 0; z < m; z++) cpy[j][z] = num;
			}
		}
		//적합한지 판단해준다
		bool flag = FindPass();
		if (flag && ans > inCnt) ans = inCnt;	
		//맵 복사
		for (int j = 0; j < n; j++) 
			if (sel[j] > 0) for (int z = 0; z < m; z++) cpy[j][z] = map[j][z];
		return;
	}
	for (int i = 0; i < 3; i++) {
		sel[index] = i;
		if (i != 0)	dfs(index + 1, inCnt + 1);
		else dfs(index + 1, inCnt);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m >> k;
		// 0 : A,   1 : B
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				cpy[i][j] = map[i][j];
			}
		ans = 2147483647;
		dfs(0, 0);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}