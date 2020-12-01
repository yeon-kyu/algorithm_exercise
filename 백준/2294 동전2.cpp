#include <iostream>
#include <algorithm>
using namespace std;

int n;
int k;
int val[101];
int dp[101][10001];

int main() {

	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	scanf("%d %d", &n, &k);
	
	for (int i = 0; i <= k; i++) {
		dp[0][i] = 999999;
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}

	int w; //현재 바라보는 동전의 종류(가치)
	for (int i = 1; i <= n; i++) {
		w = val[i];
		int coin_cnt = 0;//사용한 동전 수
		int temp;
		for (int j = 1; j <= k; j++) {
			if (j < w) { //위에것 그대로
				dp[i][j] = dp[i - 1][j];
			}
			else { //위에것과 왼쪽-x 비교
				temp = dp[i][j - w] + 1;
				dp[i][j] = min(temp, dp[i - 1][j]);
			}
		}

	}

	if (dp[n][k] == 999999) {
		printf("%d", -1);
	}
	else {
		printf("%d", dp[n][k]);
	}
	
}
