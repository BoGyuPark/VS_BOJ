//BOJ_2004_NumOfZero_Combination
#include<bits/stdc++.h>
using namespace std;
long long count(int a, int n)
{
	long long ans = 0;
	for (long long i = a; i <= n; i *= a) {
		ans += n / i;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	long long NtwoCnt, NfiveCnt, MtwoCnt, MfiveCnt, KtwoCnt, KfiveCnt;
	NtwoCnt = count(2, n);
	NfiveCnt = count(5, n);
	MtwoCnt = count(2, m);
	MfiveCnt = count(5, m);
	KtwoCnt = count(2, n - m);
	KfiveCnt = count(5, n - m);
	long long result = min((NtwoCnt - MtwoCnt - KtwoCnt), (NfiveCnt - MfiveCnt - KfiveCnt));
	cout << result;
	return 0;
}