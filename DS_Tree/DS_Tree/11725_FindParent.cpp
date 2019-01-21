//BOJ_11725_FindParent
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int p[100001];
vector<int> v[100001];
int check[100001];
void bfs(int node) {
	queue<int> q;	q.push(node);
	check[node] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (check[next] == 0) {
				p[next] = cur;
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int t1, t2;;
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	bfs(1);
	for (int i = 2; i <= n; i++)
		cout << p[i] << '\n';
	return 0;
}