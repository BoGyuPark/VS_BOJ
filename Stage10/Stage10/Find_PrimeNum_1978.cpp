//BOJ_Find_PrimeNum_1978
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;

	int arr[101] = { 0, };
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int numArr[1001] = { 0, };

	for (int j = 2; j < 1001; j++)
		numArr[j] = j;

	int a;
	for (a = 2; a*a <= 1000; a++)
	{
		if (numArr[a] == 0)
			continue;
		for (int b = a + a; b <= 1000; b += a)
			numArr[b] = 0;
	}

	vector<int> v;
	for (int i = 0; i < 1001; i++)
	{
		if (numArr[i] != 0)
			v.push_back(numArr[i]);
	}

	int vLen = v.size();
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < vLen; j++)
		{
			if (arr[i]==v[j])
			{
				cnt++;
				break;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}