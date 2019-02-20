#include<iostream>
using namespace std;
int main() {
	int n, cnt = 0;; cin >> n;
	n = 1000 - n;
	int coin[] = { 500,100,50,10,5,1 };
	for (int i = 0; i < 6; i++) {
		while (n - coin[i] >= 0) {
			cnt++;
			n -= coin[i];
		}
	}
	cout << cnt;
}