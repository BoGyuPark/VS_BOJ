#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n, m, check[101];
vector<vector<int>> vec;
int bfs(int num) {
	memset(check, -1, sizeof(check));
	queue<int> q;
	q.push(num);
	check[num] = 0;
	int dist = 1;
	int sum = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			if (check[next] != -1) continue;
			q.push(next);
			check[next] = check[now] + 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if(check[i]!=-1)	sum += check[i];
	}
	//cout << num<<"ÀÏ¶§ : "<<sum << '\n';
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	vec.resize(n + 1);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int mini = 2147483647, ans = 0;
	for (int i = 1; i <= n; i++) {
		int s = bfs(i);
		if (mini > s) {
			mini = s;
			ans = i;
		}
	}
	cout << ans;
}