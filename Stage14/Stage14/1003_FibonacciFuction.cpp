//BOJ_1003_FibonacciFuction
#include<bits/stdc++.h>
using namespace std;
typedef struct zerOne
{
	int zCnt;
	int oCnt;
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N; cin >> N;
		zerOne z1, z2, z3;
		z1.zCnt = 1; z1.oCnt = 0;
		z2.zCnt = 0; z2.oCnt = 1;
		if (N == 0)
		{
			cout << z1.zCnt << ' ' << z1.oCnt<<"\n";
		}
		else if (N == 1)
		{
			cout << z2.zCnt << ' ' << z2.oCnt << "\n";
		}
		else
		{
			for (int j = 2; j <= N; j++)
			{
				z3.zCnt = z1.zCnt + z2.zCnt;
				z3.oCnt = z1.oCnt + z2.oCnt;

				z1.zCnt = z2.zCnt; z1.oCnt = z2.oCnt;
				z2.zCnt = z3.zCnt; z2.oCnt = z3.oCnt;
			}
			cout << z3.zCnt << ' ' << z3.oCnt << "\n";
		}
		
	}

	return 0;
}