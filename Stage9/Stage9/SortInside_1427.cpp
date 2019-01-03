//SortInside_1427
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	char arr[11] = { 0, };
	cin >> arr;
	int len = strlen(arr);
	vector<int> v;
	int temp;
	for (int i = 0; i < len; i++)
	{
		temp = arr[i] - '0';
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int j = 0; j <len; j++)
		cout << v[j];

	return 0;
}