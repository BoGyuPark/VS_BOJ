#include<iostream>
using namespace std;
int k, n, t, reTime = 210;
char ans;
int main() {
	cin >> k >> n;
	while (n--) {
		cin >> t >> ans;
		reTime -= t;
		//시간이 지나면 무조건 폭탄이 터짐.
		if (reTime <= 0) break;
		//정답인 경우 폭탄을 옮긴다.
		if (ans == 'T') {
			k %= 8; k++;
		}
	}
	cout << k;
}