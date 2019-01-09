//BOJ_2749_Fibonacci_3
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000;
const int p = mod/10*15;
int fibo[p] = { 0,1 };
//피보나치 수를 K로 나눈 나저미는 항상 주기를 갖는다.
//주기의 길이가 P이면, N번째 피보나치 수를 M으로 나눈 나머지는
//N%P번째 피보나치 수를 M을 나눈 나머지와 같다.
// M = 10^k일때, 주기는 항상 15*10^(k-1)을 갖는다.
int main()
{
	long long n;
	cin >> n;
	for (int i = 2; i <p; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= mod;
	}
	cout << fibo[n%p];

	return 0;
}