/*BOJ 1766 ������*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, t1, t2, indegree[32001];
vector<vector<int>> v;

priority_queue<int, vector<int>, greater<int>> q;

void topologicalSort() {
	
	//indegree�� 0�� ���� ť�� ����
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.top(); q.pop();
		cout << now << ' ';
		//now ��� ���� �� now���� ����� ����� indegree ����
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			indegree[next]--;
			//indegree�� 0�� ���� ť�� ����
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
		//indegree ����
		indegree[t2]++;
		v[t1].push_back(t2);
	}

	topologicalSort();
}