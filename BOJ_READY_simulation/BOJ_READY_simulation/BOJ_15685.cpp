#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, x, y, d, g, a[101][101], c[101][101];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
//각 커브의 방향을 가져온다.
vector<int> cur() {
	vector<int> ans;
	ans.push_back(d);
	vector<int> temp(ans);
	for (int i = 1; i <= g; i++) {
		for (int j = 0; j < temp.size(); j++) {
			int t = temp[j];
			t = (t + 1) % 4;
			ans.push_back(t);
		}
		temp = ans;
		reverse(temp.begin(), temp.end());
	}
	return ans;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x >> d >> g;
		vector<int> dir = cur();
		c[x][y] = true;
		//각 가져온 방향에서 다음좌표를 만들어 check한다.
		for (int i : dir) {
			x += dx[i];
			y += dy[i];
			c[x][y] = true;
		}
	}

	int sum = 0;
	for (int i = 0; i < 100; i++) 
		for (int j = 0; j < 100; j++)
			if (c[i][j]&& c[i + 1][j] && c[i][j + 1] && c[i + 1][j + 1] )	sum++;
	cout << sum;
}