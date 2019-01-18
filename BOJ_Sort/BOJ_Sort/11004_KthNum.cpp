//BOJ_11004_KthNum
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long t; cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	//nth_element(v.begin(), v.begin() + k - 1 , v.end());
	cout << v[k - 1];
	return 0;
}