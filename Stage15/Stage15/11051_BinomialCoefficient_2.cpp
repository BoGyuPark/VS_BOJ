//BOJ_11051_BinomialCoefficient_2
//Failed (����� memo)
#include<bits/stdc++.h>
using namespace std;
#define MAX 1003
//��� �Լ��̹Ƿ� ���������� �����.
int memo[MAX][MAX] = { 0, };

int NCR(int n, int r)
{
	//�̹� ���� ������ ��� �������� �ʴ´�.
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