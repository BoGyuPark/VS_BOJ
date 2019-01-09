//BOJ_1021_RotatingQueue
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, M; cin >> N >> M;
	int num, len, temp, numPos, cnt = 0;
	deque<int> dq;
	for (int j = 0; j < N; j++)
		dq.push_back(j + 1);

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		//deque에서 num의 index를 찾아 판단하자.
		len = dq.size();
		for (int j = 0; j < len; j++)
		{
			if (dq[j] == num)
			{
				numPos = j;
				break;
			}
		}

		while (1) 
		{
			if (num == dq.front())
			{
				dq.pop_front();
				break;
			}

			len = dq.size();
			
			if (numPos <= len / 2)
			{
				temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				cnt++;
			}
			else
			{
				temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}