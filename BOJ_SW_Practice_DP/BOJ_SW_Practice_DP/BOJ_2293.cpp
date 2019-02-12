#include<iostream>
using namespace std;
int n, k, d[10001], nums[101], i, j, m;
int main() {
	cin >> n >> k;
	for (i = 0; i < n; i++) cin >> nums[i];
	m = i;
	d[0] = 1;
	for (j = 0; j < m; j++) {
		for (i = 1; i <= k; i++)
			if (i - nums[j] >= 0) d[i] += d[i - nums[j]];
	}
	cout << d[k];
}