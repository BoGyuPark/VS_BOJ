#include<iostream>
#include<algorithm>
using namespace std;
void findResult(int num) {
	int temp = num, sum = 0;
	for (int i = num - 1; i >= 1; i--) {
		if (num%i == 0) {
			sum += i;
			//num /= i;
		}
	}
	if (sum == temp) cout << temp << ' ';
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		findResult(i);
	}
}