#include<iostream>
using namespace std;
int T, Test, n, map[21][21];
int dx[] = { 1,1,-1,-1 };
int dy[] = { -1,1,1,-1 };
int Search(int nowx, int nowy) {
	int ans = -1;
	int Limit = n - 2, rLimit = n - 2;
	for (int i = 1; i <= Limit; i++) {
		bool impo, overlap;
		for (int j = 1; j <= rLimit; j++) {
			/*      i�� / /, j�� \ \       */
			int check[102] = { 0, };
			int x = nowx, y = nowy, cnt = 0;
			impo = overlap = false;

			// �밢�� �簢���� �ѹ� �����.
			for (int z = 0; z < 4; z++) {
				int maxi = (z % 2 == 0 ? i : j);
				// i��, j�� �̵�
				for (int k = 1; k <= maxi; k++) {
					int nx = x + dx[z], ny = y + dy[z];
					//�� ���� ������ ���
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
						impo = true;
						break;
					}
					x = nx; y = ny;
					if (check[map[x][y]] == false) {
						check[map[x][y]]++;
						cnt++;
					}
					//�ߺ� �߻�
					else {
						overlap = true;
						break;
					}
				}
				if (impo || overlap) break;
			}
			//�ߺ��� ���ٸ� ����ū ����Ʈ �� ����
			if (cnt == (i * 2 + j * 2) && ans < cnt) ans = cnt;

			if (impo) break;
		}
		rLimit--;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];

		int result = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == 0 || j == n - 1 || i == n - 1) continue;
				int temp =  Search(i, j);
				if (result < temp) result = temp;
			}
		}
		cout << '#' << T << ' ' << result << '\n';
	}
}