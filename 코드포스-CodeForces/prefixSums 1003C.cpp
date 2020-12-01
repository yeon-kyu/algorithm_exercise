#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	
	int n,k;
	int a[5001];
	long long sum[5001];
	cin >> n >> k;

	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	
	double max = 0;
	for (int i = k; i <= n; i++) {
		double temp;
		for (int j = 0; j <= n-i; j++) {
			temp = (sum[j + i] - sum[j]) / (double)i;
			if (temp > max) {
				max = temp;
			}
		}
	}
	cout.precision(15);
	cout << max;

}
