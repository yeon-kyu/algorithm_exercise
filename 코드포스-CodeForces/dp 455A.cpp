#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
long long a[100001] = { 0 };//숫자 i 의 갯수 저장
long long dp[100001]; //i번째 수 까지의 최대 포인트
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	long long temp;
	int max_num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		a[temp] += 1;
		if (temp > max_num) {
			max_num = temp;
		}
	}
	dp[0] = 0;
	dp[1] = a[1];
	long long left, right;
	
	for (int i = 1; i <= max_num; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);
	}
	cout << dp[max_num];
}
