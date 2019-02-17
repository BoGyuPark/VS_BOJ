#include<iostream>
using namespace std;
int main() {
	int n, ans = 0; cin >> n;
	while (n != 0) {
		if (n % 2 == 1) ans++;
		n /= 2;
	}
	cout << ans;
}