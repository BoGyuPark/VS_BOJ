#include <iostream>
using namespace std;
char a[12][12];
int n, m;
int main(void){
	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
		
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) cout << a[i][j];
			cout << '\n';
		}
	}
}