/*BOJ 1766 문제집*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, t1, t2, indegree[32001];
vector<vector<int>> v;

priority_queue<int, vector<int>, greater<int>> q;

void topologicalSort() {
	
	//indegree가 0인 것을 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.top(); q.pop();
		cout << now << ' ';
		//now 노드 삭제 후 now노드와 연결된 노드의 indegree 감소
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;
			//indegree가 0인 것을 큐에 삽입
			if (indegree[next] == 0) q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		//indegree 측정
		indegree[t2]++;
		v[t1].push_back(t2);
	}

	topologicalSort();
}