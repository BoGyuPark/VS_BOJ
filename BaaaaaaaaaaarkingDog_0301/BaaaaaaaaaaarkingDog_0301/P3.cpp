#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, sel[8];
vector<pair<int, int>> v, temp;
vector<int> ans;
void dfs(int index) {
	if (index == n) {
		int sum = 0;
		temp = v;
		for (int j = 0; j < n; j++) {
			if (temp[j].first <= 0 || temp[sel[j] - 1].first <= 0) continue;
			temp[j].first -= temp[sel[j] - 1].second;
			if (temp[j].first <= 0) sum++;

			temp[sel[j] - 1].first -= temp[j].second;
			if (temp[sel[j] - 1].first <= 0) sum++;
		}
		ans.push_back(sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (index == i-1) continue;
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		v.push_back({ t1,t2 });
	}
	dfs(0);
	sort(ans.begin(), ans.end());
	if (ans.size() == 0) cout << 0;
	else cout << ans[ans.size() - 1];
}