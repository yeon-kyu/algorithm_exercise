#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int a[100001];
long long sum[100001];

int main() {
	
	int t, n;
	cin >> t;
	
	sum[0] = 0;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> v; //음수가 나타난 위치의 인덱스를 저장함
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
			sum[j] = sum[j - 1] + a[j];
			if (a[j] <= 0) {
				v.push_back(j);
			}
			if (sum[j] <= 0) {
				flag = false;
			}
		}
		if (flag == false) {
			cout << "NO\n";
			continue;
		}
		long long tot = sum[n];
		
		int size = v.size();
		for (int j = size; j > 0; j--) {
			int z = v[j - 1];
			
			if (tot - sum[z - 1] <= 0) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}
	
}
