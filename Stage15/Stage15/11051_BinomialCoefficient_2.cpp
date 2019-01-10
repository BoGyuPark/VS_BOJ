//BOJ_11051_BinomialCoefficient_2
//Failed (재귀적 memo)
#include<bits/stdc++.h>
using namespace std;
#define MAX 1003
//재귀 함수이므로 전역변수로 만든다.
int memo[MAX][MAX] = { 0, };

int NCR(int n, int r)
{
	//이미 계산된 결과라면 재귀 수행하지 않는다.
	if (memo[n][r] > 0)		return memo[n][r];
	if (n == r || r == 0)	return memo[n][r] = 1;
	return memo[n][r] = (NCR(n - 1, r - 1) + NCR(n - 1, r)) % 10007;
}

int main()
{
	int N, K; cin >> N >> K;
	int result = NCR(N, K);
	cout << result;
	return 0;
}