/*BOJ 1517 버블 소트*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, t;
vector<int> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
		sort(v.begin(), v.end());
		if (v.size() % 2 == 0) {
			cout << v[(v.size() / 2) - 1] << '\n';
		}
		else {
			cout << v[v.size() / 2] << '\n';
		}
	}
}