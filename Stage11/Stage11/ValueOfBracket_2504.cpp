//BOJ_ValueOfBracket_2504
//스스로 풀지 못한 문제
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char arr[33] = { 0, };
	cin >> arr;
	int len = strlen(arr);
	stack<char> s;
	int val = 0, temp = 1, no = 1;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == '(')
		{
			s.push(arr[i]);
			temp *= 2;
		}
		else if (arr[i] == '[')
		{
			s.push(arr[i]);
			temp *= 3;
		}
		else if (arr[i] == ')')
		{
			if (arr[i - 1] == '(')
				val += temp;
			if (s.empty() == 1)
			{
				no = 0;
				break;
			}
			if (s.top() == '(')
			{
				s.pop();
			}
			temp /= 2;
		}
		else
		{
			if (arr[i - 1] == '[')
				val += temp;
			if (s.empty() == 1)
			{
				no = 0;
				break;
			}
			if (s.top() == '[')
			{
				s.pop();
			}
			temp /= 3;
		}
	}
	if (no == 0 || !s.empty())
		cout << 0;
	else
		cout << val;
	
	return 0;
}