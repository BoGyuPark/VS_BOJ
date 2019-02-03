#include<iostream>
using namespace std;
int n, s, arr[100001], dif = 2000000000, flag = 1;
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	long long sum = arr[0];
	for (int right = 0, left = 0; right < n;) {
		if (sum < s) {
			right++;
			sum += arr[right];
		}
		else if (sum > s) {
			if (dif > right - left + 1) {
				dif = right - left + 1;
				flag = 0;
			}
			sum -= arr[left];
			left++;
		}
		else {
			if (dif > right - left + 1)
				dif = right - left + 1;
			flag = 0;
			right++;
			sum += arr[right];
		}
	}
	cout << (flag == 1 ? 0 : dif);
}