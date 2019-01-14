//BOJ_11650_SortCoordinate
#include<bits/stdc++.h>
using namespace std;
int main() {
	int N; cin >> N;
	vector<pair<int, int> > v;
	while (N--) {
		int t1, t2;
		cin >> t1 >> t2;
		v.push_back(make_pair(t1, t2));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << "\n";
	return 0;
}