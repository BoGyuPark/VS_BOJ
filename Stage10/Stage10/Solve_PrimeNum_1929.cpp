//BOJ_Solve_PrimeNum_1929
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	//소수를 vector에 넣기(에라토스테네스의 체)
	int *arr = new int[N+3]();
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
	int vLen;
	for (int i = M; i <= N; i++)
	{
		if (arr[i] != 0)
			v.push_back(arr[i]);
	}
	delete[] arr;

	vLen = v.size();
	for (int i = 0; i < vLen; i++)
		cout << v[i] << "\n";

	return 0;
}