#include<iostream>
#include<string>
using namespace std;
int n, ans, di = 1, len = 1;
int main() {
	string str;		cin >> n;
	str = to_string(n);
	for (int i = 0; i < str.size() - 1; i++) {
		ans += di * 9 * len;
		di *= 10;
		len++;
	}
	cout << ans + (n - di + 1)*len;;
}