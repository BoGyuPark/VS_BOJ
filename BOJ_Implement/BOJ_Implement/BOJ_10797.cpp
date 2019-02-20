#include<iostream>
using namespace std;
int main() {
	int num, car[5], ans = 0;
	cin >> num;
	for (int i = 0; i < 5; i++) {
		cin >> car[i];
		if (car[i] == num) ans++;
	}
	cout << ans;
}