#include<iostream>
#include<vector>
#define MAX 4000001
using namespace std;
bool check[MAX];
int n, ans = 0, sum = 0;
vector<int> v;
void FindPrime() {
	for (long long i = 2; i < MAX; i++) {
		if (check[i] == false) {
			v.push_back(i);
			for (long long j = i * 2; j < MAX; j += i) {
				check[j] = true;
			}
		}
	}
}
int main() {
	cin >> n;
	FindPrime();
	sum = v[0];
	for (int r = 0, l = 0; r < v.size();) {
		if (sum < n) {
			r++;
			sum += v[r];
		}
		else if(sum > n) {
			sum -= v[l];
			l++;
		}
		else {
			ans++; r++;
			if (r== v.size())
				break;
			sum += v[r];
		}
	}
	cout << ans;
}