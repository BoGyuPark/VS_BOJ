#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, t1, t2, t3;
int ad[11][11], a[11][11];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<int> map[11][11];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ad[i][j];
			a[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		map[t1 - 1][t2 - 1].push_back(t3);
	}
	while (k--) {
		//봄 자신의 나이만큼 양분을 먹고 나이가 1증가
		// 나이가 어린 나무부터 양분을 먹는다.
		//양분이 부족하면 즉사
		int dead[11][11] = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int Size = map[i][j].size();
				if (Size > 0) {
					int removecnt = 0;
					sort(map[i][j].begin(), map[i][j].end());
					for (int z = 0; z < Size; z++) {
						if (map[i][j][z] <= a[i][j]) {
							a[i][j] -= map[i][j][z];
							map[i][j][z]++;
						}
						else {
							removecnt++;
							dead[i][j] += (map[i][j][z] / 2);
						}
					}
					while (removecnt--) {
						map[i][j].pop_back();
					}
				}
			}
		}
		//가을 나무의 나이가 %5==0 이면 주위 8자리에 나이가 1인 나무 증식
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int Size = map[i][j].size();
				if (Size > 0) {
					for (int z = 0; z < Size; z++) {
						if (map[i][j][z] % 5 == 0) {
							for (int s = 0; s < 8; s++) {
								int nx = i + dx[s], ny = j + dy[s];
								if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
								map[nx][ny].push_back(1);
							}
						}
					}
				}
			}
		}
		//여름 죽은나무는 나이/2 로 양분 추가
		//겨울 각 양분을 더해준다.
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				a[i][j] += (dead[i][j] + ad[i][j]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += map[i][j].size();
	cout << ans;
}