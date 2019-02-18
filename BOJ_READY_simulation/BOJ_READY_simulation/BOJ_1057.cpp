#include<iostream>
using namespace std;
int n, a, b, r;
int main() {
	cin >> n >> a >> b;
	while (a != b) {
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		r++;
	}
	cout << r;
}