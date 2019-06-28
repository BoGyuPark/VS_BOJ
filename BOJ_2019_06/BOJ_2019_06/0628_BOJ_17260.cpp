#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, k, h_arr[200001],ans;
bool check[200001];
vector<vector<int>> graph;
priority_queue<pair<int, int>> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	k--;
	for (int i = 0; i < n; i++) {
		cin >> h_arr[i];
		vector<int> v;
		graph.push_back(v);
		if(i!=k)
			pq.push({ h_arr[i],i });
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	//pq사용하자
	while (!pq.empty()) {
		double bound_h = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (check[next] == true) continue;
			if (bound_h < h_arr[next]) continue;
			if (next == k) {
				cout << 1;
				return 0;
			}
			pq.push({ (bound_h - h_arr[next]) / 2.0 + h_arr[next],next });
			check[next] = true;
		}
	}
	cout << ans;
}