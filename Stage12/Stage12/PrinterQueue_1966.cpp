//BOJ_PrinterQueue_1966
#include<bits/stdc++.h>
using namespace std;
typedef struct st
{
	int val;
	int pos;
};

int main()
{
	int T, M, N, len, max = 0, cnt; cin >> T;
	st tmp, want, f;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		deque<st> dq;
		for (int j = 0; j < N; j++)
		{
			cin >> tmp.val;
			tmp.pos = j;
			dq.push_back(tmp);
		}
		cnt = 0;
		want = dq[M];
		while (1)
		{
			f = dq.front();
			max = f.val;
			len = dq.size();
			//MAX구하기
			for (int x = 1; x < len; x++)
			{
				if (max < dq[x].val)
					max = dq[x].val;
			}

			if (f.val < max) {
				dq.pop_front();
				dq.push_back(f);
			}
			else {
				//중요도가 같을때 구분을 해야한다.
				if (max == want.val && want.pos == f.pos) {
					cout << cnt + 1 << "\n";
					break;
				}
				dq.pop_front();
				cnt++;
			}

		}
	}
	return 0;
}