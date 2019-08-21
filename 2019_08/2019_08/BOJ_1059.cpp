/*BOJ 1059 ¼ö2*/
#include<iostream>
using namespace std;
int L, arr[1001], n, temp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L;
	int maxi = -1;
	for (int i = 0; i < L; i++) {
		cin >> temp;
		if (maxi < temp) maxi = temp;
		arr[temp] = true;
	}
	cin >> n;
	if (arr[n] == true) {
		cout << 0;
		return 0;
	}
	int left = n - 1, right = n + 1;
	int leftCnt = 0, rightCnt = 0;
	int ans = 0;
	//left
	while (true) {
		if (left <= 0) break;
		if (arr[left] == false) {
			leftCnt++;
			left--;
		}
		else break;
	}
	//right
	while (true) {
		if (right > maxi) break;
		if (arr[right] == false) {
			rightCnt++;
			right++;
		}
		else break;
	}
	cout << leftCnt + rightCnt + leftCnt * rightCnt;
}