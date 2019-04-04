#include<iostream>
#include<vector>
using namespace std;
int T, tc, n, m, C, a[10][10],sel[5], honeySum;
vector<vector<int>> v;
vector<int> ans;
void dfs(int index, int vecIdx) {
	if (index == m) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			if (sel[j] == 1)	sum += v[vecIdx][j];
		}
		int t = 0;
		if (0 < sum && sum <= C) {
			for (int j = 0; j < m; j++) {
				if (sel[j] == 1) t += (v[vecIdx][j] * v[vecIdx][j]);
			}
			if (t > honeySum) honeySum = t;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		dfs(index + 1, vecIdx);
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m >> C;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
		
		vector<int> temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				for (int z = 0; z < m; z++) temp.push_back(a[i][j + z]);
				v.push_back(temp);
				temp.clear();
			}
		}
		//dfs(0, 0);

		for (int i = 0; i < v.size(); i++) {
			honeySum = 0;
			dfs(0, i);
			ans.push_back(honeySum);
		}
		/*for (auto i : ans) cout << i << ' ';
		cout << '\n';*/
		int MaxValue = 0;
		int colCnt = n - m + 1;
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans.size(); j++) {
				//중복되는 구간을 제외한다.
				int row = i / colCnt;
				if (colCnt*row <= j && j < colCnt*(row + 1)) {
					//j의 시작이 범위안에 있으면 안되고
					if ((i <= j && j <= i + m - 1) || (i <= j + m - 1 && j + m - 1 <= i + m - 1)) continue;
				}
				//cout << i << ' ' << j << '\n';
				//if (i == j) continue;
				if (MaxValue < ans[i] + ans[j]) MaxValue = ans[i] + ans[j];
			}
		}
		//cout << MaxValue << '\n';
		cout << '#' << tc << ' ' << MaxValue << '\n';
		v.clear();
		ans.clear();
	}
}