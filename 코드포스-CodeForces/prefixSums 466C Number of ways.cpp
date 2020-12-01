#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[500001];
long long prefix[500001];

long long sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	prefix[0] = 0;
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		a[i] = temp;
		prefix[i] = prefix[i - 1] + temp;
	}
	
	long long dest = prefix[n];
	
	if (prefix[n] % 3 != 0 || n<3) {
		cout << 0;
		return 0;
	}
	dest = dest / 3;
	long long dest2 = dest * 2;
	long long cnt = 0;
	long long cnt2 = 0;
	//cout <<dest<<endl;
	for (int i = 1; i < n; i++) {
		if (prefix[i] == dest2)
			cnt += cnt2;
		if (prefix[i] == dest) {
			cnt2++;
		}
	}

	cout << cnt;


}