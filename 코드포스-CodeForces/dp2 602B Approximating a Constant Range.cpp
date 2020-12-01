#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[100001];
int dp[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int left = 1;
	int max = a[1] + 1; 
	int min = a[1];
	a[0] = -1; //left pointer가 넘어오지못하는 경계선
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (a[i] == max || a[i] == min) {
			dp[i] = dp[i - 1] + 1;
		}
		else if (a[i] > max) {
			max++;
			min++;
			left = i;
			while (1) {
				if (a[left] == min || a[left] == max) {
					left--;
				}
				else
					break;
			}
			dp[i] = i - left;
		}
		else if (a[i] < min) {
			max--;
			min--;
			left = i-1;
			while (1) {
				if (a[left] == min || a[left] == max)
					left--;
				else
					break;
			}
			dp[i] = i - left;
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	
	cout<<ans;
}