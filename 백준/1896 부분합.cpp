#include <iostream>
using namespace std;

int N, S;
int ar[100000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> ar[i];
	}

	int start = 0, end = 0;
	int min = N + 1;
	int sum = ar[0];
	while (true) { //start와 end의 위치를 조절하며 부분합들 검사
		if (sum >= S) {
			if (min > end - start + 1) {
				min = end - start + 1;
			}
			sum -= ar[start];
			start++;
		}
		else {
			end++;
			sum += ar[end];
		}
		if (end == N) {
			break;
		}
	}
	if (min == N + 1) {
		cout << 0;
	}
	else {
		cout << min;
	}

}
