#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, a[11][11], ad[11][11], dead[11][11];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<int> tree[11][11];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ad[i][j];
			a[i][j] = 5;
		}
	}
	int tx, ty, ta;
	for (int i = 0; i < m; i++) {
		cin >> tx >> ty >> ta;
		tree[tx - 1][ty - 1].push_back(ta);
	}
	//봄,여름,가을,겨울
	while (k--) {
		//v는 나무가 있는 각 좌표와 나무들의 나이를 갖는다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dead[i][j] = 0;
				//좌표에 나무가 있으면
				if (tree[i][j].size() == 0) continue;
				sort(tree[i][j].begin(), tree[i][j].end());
				int deadcnt = 0;
				for (int z = 0; z < tree[i][j].size(); z++) {
					if (a[i][j] - tree[i][j][z] >= 0) {
						a[i][j] -= tree[i][j][z];
						tree[i][j][z]++;
					}
					else {
						dead[i][j] += (tree[i][j][z] / 2);
						deadcnt++;
					}
				}
				//앞에서 나이순으로 정렬했기때문에 뒤에서 deadcnt수 만큼은 죽은나무
				while (deadcnt--) { tree[i][j].pop_back(); }	
			}
		}
		//가을이되어 5의배수인 나무는 증식한다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (tree[i][j].size() == 0) continue;
				for (int z = 0; z < tree[i][j].size(); z++) {
					if (tree[i][j][z] % 5 == 0) {
						for (int w = 0; w < 8; w++) {
							int nx = i + dx[w], ny = j + dy[w];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
		//겨울 처음받은 양분 다시 넣는다.
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				a[i][j] += (ad[i][j] + dead[i][j]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			ans += tree[i][j].size();
	}
	cout << ans;
}