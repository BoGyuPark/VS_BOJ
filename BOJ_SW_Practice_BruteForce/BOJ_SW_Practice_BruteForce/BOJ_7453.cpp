#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, a[4001], b[4001], c[4001], d[4001], i, j;
int main() {
	cin >> n;
	for (i = 0; i < n; i++)		cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<int> ab, cd;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(ab.begin(), ab.end()); 
	sort(cd.begin(), cd.end());
	long long ans = 0;
	for (i = 0; i < ab.size(); i++) {
		auto q = equal_range(cd.begin(), cd.end(), -ab[i]);
		ans += q.second - q.first;
	}
	cout << ans;
}