/*BOJ 2252 줄 세우기*/
//위상 정렬
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, u, v;
bool visited[32001];
vector<vector<int>> ve;
vector<int> ans;
void dfs(int nodeIdx) {
	visited[nodeIdx] = true;
	for (int i = 0; i < ve[nodeIdx].size(); i++) {
		int next = ve[nodeIdx][i];
		if (visited[next]) continue;
		dfs(next);
	}
	ans.push_back(nodeIdx);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	ve.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		ve[u].push_back(v);
	}

	for (int i = 1; i < ve.size(); i++) {
		if (visited[i]) continue;
		dfs(i);
	}
	reverse(ans.begin(), ans.end());
	for(auto i : ans) cout << i << ' ';
}