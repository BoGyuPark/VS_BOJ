#include<iostream>
using namespace std;
void go(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	int c = 6 - a - b;	//a와 b가 아닌 나머지 기둥의 번호
	go(a, c, n - 1);
	cout << a << ' ' << b << '\n';
	go(c, b, n - 1);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	cout << (1 << n) -1 << '\n';
	go(1, 3, n);
}