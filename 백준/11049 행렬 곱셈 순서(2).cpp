#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int mat[501][2];
int dp[501][501];

int INF = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> mat[i][0] >> mat[i][1];
	}

	// dp[i][j] : i번째 행렬부터 j번째 행렬까지 계산했을 때 최솟값
	for (int i = 0; i < N; i++) {
		dp[i][i] = 0;
	}

	for (int j = 1; j < N; j++) {
		for (int i = 0; i + j< N; i++) {
			// 구하고자 하는 것 : dp[i][i + j]
			
			int mini = INF;
			for (int k = 0; k < j; k++) {
				int temp = dp[i][i + k] + dp[i + k + 1][i + j] + mat[i][0] * mat[i + k][1] * mat[i + j][1];
				mini = min(mini, temp);
			}
			dp[i][i + j] = mini;
		}
	}

	cout << dp[0][N - 1];
}