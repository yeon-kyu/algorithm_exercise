#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> v[501];
vector<int> dp[501];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {

		int temp;
		for (int j = 0; j <= i; j++) {
			cin >> temp;
			v[i].push_back(temp);
		}
	}

	dp[0].push_back(v[0][0]);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i].push_back(v[i][0] + dp[i-1][0]);
			}
			else if (j == i) {
				dp[i].push_back(v[i][i] + dp[i - 1][i - 1]);
			}
			else {
				dp[i].push_back(v[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]));
			}
			//cout << dp[i][j] << ' ';
		}
		//cout << endl;
	}

	int maxi = 0;
	for (int i = 0; i < N; i++) {
		maxi = max(dp[N - 1][i], maxi);
	}
	cout << maxi;
	
	return 0;
}