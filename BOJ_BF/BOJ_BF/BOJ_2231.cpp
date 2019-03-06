#include<iostream>
using namespace std;
int n, sum;
int main() {
	cin >> n;
	int i, temp;
	for (i = 1; i < n; i++) {
		sum = i;
		temp = i;
		while (temp % 10 != 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n) break;
	}
	cout << (i == n ? 0 : i);
}