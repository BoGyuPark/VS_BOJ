//BOJ_JosephPerthProblem0_11866
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N, M; cin >> N >> M;
	queue<int> q;
	for (int i = 0; i < N; i++)
		q.push(i + 1);
	int sol[1001] = { 0, };
	int temp, joFront, j = 0, len = 0;;
	while (1)
	{
		for (int i = 0; i < M-1; i++)
		{
			temp = q.front();
			q.pop(); q.push(temp);
		}
		temp = q.front();
		sol[j++] = temp;
		len++;
		q.pop();
		if (q.empty() == 1)
			break;
	}
	
	cout << "<";
	for (int i = 0; i < len; i++)
	{
		if (i != len - 1)
			cout << sol[i] << ", ";
		else
			cout << sol[i] << ">";
	}
	return 0;
}