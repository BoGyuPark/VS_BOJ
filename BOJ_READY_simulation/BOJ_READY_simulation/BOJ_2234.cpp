#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
int a[51][51], c[51][51], rcnt = 0, n, m, dir, sum, te[51][51];
//          1  2  4  8
//          좌 상 우 하
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
using namespace std;
vector<int> rsum;
int main() {
	cin >> m >> n;
	//이동할수 있는 방향으로 변경
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			a[i][j] = 15 - a[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == false) {
				q.push({ i,j });
				c[i][j] = true;
				rcnt++;
				te[i][j] = rcnt;
				sum = 1;
				//bfs시작
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					int mul = 1;
					for (int z = 0; z < 4; z++) {
						dir = 0;
						if (a[x][y] & mul) {
							//방향 index구하기
							int t = mul;
							while (t != 1) {
								t /= 2;
								dir++;
							}
							//
							int nx = x + dx[dir], ny = y + dy[dir];
							if (c[nx][ny] == false) {
								c[nx][ny] = true;
								te[nx][ny] = rcnt;
								q.push({ nx,ny });
								sum++;
							}
						}
						mul *= 2;
					}
				}
				//방의 크기를 저장
				rsum.push_back(sum);
			}
		}
	}
	int maxi = 0;
	for (auto i : rsum) if (maxi < i) maxi = i;
	cout << rcnt << '\n';
	cout << maxi << '\n';
	//3번구한다.
	memset(c, 0, sizeof(c));
	vector<pair<int, int>> pa;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == false) {
				q.push({ i,j });
				c[i][j] = true;
				//bfs시작
				int number = te[i][j];
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z], ny = y + dy[z];
						if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
							if (c[nx][ny] == false) {
								if (te[nx][ny] == number) {
									c[nx][ny] = true;
									q.push({ nx,ny });
								}
								else {
									pa.push_back({ number,te[nx][ny] });
								}
							}
						}
					}
				}
			}
		}
	}
	sort(pa.begin(), pa.end());
	pa.erase(unique(pa.begin(), pa.end()), pa.end());
	int ans = 0, temp;
	for (auto &i : pa) {
		temp = rsum[i.first - 1] + rsum[i.second - 1];
		if (ans < temp) ans = temp;
	}
	cout << ans;
}