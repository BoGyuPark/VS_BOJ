/*BOJ 1874 스택 수열*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int n, num;
stack<int> s;
vector<char> v;
vector<int> numList, arr;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int value = 1;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
		while (value<=num) {
			s.push(value);
			value++;
			v.push_back('+');
			//cout << '+' << '\n';
		}

		if (!s.empty()) {
			if (s.top() == num) {
				numList.push_back(num);
				s.pop();
				v.push_back('-');
				//cout << '-' << '\n';
			}
		}
	}
	if (numList.size() != n) cout << "NO";
	else {
		for(int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
	}
}