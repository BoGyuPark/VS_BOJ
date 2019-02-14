#include<iostream>
#include<cstring>
using namespace std;
int t, n,a[100001],c[100001],indeg[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		memset(indeg, 0, sizeof(indeg));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			indeg[a[i]]++;
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			int now = i;
			while (c[now] == false && indeg[now] == false) {
				sum++;
				c[now] = true;
				indeg[a[now]]--;
				now = a[now];
			}
		}
		cout << sum << '\n';
	}
}