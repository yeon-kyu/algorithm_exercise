#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int T;
int N;
int dp[41][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 41; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	dp[0][0] = 1;
	dp[0][1] = 0;

	dp[1][0] = 0;
	dp[1][1] = 1;

	dp[2][0] = 1;
	dp[2][1] = 1;

	for (int i = 3; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		//cout << dp[i][0] << ' ' << dp[i][1] << endl;
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << dp[N][0] << ' ' << dp[N][1] << endl;
	}
	
}