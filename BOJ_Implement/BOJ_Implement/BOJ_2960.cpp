#include<iostream>
#include<vector>
using namespace std;
int a[1001], n, k, cnt = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 2; i <= n; i++) a[i] = i;
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (a[i] != 0) { a[i] = 0; v.push_back(i); }
		for (int j = i; j <= n; j += i) {
			if (a[j] != 0) {
				a[j] = 0; v.push_back(j);
			}
		}
	}
	cout << v[k - 1];
}