#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int cost[1001][3];
int dp[1001][3];

int INF = 1000001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = INF;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	// dp[i][j] : i번째 집까지 계산했을 때 j의 색을 선택했을 경우 최솟값
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = 0;
		}
	}

	// 빨간색
	dp[0][0] = cost[0][0];
	dp[0][1] = dp[0][2] = INF;
	for (int i = 1; i < N; i++) {
		int a = dp[i - 1][0];
		int b = dp[i - 1][1];
		int c = dp[i - 1][2];

		dp[i][0] = cost[i][0] + min(b, c);
		dp[i][1] = cost[i][1] + min(a, c);
		dp[i][2] = cost[i][2] + min(a, b);
	}
	answer = min(answer, min(dp[N - 1][1], dp[N - 1][2]));

	// 초록색
	dp[0][1] = cost[0][1];
	dp[0][0] = dp[0][2] = INF;
	for (int i = 1; i < N; i++) {
		int a = dp[i - 1][0];
		int b = dp[i - 1][1];
		int c = dp[i - 1][2];

		dp[i][0] = cost[i][0] + min(b, c);
		dp[i][1] = cost[i][1] + min(a, c);
		dp[i][2] = cost[i][2] + min(a, b);
	}
	answer = min(answer, min(dp[N - 1][0], dp[N - 1][2]));

	// 파란색
	dp[0][2] = cost[0][2];
	dp[0][0] = dp[0][1] = INF;
	for (int i = 1; i < N; i++) {
		int a = dp[i - 1][0];
		int b = dp[i - 1][1];
		int c = dp[i - 1][2];

		dp[i][0] = cost[i][0] + min(b, c);
		dp[i][1] = cost[i][1] + min(a, c);
		dp[i][2] = cost[i][2] + min(a, b);
	}
	answer = min(answer, min(dp[N - 1][0], dp[N - 1][1]));

	cout << answer;
}