#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int n;
vector<int> v;
void printArr() {
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << '\n';
}

int main() {
	cin >> n;
	// N제한이 10만 이므로 N^2 = 100억...->약 100초
	// O(N)으로 풀어야함
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	printArr();

	v.erase(unique(v.begin(), v.end()), v.end());
	printArr();
	int left = 0, right = v.size() - 1;
	
	while (left != right) {
		if (abs(v[left]) == abs(v[right])) {
			if (ans < abs(v[left])) {
				ans = abs(v[left]);
				break;
			}
			right--;
		}
		else if (abs(v[left]) > abs(v[right])) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << ans;
}