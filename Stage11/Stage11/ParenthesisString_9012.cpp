//BOJ_ParenthesisString_9012
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin >> T;
	char arr[53] = { 0, };
	int len;
	for (int i = 0; i < T; i++)
	{
		cin >> arr;
		len = strlen(arr);
		stack<char> s;
		for (int j = 0; j < len; j++)
		{
			if (s.empty() != 1 && arr[j] == ')' && s.top()=='(')
				s.pop();
			else
				s.push(arr[j]);
		}
		cout << (s.empty() ? "YES" : "NO") << "\n";
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}