#include <iostream>
#include<math.h>
typedef long long ll;
using namespace std;
int main(void) {
	ll n;
	cin >> n;
	ll maxi = sqrt(n), mini = 2147483647;

	for (ll i = 1; i <= maxi + 1; i++) {
		if (n%i == 0) {
			ll j = n / i;
			if (mini > abs(i - j)) mini = abs(i - j);
		}
	}
	cout << mini;
	return 0;
}
