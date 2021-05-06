#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int stair[301];
int dp[301];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
	}
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = stair[3] + max(stair[1], stair[2]);
	for (int i = 4; i <= N; i++) {
		dp[i] = stair[i] + max(dp[i - 2], dp[i - 3] + stair[i - 1]);
		
	}
	cout << dp[N];




	return 0;
}