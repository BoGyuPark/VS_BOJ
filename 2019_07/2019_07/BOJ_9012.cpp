/*BOJ 9012 °ýÈ£*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int n;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s, ans = "YES";
		cin >> s;
		stack<char> st;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '(') st.push('(');
			else {
				if (!st.empty()) st.pop();
				else ans = "NO";	
			}
		}
		if (!st.empty()) ans = "NO";
		cout << ans << '\n';
	}
}