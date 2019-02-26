#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int T, Test, k, n, m, a[16][13], cpy[16][13], sel[5];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void bfs(int col) {
	int c[16][13] = { 0, };
	//먼저 맨위의 벽돌의 좌표를 찾는다.
	int row = 94321;
	for (int i = 0; i < n; i++) {
		if (cpy[i][col] != 0) {
			row = i;
			break;
		}
	}
	if (row == 94321) return;

	queue<pair<int, int>> q;
	c[row][col] = true;
	q.push({ row,col });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		int value = cpy[x][y] - 1;
		cpy[x][y] = 0;
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= value; j++) {
				int nx = x + j * dx[i], ny = y + j * dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (c[nx][ny] == false) {
					if (cpy[nx][ny] != 0) {
						c[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
	}
}

void down() {
	for (int i = 0; i < m; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (cpy[j][i] != 0) {
				int empty = 0;
				for (int z = 1; z < n - j; z++) {
					if (cpy[j + z][i] != 0) break;
					else empty++;
				}
				if (empty > 0) swap(cpy[j + empty][i], cpy[j][i]);
			}
		}
	}
	/*queue<int> colq;
	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (cpy[i][j] != 0) {
				colq.push(cpy[i][j]);
				cpy[i][j] = 0;
			}
		}
		int len = colq.size();
		for (int i = n - 1; i > (n - 1 - len); i--) {
			cpy[i][j] = colq.front();
			colq.pop();
		}
	}*/
}

void go(int index, vector<int> &ans) {
	//종료 조건
	if (index == k) {
		for (int i = 0; i < k; i++) {
			int order = sel[i];
			bfs(order);
			down();
		}
		//마지막에 남은 벽돌의 수를 구한다.
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) if (cpy[i][j] != 0) sum++;
		}
		ans.push_back(sum);
		if (sum == 0) return;
		//cpy해줘야한다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cpy[i][j] = a[i][j];
		}
		return;
	}
	for (int i = 0; i < m; i++) {
		sel[index] = i;
		go(index + 1, ans);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> k >> m >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				cpy[i][j] = a[i][j];
			}
		}
		vector<int> ans;
		go(0, ans);
		sort(ans.begin(), ans.end());
		cout << '#' << T << ' ' << ans[0] << '\n';
	}
}