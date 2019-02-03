#include<iostream>
using namespace std;
int n, m, arr[10001], ans = 0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	long long sum = arr[0];
	for (int ri = 0, le = 0; ri < n;) {
		if (sum < m) {
			ri++;
			sum += arr[ri];
		}
		else if (sum > m) {
			sum -= arr[le];
			le++;
		}
		else {
			ans++; ri++; 
			sum += arr[ri];
		}
	}
	cout << ans;
}