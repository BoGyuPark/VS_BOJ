#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int r, c, n, ch[121][121];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[121][121];
vector<pair<int, int>> group;
void dfs(int i, int j) {
	ch[i][j] = true;
	group.push_back({ i,j });
	a[i][j] = '.';
	for (int z = 0; z < 4; z++) {
		int nx = i + dx[z], ny = j + dy[z];
		if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
			if (a[nx][ny] == 'x') {
				dfs(nx, ny);
			}
		}
	}
}

void simulate() {
	memset(ch, 0, sizeof(ch));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'x' && ch[i][j] == false) {
				group.clear();
				dfs(i, j);
				vector<int> low(c, -1);
				//각 열에 가장 큰행의 인덱스를 저장
				for (auto &p : group) {
					low[p.second] = max(p.first, low[p.second]);
				}
				int lowest = r;
				for (int z = 0; z < low.size(); z++) {
					if (low[z] != -1) {
						int temp = 0;
						for (int d = 1; d <= r; d++) {
							if (low[z] + d < r) {
								if (a[low[z] + d][z] == 'x') break;
								temp = d;
							}
							else break;
						}
						lowest = min(temp, lowest);
					}
				}
				for (auto &p : group) {
					p.first += lowest;
					a[p.first][p.second] = 'x';
					ch[p.first][p.second] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) cin >> a[i][j];
	cin >> n;
	int row;
	for (int i = 0; i < n; i++) {
		cin >> row;
		row = r - row;
		//왼쪽에서 오른쪽으로
		if (i % 2 == 0) {
			for (int j = 0; j < c; j++) {
				if (a[row][j] == 'x') {
					a[row][j] = '.';
					break;
				}
			}
		}
		//오른쪽에서 왼쪽으로
		else {
			for (int j = c; j >= 0; j--) {
				if (a[row][j] == 'x') {
					a[row][j] = '.';
					break;
				}
			}
		}
		simulate();
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) cout << a[i][j];
		cout << '\n';
	}
}