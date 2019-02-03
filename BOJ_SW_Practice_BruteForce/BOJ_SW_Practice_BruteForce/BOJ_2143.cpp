#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int up[1001], down[1001], n1, n2;
long long t, ans = 0, partsum = 0;
vector<int> upv, downv;
void go(int sum, int index, int array[], vector<int> &v, int dest) {
	for (int i = 0; i < dest; i++) {
		sum = 0;
		for (int j = i; j < dest; j++) {
			sum += array[j];
			v.push_back(sum);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t >> n1;
	for (int i = 0; i < n1; i++) cin >> up[i];
	cin >> n2;	for (int i = 0; i < n2; i++) cin >> down[i];
	go(0, 0, up, upv, n1); 
	go(0, 0, down, downv, n2);
	sort(upv.begin(), upv.end()); sort(downv.begin(), downv.end());
	for (int i = 0; i < upv.size(); i++) {
		auto p = equal_range(downv.begin(), downv.end(), t - upv[i]);
		ans += p.second - p.first;
	}
	cout << ans;
}