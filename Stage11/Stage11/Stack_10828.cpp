//Stack_10828
#include<bits/stdc++.h>
using namespace std;

typedef struct st
{
	int stackArr[10001] = { 0, };
	int top;
}stack;

int main()
{
	int N; cin >> N;
	string temp;
	int state;
	string arr[5] = { "push","pop","size","empty","top" };

	st s;
	s.top = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < 5; j++)
		{
			if (temp.compare(arr[j])==0) {
				state = j;
				break;
			}
		}
		int num;
		switch (state)
		{
			//push
			case 0:
				cin >> num;
				s.top++;
				s.stackArr[s.top] = num;
				break;
			//pop
			case 1:
				if (s.top == -1)
					cout << -1 << "\n";
				else
				{
					cout << s.stackArr[s.top] << "\n";
					s.top--;
				}
				break;
			
			//size
			case 2:
				cout << s.top + 1 << "\n";
				break;
			
			//empty
			case 3:
				if (s.top == -1)
					cout << 1 << "\n";
				else
					cout << 0 << "\n";
				break;
			
			//top
			case 4:
				if (s.top == -1)
					cout << -1 << "\n";
				else
				{
					cout << s.stackArr[s.top] << "\n";
				}
				break;
		}
			
	}

	return 0;
}