#include<iostream>
using namespace std;
int main() {
	int mi, pl, sum = 0, ans = -1;
	for (int i = 0; i < 4; i++) {
		cin >> mi >> pl;
		sum += (pl - mi);
		if (ans < sum) ans = sum;
	}
	cout << ans;
}