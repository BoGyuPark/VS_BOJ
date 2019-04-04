#include<iostream>
using namespace std;
int T, tc, n, m, k, map[13][20], sel[13], cpy[13][20], ans;
int tt = 0;
//k개 연속을 체크하는 함수
bool FindPass() {
	int cnt = 0;
	for (int col = 0; col < m; col++) {
		int colPass = 1, ConFirm = false;
		for (int row = 1; row < n; row++) {
			if (row == n - k + 2 && colPass == 1) break;
			if (cpy[row - 1][col] == cpy[row][col]) colPass++;
			else colPass = 1;
			if (colPass == k) {
				cnt++;
				ConFirm = true;
				colPass = 1;
				break;
			}
		}
		if (!ConFirm) return false;
	}
	return true;
}
//         행           투약횟수
void dfs(int index, int inCnt) {
	//최소 투약횟수보다 크면 바로 리턴
	if (ans <= inCnt) return;
	//모든 행에 A를 투약할지, B를 투약할지, 투약하지 않을지 결정
	if (index == n) {
		bool flag = FindPass();
		if (flag && ans > inCnt) ans = inCnt;
		return;
	}

	dfs(index + 1, inCnt);		//약물 투입하지 않는다.
	int temp[20];

	//A 약물 투입
	for (int i = 0; i < m; i++) temp[i] = cpy[index][i];
	for (int i = 0; i < m; i++) cpy[index][i] = 0;		//0약물투입
	dfs(index + 1, inCnt + 1);
	for (int i = 0; i < m; i++) cpy[index][i] = temp[i];	//원상 복귀

	//B 약물 투입
	for (int i = 0; i < m; i++) temp[i] = cpy[index][i];
	for (int i = 0; i < m; i++) cpy[index][i] = 1;		// 1약물투입
	dfs(index + 1, inCnt + 1);
	for (int i = 0; i < m; i++) cpy[index][i] = temp[i];	//원상 복귀
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