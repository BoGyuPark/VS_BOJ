/*BOJ 4195 模备 匙飘况农*/
#include<iostream>
#include<string>
#include<map>
#include<cstring>
using namespace std;
int T, n, parent[100001], personCnt[100001];
map<string, int> m;
string a, b;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a == b) return;

	if (a < b) parent[b] = a;
	else parent[a] = b;
	int t1 = personCnt[a];
	int t2 = personCnt[b];
	personCnt[a] += t2;
	personCnt[b] += t1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int cnt = 1;
		for (int i = 1; i <= 100000; i++) {
			parent[i] = i;
			personCnt[i] = 1;
		}
		for (int j = 0; j < n; j++) {
			cin >> a >> b;
			if (m.count(a) == 0) {
				m[a] = cnt;
				cnt++;
			}
			if (m.count(b) == 0) {
				m[b] = cnt;
				cnt++;
			}
			unionParent(m[a], m[b]);
			cout << personCnt[getParent(m[a])] << '\n';
		}
		m.clear();
		memset(personCnt, 0, sizeof(personCnt));
	}
}