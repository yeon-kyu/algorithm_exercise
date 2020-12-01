#include <iostream>
#include <algorithm>
using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long dp[91];
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[n];

}
