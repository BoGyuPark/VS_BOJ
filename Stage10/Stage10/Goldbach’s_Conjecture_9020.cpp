//Goldbach¡¯s_Conjecture_9020
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T, i = 0;
	cin >> T;
	int *Arr = new int[T + 3]();
	
	for (int i = 0; i < T; i++)
	{
		cin >> Arr[i];
	}

	int arr[10002] = { 0, };
	for (int i = 2; i < 10001; i++)
		arr[i] = i;

	for (int i = 2; i*i <= 10001; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= 10001; j += i)
			arr[j] = 0;
	}

	vector<int> v;
	for (int i = 0; i < 10001; i++)
	{
		if (arr[i] != 0)
			v.push_back(arr[i]);
	}
	int vLen = v.size();

	int temp, flag = 0;
	for (int i = 0; i < T; i++)
	{
		temp = Arr[i];
		flag = 0;
		for (int j = vLen - 1; j >= 0; j--)
		{
			if (flag == 0) {
				for (int z = j + 1; z < vLen; z++)
				{
					if (v[j] + v[z] == temp)
					{
						cout << v[j] << ' ' << v[z] << "\n";
						flag = 1;
						break;
					}
					else if (v[j] * 2 == temp)
					{
						cout << v[j] << ' ' << v[j] << "\n";
						flag = 1;
						break;
					}
				}
			}
			else
				break;
			
		}

	}	
	return 0;
}

//for (int j = 0; j < vLen; j++)
//{
//	for (int z = j + 1; z < vLen; z++)
//	{
//		if (v[j] + v[z] == temp)
//		{
//			cout << v[j] << ' ' << v[z] << "\n";
//		}
//		else if (v[j] * 2 == temp)
//		{
//			cout << v[j] << ' ' << v[j] << "\n";
//			break;
//		}
//	}
//}