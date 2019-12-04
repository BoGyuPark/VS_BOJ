#include<iostream>
using namespace std;
typedef long long ll;
ll memo[100];
ll fibo(int x) {
	if (x == 1 || x == 2) return 1;
	if (memo[x] != 0) return memo[x];
	return memo[x] = fibo(x - 1) + fibo(x - 2);
}
int main() {
	cout << fibo(10) << '\n';
}