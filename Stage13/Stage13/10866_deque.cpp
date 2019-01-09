//BOJ_10866_deque
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N; cin >> N;
	deque<int> dq;
	string arr[8] = { "push_front","push_back","pop_front","pop_back","size","empty","front","back" };
	int state;
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < 8; j++)
		{
			if (temp.compare(arr[j]) == 0)
				state = j;
		}
		int X;
		switch (state)
		{
		case 0:
			cin >> X;
			dq.push_front(X);
			break;
		case 1:
			cin >> X;
			dq.push_back(X);
			break;
		case 2:
			if (dq.empty() == 1)
				cout << -1 << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			break;
		case 3:
			if (dq.empty() == 1)
				cout << -1 << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			break;
		case 4:
			cout << dq.size() << "\n";
			break;
		case 5:
			cout << (dq.empty() ? 1 : 0) << "\n";
			break;
		case 6:
			if (dq.empty() == 1)
				cout << -1 << "\n";
			else {
				cout << dq.front() << "\n";
			}
			break;
		case 7:
			if (dq.empty() == 1)
				cout << -1 << "\n";
			else {
				cout << dq.back() << "\n";
			}
			break;
		
		}

	}


	return 0;
}