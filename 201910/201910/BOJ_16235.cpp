#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int n, m, k, A[11][11], map[11][11], row, col, age;
vector<int> v[11][11];
void springAndSummer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!v[i][j].empty()) {
				sort(v[i][j].begin(), v[i][j].end());
				int vSize = v[i][j].size();
				int z = 0;
				for (z = 0; z < vSize; z++) {
					if (map[i][j] - v[i][j][z] >= 0) {
						map[i][j] -= v[i][j][z];
						v[i][j][z]++;
					}
					else break;
				}
				for (int a = vSize - 1; a >= z; a--) {
					map[i][j] += v[i][j][a] / 2;
					v[i][j].pop_back();
				}
			}
		}
	}
}
void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!v[i][j].empty()) {
				int vSize = v[i][j].size();
				for (int z = 0; z < vSize; z++) {
					if (v[i][j][z] % 5 == 0) {
						for (int a = 0; a < 8; a++) {
							int nx = i + dx[a], ny = j + dy[a];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
							v[nx][ny].push_back(1);
						}
					}
				}
			
			}
		}
	}
}
void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += A[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> row >> col >> age;
		v[row - 1][col - 1].push_back(age);
	}

	for (int t = 0; t < k; t++) {
		springAndSummer();
		fall();
		winter();
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += v[i][j].size();
		}
	}
	cout << ans;
}