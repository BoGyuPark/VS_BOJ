//BOJ_SortNumber2_2751
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	long long N, temp;
	vector<long long> v;
	cin >> N;
	for (long long i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	for (long long j = 0; j < N; j++)
		cout << v[j] << "\n";

	return 0;
}