#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V, E, A, B, C, parent[10001];
struct Edge {
	int s, e, cost;
};
vector<Edge> v;
bool cmp(Edge a, Edge b) {
	return a.cost < b.cost;
}
int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b) {
	a = getParent(a), b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
bool findParent(int a, int b) {
	a = getParent(a), b = getParent(b);
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		v.push_back({ A,B,C });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i <= V; i++) parent[i] = i;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int s = v[i].s, e = v[i].e;
		if (!findParent(s, e)) {
			unionParent(s, e);
			sum += v[i].cost;
		}
	}
	cout << sum;
}