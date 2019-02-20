#include<iostream>
using namespace std;
int main() {
	long long n, i = 1; cin >> n;
	while (n > 0) {
		i++;
		n -= i;
	}
	cout << i - 1;
}