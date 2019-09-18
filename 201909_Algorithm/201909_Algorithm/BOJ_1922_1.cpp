/*BOJ 1922 ��Ʈ��ũ ����_ũ�罺Į �˰���*/
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

// �� �θ� ��带 ��ģ��.
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

//���� �θ� ��带 �������� Ȯ��
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	//�� ���� �� ����ȣ�� �θ��� ��ȣ
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	//���� w �������� �������� ����
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		//�� ��尡 ���� ���տ� �ִ��� �Ǵ� (���Ͽ� ���ε�)
		if (!findParent(v[i].s, v[i].e)) {
			unionParent(v[i].s, v[i].e);
			ans += v[i].w;
		}
	}
	cout << ans;
}