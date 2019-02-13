#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, a[101][101], c[101][101], areas;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<int> nums;
void REmove(int x) {
	for(int i=0; i<n;i++)
		for (int j = 0; j < n; j++)	if (a[i][j] <= x) c[i][j] = true;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			nums.push_back(a[i][j]);
		}
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	queue<pair<int, int> >q;
	vector<int> maxArea;
	for (auto& num : nums) {
		memset(c, 0, sizeof(c));
		REmove(num);	areas = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] == false) {
					q.push({ i,j });	c[i][j] = true; areas++;
					while (!q.empty()) {
						int x = q.front().first, y = q.front().second; q.pop();
						for (int z = 0; z < 4; z++) {
							int nx = x + dx[z], ny = y + dy[z];
							if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
								if (c[nx][ny] == false) {
									c[nx][ny] = true; q.push({ nx,ny });
								}
							}
						}
					}
				}
			}
		}
		maxArea.push_back(areas);
	}
	sort(maxArea.begin(), maxArea.end());
	int ans = maxArea[maxArea.size() - 1];
	cout << (ans > 0 ? ans : 1);
}