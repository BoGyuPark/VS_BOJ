//BOJ_Queue_10845
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string Sarr[6] = { "push", "pop", "size", "empty","front","back" };
	int N; cin >> N;
	string temp;
	int state, X;
	int queueArr[10010] = { 0, };
	int f = 0, b = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < 6; j++)
		{
			if (temp.compare(Sarr[j]) == 0) {
				state = j;
				break;
			}
		}

		switch (state)
		{
			//push
			case 0:
				cin >> X;
				queueArr[b++] = X;
				break;
			
			//pop
			case 1:
				if (f == b)
					cout << -1 << "\n";
				else {
					cout << queueArr[f] << "\n";
					f++;
				}
				break;
			
			//size
			case 2:
				cout << b - f << "\n";
				break;
			
			//empty
			case 3:
				cout << (f == b ? 1 : 0) << "\n";
				break;
			
			//front
			case 4:
				if (f == b)
					cout << -1 << "\n";
				else
					cout << queueArr[f] << "\n";
				break;
			
			//back
			case 5:
				if (f == b)
					cout << -1 << "\n";
				else
					cout << queueArr[b-1] << "\n";
				break;
		}
	}
	return 0;
}