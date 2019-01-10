//BOJ_2407_Combination
#include<bits/stdc++.h>
using namespace std;
typedef struct fs{
	string name;
	string kinds;
};
int main()
{
	int N; cin >> N;
	int arr[30] = { 0, };
	for (int a = 0; a < N; a++) {
		// num : 0 ~ 30
		int num, cnt = 1;
		cin >> num;
		fs fashion[30];
		for (int i = 0; i < num; i++) {
			string t1, t2;
			cin >> t1 >> t2;
			fashion[i].name = t1;	fashion[i].kinds = t2;
		}
	
	}
	cout << 2;

	return 0;
}