//BOJ_1377_BubbleSort
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<pair<int, int> > v;
	//°ª, ÀÎµ¦½º
	for (int i = 1; i <= n; i++) {
		int t;	cin >> t;
		v.push_back(make_pair(t, i));
	}
	sort(v.begin(), v.end());
	int max = -1;
	int i = 0;
	for (auto &q : v) {
		if (max < (q.second - i))
			max = q.second - i;
		i++;
	}
	cout << max;
	return 0;
}