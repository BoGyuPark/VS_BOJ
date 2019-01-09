//BOJ_Stack_sequence_1874
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N; cin >> N;
	stack<int> st;
	vector<char> v;
	int input, j = 1, top;
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (input < j)
		{
			top = st.top();
			if (top == input)
			{
				st.pop();
				v.push_back('-');
				continue;
			}
			else
			{
				flag = 1;
				continue;
			}
		}
		while (1)
		{
			if (j <= input)
			{
				st.push(j);
				v.push_back('+');
				//cout << "+\n";
				if (j == input)
				{
					st.pop();
					v.push_back('-');
					//cout << "-\n";
					j++;
					break;
				}
				j++;
			}
		
		}


	}

	if (flag == 0) {
		int len = v.size();
		for (int i = 0; i < len; i++)
			cout << v[i] << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	

	return 0;
}