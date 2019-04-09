#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, k, a[11][11], eatable[11][11], deadTree[11][11];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<int> map[11][11];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			eatable[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		map[x - 1][y - 1].push_back(age);
	}

	while (k--) {
		//봄
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//나무가 있는곳
				if (map[i][j].size() > 0) {
					if (map[i][j].size() > 1) sort(map[i][j].begin(), map[i][j].end());
					for (int z = 0; z < map[i][j].size(); z++) {
						//양분을 나무의 나이만큼 빼주고 나이를 증가
						if (eatable[i][j] - map[i][j][z] >= 0) {
							eatable[i][j] -= map[i][j][z];
							map[i][j][z]++;
						}
						else {
							//모두다 팝 해버린다.
							for (int x = z; x < map[i][j].size(); x++)	
								deadTree[i][j] += map[i][j][x] / 2;
							int t = map[i][j].size() - z;
							while (t--) map[i][j].pop_back();
							break;
						}
					}
				}
			}
		}
		
		//가을
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//나무가 있는곳
				if (map[i][j].size() > 0) {
					for (int z = 0; z < map[i][j].size(); z++) {
						if (map[i][j][z] % 5 == 0) {
							for (int x = 0; x < 8; x++) {
								int nx = i + dx[x], ny = j + dy[x];
								if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
								map[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		}
		//여름 + 겨을
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				eatable[i][j] += (deadTree[i][j] + a[i][j]);
			}
		}
		memset(deadTree, 0, sizeof(deadTree));
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += map[i][j].size();
		}
	}
	cout << ans;
}