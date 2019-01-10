//BOJ_11050_BinomialCoefficient_1
#include<bits/stdc++.h>
using namespace std;
int factorial(int x)
{
	int num = 1, temp = x;
	for (int i = 0; i < x; i++)
	{
		num *= temp--;
	}
	return num;
}
int main()
{
	int N, K; cin >> N >> K;
	int result;
	result = factorial(N) / (factorial(K)*(factorial(N - K)));
	cout << result;
	return 0;
}