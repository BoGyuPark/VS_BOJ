//BOJ_SortWord_1181
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<string, int> > v;
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(make_pair(tmp, tmp.size()));
	}

	sort(v.begin(), v.end(), cmp);
	//중복 제거
	v.erase(unique(v.begin(), v.end()), v.end());

	int len = v.size();
	for (int i = 0; i < len; i++)
	{
		cout << v[i].first << "\n";
	}
	
	return 0;
}