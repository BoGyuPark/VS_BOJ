#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, sel[8];
vector<int> v;
void dfs(int index,int start) {
	if (index == m) {
		for (int j = 0; j < m; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		sel[index] = v[i];
		dfs(index + 1, i);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; v.push_back(t);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	n = v.size();
	dfs(0,0);
}