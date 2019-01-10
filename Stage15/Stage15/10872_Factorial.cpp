//BOJ_10872_Factorial
#include<bits/stdc++.h>
using namespace std;
long long fact(long long n)
{
	if (n == 0 || n == 1)
		return 1;

	return n = n * fact(n - 1);
}
int main()
{
	int N; cin >> N;
	long long result = fact(N);
	cout << result;
}