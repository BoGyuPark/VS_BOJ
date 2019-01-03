//Statics_2108
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, sum = 0;
	int maxVal, maxIndex, center, MaxFre, range, temp;
	int flag = 0;
	double avg;
	vector<int> v;
	int arr[8001] = { 0, };
	// index 0 = -4000, index 4000 = 0, index 8000 = 4000
	cin >> N;
	for(long long i=0; i<N; i++)
	{
		cin >> temp;
		v.push_back(temp);
		sum += temp;
		arr[4000 + temp]++;		
	}

	sort(v.begin(), v.end());
	
	avg = sum / (double)N;

	center = v[v.size() / 2];

	maxIndex = 0, maxVal = 0;
	for (int j = 0; j < 8001; j++)
	{
		if (arr[j] != 0) 
		{
			if (maxVal < arr[j])
			{
				maxVal = arr[j];
				maxIndex = j;
				flag = 0;
			}
			else if (maxVal == arr[j] && flag == 0)
			{
				flag = 1;
				maxVal = arr[j];
				maxIndex = j;
			}
		}
		
	}

	MaxFre = maxIndex - 4000;

	range = v[v.size()-1] - v[0];

	cout << fixed;
	cout.precision(0);
	cout << avg << "\n" << center << "\n" << MaxFre << "\n" << range;
	return 0;
}