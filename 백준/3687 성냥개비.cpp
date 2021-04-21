#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, N;

long long mins[102];

void getMin(int n) {
	cout << mins[n] << ' ';
}
void getMax(int n) {
	if (n % 2 == 0) {
		int a = n / 2 - 1;
		cout << 1;
		for (int i = 0; i < a; i++) {
			cout << 1;
		}
		cout << '\n';
	}
	else {
		int a = n / 2 - 1;
		cout << 7;
		for (int i = 0; i < a; i++) {
			cout << 1;
		}
		cout << '\n';
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	mins[2] = 1;
	mins[3] = 7;
	mins[4] = 4;
	mins[5] = 2;
	mins[6] = 6;
	mins[7] = 8;

	mins[8] = 10;
	mins[9] = 18;
	mins[10] = 22;
	mins[11] = 20;
	mins[12] = 28;
	mins[13] = 68;
	mins[14] = 88;

	mins[15] = 108;
	mins[16] = 188;
	mins[17] = 200;

	for (int i = 18; i < 101; i++) {
		mins[i] = mins[i - 7] * 10 + 8;
	}

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		getMin(N);
		getMax(N);
	}

	return 0;
}