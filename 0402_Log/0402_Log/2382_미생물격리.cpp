#include<iostream>
#include<vector>
using namespace std;
int tc, T, n, m, k;
typedef struct info {
	int r, c, cnt, dir;
};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int TransDirs[] = { 1,0,3,2 };
vector<int> map[100][100];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m >> k;
		vector<info> wl(k);			//�̻��� ����Ʈ
		//�̻����� ��ȣ�� �ִ´�.
		for (int i = 0; i < k; i++) {
			cin >> wl[i].r >> wl[i].c >> wl[i].cnt >> wl[i].dir;
			wl[i].dir -= 1;
			map[wl[i].r][wl[i].c].push_back(i);
		}

		while (m--) {

			//map���� �̻��� ����
			for (int i = 0; i < k; i++) {
				if (wl[i].cnt == 0) continue;
				map[wl[i].r][wl[i].c].clear();
			}

			//�̻����� �̵��� ��Ų��.
			for (int i = 0; i < k; i++) {
				if (wl[i].cnt == 0) continue;
				wl[i].r += dx[wl[i].dir];
				wl[i].c += dy[wl[i].dir];
				map[wl[i].r][wl[i].c].push_back(i);
			}

			//int check[100][100] = { 0, };
			//����ó���� �̻��� �� ó�����ش�.
			for (int i = 0; i < k; i++) {
				if (wl[i].cnt == 0) continue;

				if (wl[i].r == 0 || wl[i].r == n - 1 || wl[i].c == 0 || wl[i].c == n - 1) {
					wl[i].cnt /= 2;
					wl[i].dir = TransDirs[wl[i].dir];
				}
				//������ ��ġ�� ������ �����ش�.
				else if (map[wl[i].r][wl[i].c].size() > 1) {
					int row = wl[i].r, col = wl[i].c;
					int temp = 0, sum = 0, tempDir = 0, tempIdx = 0;
					for (int j = 0; j < map[row][col].size(); j++) {
						if (temp < wl[map[row][col][j]].cnt) {
							temp = wl[map[row][col][j]].cnt;
							tempDir = wl[map[row][col][j]].dir;
							tempIdx = map[row][col][j];
						}
						sum += wl[map[row][col][j]].cnt;
						wl[map[row][col][j]].cnt = 0;
					}
					wl[tempIdx].cnt = sum;
					wl[tempIdx].dir = tempDir;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < k; i++) ans += wl[i].cnt;
		//���ʱ�ȭ
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) map[i][j].clear();
		cout << '#' << tc << ' ' << ans << '\n';
	}
}