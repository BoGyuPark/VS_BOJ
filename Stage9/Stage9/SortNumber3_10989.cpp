//BOJ_SortNumber3_10989
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long N;
	int temp;
	int v[10001] = { 0, };

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (long long i = 0; i < N; i++)
	{
		cin >> temp;
		v[temp]++;
	}
	

	int i = 0;
	while (i < 10001)
	{
		while (v[i] > 0) {
			cout << i << "\n";
			v[i]--;
		}
		i++;
	}
		

	return 0;
}