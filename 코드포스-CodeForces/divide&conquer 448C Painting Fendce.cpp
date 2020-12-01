#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[5001];


int solve(int i, int j) {
	int ver_ans, hor_ans;

	ver_ans = j - i + 1;

	if (ver_ans < 1) {
		return 0;
	}

	int lowest_idx = i;
	for (int k = i + 1; k <= j; k++) {
		if (a[k] < a[lowest_idx]) {
			lowest_idx = k;
		}
	}

	hor_ans = a[lowest_idx];
	for (int k = i; k <= j; k++) {
		a[k] -= hor_ans;
	}

	int left = solve(i, lowest_idx - 1);
	int right = solve(lowest_idx + 1, j);

	hor_ans += left + right;

	return min(ver_ans, hor_ans);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << solve(1, n);

}
