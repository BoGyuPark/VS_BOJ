#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, a[51][51], temp[13], dist[51][51];
vector<pair<int, int>> v, h;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) v.push_back({ i,j });
			else if (a[i][j] == 1) h.push_back({ i,j });
		}
	}
	//������ ���� �۾�
	for (int i = 0; i < m; i++) temp[i] = 1;
	int Vsize = v.size();
	vector<int> ans;
	do
	{
		int dist[51][51] = { 0, };
		vector<pair<int, int>> t;
		//ġŲ���� ���Ѵ�.
		for (int i = 0; i < Vsize; i++) {
			if (temp[i] == 1)	t.push_back({ v[i].first,v[i].second });
		}
		
		int cmp, distance = 0;
		for (int j = 0; j < h.size(); j++) {
			int x = h[j].first, y = h[j].second;
			//������ ���� ġŲ������ �Ÿ��� ��
			for (int z = 0; z < t.size(); z++) {
				int dif = abs(x - t[z].first) + abs(y - t[z].second);
				if (dist[x][y] == 0 || dist[x][y] > dif)
					dist[x][y] = dif;
			}
		}
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) distance += dist[i][j];

		ans.push_back(distance);	
	} while (prev_permutation(temp, temp + Vsize));
	sort(ans.begin(), ans.end());
	cout << ans[0];
}