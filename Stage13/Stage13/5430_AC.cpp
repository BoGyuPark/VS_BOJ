//BOJ_5430_AC
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T, n, num, flag = 0, rcnt, FBcheck; cin >> T;
	string p,arr;
	deque<int> dq;
	for (int i = 0; i < T; i++)
	{
		rcnt = 0; FBcheck = 0;
		cin >> p >> n >> arr;
		int plen = p.length();
		int arrLen = arr.length();
		for (int j = 0; j < arrLen; j++)
		{
			if (arr[j] == '[' || arr[j] == ',' || arr[j] == ']')
				arr[j] = ' ';
		}

		istringstream iss(arr);
		do
		{
			string temp;
			iss >> temp;
			num = atoi(temp.c_str());
			dq.push_back(num);
		} while (iss);
		dq.pop_back();

		for (int z = 0; z < plen; z++)
		{
			char fuc;
			fuc = p[z];
			if (fuc == 'R')
			{
				//reverse(dq.begin(), dq.end());
				//FBcheck 0이면 popfront, 1이면 popback
				FBcheck++;
				FBcheck %= 2;
				rcnt++;
			}
			else
			{
				if (dq.empty() == 1)
				{
					flag = 1;
					break;
				}
				else if(FBcheck==0)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (flag == 0)
		{
			if(rcnt%2!=0)
				reverse(dq.begin(), dq.end());
			int soLen;
			soLen = dq.size();
			cout << '[';
			for (int x = 0; x < soLen; x++)
			{
				cout << dq.front();
				dq.pop_front();
				if (x != soLen - 1)
					cout << ',';
			}
			cout << "]\n";
		}
		else
		{
			cout << "error" << "\n";
			flag = 0;
		}
	}
	return 0;
}