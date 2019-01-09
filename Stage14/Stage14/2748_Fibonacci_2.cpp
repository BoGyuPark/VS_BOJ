//2748_Fibonacci_2
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	long long f1 = 0, f2 = 1;
	long long arr[100] = { 0, };
	long long sum = 0;
	for (int i = 2; i <= n; i++)
	{
		sum = f1 + f2;
		arr[i] = sum;
		f1 = f2;
		f2 = sum;
	}
	if (n == 0)
		cout << 0;
	else if (n == 1)
		cout << 1;
	else
		cout << sum;
	return 0;
}