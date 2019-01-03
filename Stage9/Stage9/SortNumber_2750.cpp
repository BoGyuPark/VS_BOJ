//BOJ_SortNumber_2750
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	int arr[1010] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	
	for (int j = 0; j < N; j++)
		cout << arr[j] << "\n";

	return 0;
}