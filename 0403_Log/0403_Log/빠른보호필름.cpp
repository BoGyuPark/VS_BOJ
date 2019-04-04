#include<iostream>
using namespace std;
int T, tc, n, m, k, map[13][20], sel[13], cpy[13][20], ans;
int tt = 0;
//k�� ������ üũ�ϴ� �Լ�
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
//         ��           ����Ƚ��
void dfs(int index, int inCnt) {
	//�ּ� ����Ƚ������ ũ�� �ٷ� ����
	if (ans <= inCnt) return;
	//��� �࿡ A�� ��������, B�� ��������, �������� ������ ����
	if (index == n) {
		bool flag = FindPass();
		if (flag && ans > inCnt) ans = inCnt;
		return;
	}

	dfs(index + 1, inCnt);		//�๰ �������� �ʴ´�.
	int temp[20];

	//A �๰ ����
	for (int i = 0; i < m; i++) temp[i] = cpy[index][i];
	for (int i = 0; i < m; i++) cpy[index][i] = 0;		//0�๰����
	dfs(index + 1, inCnt + 1);
	for (int i = 0; i < m; i++) cpy[index][i] = temp[i];	//���� ����

	//B �๰ ����
	for (int i = 0; i < m; i++) temp[i] = cpy[index][i];
	for (int i = 0; i < m; i++) cpy[index][i] = 1;		// 1�๰����
	dfs(index + 1, inCnt + 1);
	for (int i = 0; i < m; i++) cpy[index][i] = temp[i];	//���� ����
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