/*BOJ 1922 네트워크 연결_크루스칼 알고리즘*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, a, b, c, ans, parent[1001];
struct info {
	int s, e, w;
};
vector<info> v;
bool cmp(info &a, info &b) {
	return a.w < b.w;
}

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// 각 부모 노드를 합친다.
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//같은 부모 노드를 가지는지 확인
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	//각 노드는 각 노드번호가 부모노드 번호
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	//간선 w 기준으로 오름차순 정렬
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		//두 노드가 같은 집합에 있는지 판단 (유니온 파인드)
		if (!findParent(v[i].s, v[i].e)) {
			unionParent(v[i].s, v[i].e);
			ans += v[i].w;
		}
	}
	cout << ans;
}