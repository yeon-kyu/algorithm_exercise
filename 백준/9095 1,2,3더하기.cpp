#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	int cnt;
	cin >> cnt;
	for (int k = 0; k < cnt; k++) {
		cin >> n;
		int A[12] = { 0 };
		A[1] = 1;
		A[2] = 2;
		A[3] = 4;
		for (int i = 4; i < n + 1; i++) {
			for (int j = 0; j < 3; j++) {
				A[i] += A[i - 1 - j];
			}
		}
		cout << A[n] << endl;
	}
}