//BOJ_PrimeNumber_2581
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int M, N;
	int sum = 0, min = 0;
	cin >> M >> N;
	
	//소수를 vector에 넣기(에라토스테네스의 체)
	int arr[10010] = { 0, };
	for (int i = 2; i <= 10000; i++)
		arr[i] = i;

	for (int i = 2; i*i <= 10000; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= 10000; j += i)
		{
			arr[j] = 0;
		}
	}

	vector<int> v;
	int vLen;
	int cnt = 0;
	for (int i = 0; i <= 10000; i++)
	{
		if (arr[i] != 0)
			v.push_back(arr[i]);
	}
	vLen = v.size();
	int flag = 0;
	for (int i = 0; i < vLen; i++)
	{
		if (v[i] >= M && v[i] <= N)
		{
			if (flag == 0) {
				min = v[i];
				flag = 1;
			}
			sum += v[i];
			cnt++;
		}
	}
	
	if (cnt == 0)
		cout << -1;
	else
		cout << sum <<"\n"<< min;

	return 0;
}