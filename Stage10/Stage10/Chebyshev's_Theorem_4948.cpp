//BOJ_Chebyshev's_Theorem_4948
#include<bits/stdc++.h>
#define N 246912
using namespace std;
int main()
{
	int *Arr = new int[123457+3]();
	int i = 0, totalCnt = 0;
	while (1)
	{
		cin >> Arr[i++];
		totalCnt++;
		if (Arr[i - 1] == 0)
			break;
	}

	//소수를 vector에 넣기(에라토스테네스의 체)
	int *arr = new int[N + 3]();
	for (int i = 0; i <= N; i++)
		arr[i] = i;
	arr[1] = 0;
	for (int i = 2; i*i <= N; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= N; j += i)
		{
			arr[j] = 0;
		}
	}
	vector<int> v;
	for (int i = 0; i <= N; i++)
	{
		if (arr[i] != 0)
			v.push_back(arr[i]);
	}
	int vLen = v.size();
	int tmp, cnt = 0;
	for (int i = 0; i < totalCnt-1; i++)
	{
		tmp = Arr[i];
		for (int j = 0; j < vLen; j++)
		{
			if (v[j] > tmp && v[j] <= tmp * 2)
				cnt++;
		}
		cout << cnt << "\n";
		cnt = 0;
	}
	delete[] Arr;
	delete[] arr;
	return 0;
}